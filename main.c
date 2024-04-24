/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adanylev <adanylev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:01:39 by adanylev          #+#    #+#             */
/*   Updated: 2024/04/24 14:27:21 by adanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pip(t_pipex *pipex, char **argv, char **envp)
{
	int	status;

	pipe(pipex->fd);
	pipex->son = fork();
	if (pipex->son < 0)
		error_other("Fork issue\n");
	else if (pipex->son == 0)
		son_process(pipex, argv, envp);
	pipex->daughter = fork();
	if (pipex->daughter < 0)
		error_other("Fork issue\n");
	else if (pipex->daughter == 0)
		daughter_process(pipex, argv, envp);
	free_parent(pipex);
	waitpid(pipex->son, 0, 0);
	waitpid(pipex->daughter, &status, 0);
	if (WIFEXITED(status))
		exit(WEXITSTATUS(status));
}

void	parse_path(char **envp, t_pipex *pipex)
{
	int		b;
	char	*tmp;

	b = 0;
	while (*envp)
	{
		if (ft_strncmp("PATH=", *envp, 5) == 0)
		{
			b = 1;
			tmp = ft_substr(*envp, 5, ft_strlen(*envp) - 5);
			pipex->paths = ft_split(tmp, ':');
			free(tmp);
			if (!pipex->paths)
				error_other("Pipex: Memory issues\n");
		}
		envp++;
	}
	if (b == 0)
		error_other("PATH not found\n");
}



int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	char **cool;
	int	i;
	
	i = 0;
	cool = cool_split("hello'my'name holaaaa", ' ');
	while (cool[i])
	{
		printf("%s\n", cool[i]);
		i++;
	}
	return (1);
	if (argc != 5)
		perror("Input error\n");
	pipex.infile = open(argv[1], O_RDONLY);
	pipex.outfile = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	pipex.cmd1 = ft_split(argv[2], ' ');
	pipex.cmd2 = ft_split(argv[3], ' ');
	parse_path(envp, &pipex);
	pip(&pipex, argv, envp);
	free_parent(&pipex);
	exit(1);
}
