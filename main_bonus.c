/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adanylev <adanylev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:50:45 by adanylev          #+#    #+#             */
/*   Updated: 2024/05/11 18:06:30 by adanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	pip(t_pipex *pipex, char **envp, int argc)
{
	int	status;
	int	i;

	(void)argc;
	status = 0;
	i = 0;
	if (pipex->limiter)
		dup2(heredoc(pipex), STDIN_FILENO);
	else
		dup2(pipex->infile, STDIN_FILENO);
	pipex->son = malloc(sizeof(pid_t) * (pipex->num_com));
	while (i < pipex->num_com)
	{
		if (pipe(pipex->fd) == -1)
			error_other("Pipe issue\n");
		pipex->son[i] = fork();
		if (pipex->son[i] < 0)
			error_other("Fork issue\n");
		else if (pipex->son[i] == 0)
		{
            if (i < pipex->num_com - 1)
			{
                close(pipex->fd[0]);
                dup2(pipex->fd[1], STDOUT_FILENO);
                close(pipex->fd[1]);
            }
			else
                dup2(pipex->outfile, STDOUT_FILENO);
            son_process(pipex, pipex->cmds[i], envp);
        }
		close(pipex->fd[1]);
        if (i < pipex->num_com)
		{
            dup2(pipex->fd[0], STDIN_FILENO);
            close(pipex->fd[0]);
        }
        i++;
	}
	close(pipex->infile);
    close(pipex->outfile);
    waiting(&status, pipex->num_com);
    if (WIFEXITED(status))
        exit(WEXITSTATUS(status));
	free_parent(pipex);
	exit(1);
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

char	**get_coms(char **argv, int argc)
{
	char **coms;
	int i;

	i = 0;
	coms = malloc(sizeof(char *) * (argc - 2));
	while (i < argc - 3)
	{
		coms[i] = argv[i + 2];
		i++;
	}
	coms[i] = NULL;
	return(coms);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	
	if (argc < 5)
	{
		perror("Input error\n");
		exit(1);
	}
	if (ft_strncmp(argv[1], "here_doc", 8))
	{
		if (access(argv[1], F_OK) == -1)
			error(3, argv[1], 127);
		if (access(argv[1], R_OK) == -1)
			error(1, argv[1], 126);
		pipex.infile = open(argv[1], O_RDONLY);
		pipex.outfile = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
		pipex.cmds = get_coms(argv, argc);
		pipex.num_com = count_coms(pipex.cmds);
		pipex.limiter = NULL;
	}
	else 
	{
		pipex.outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
		pipex.cmds = get_coms_here(argv, argc);
		pipex.num_com = count_coms(pipex.cmds) - 1;
		pipex.limiter = argv[2];
		pipex.infile = 0;
	}
	parse_path(envp, &pipex);
	pip(&pipex, envp, argc);
	free_parent(&pipex);
	return(0);
}

