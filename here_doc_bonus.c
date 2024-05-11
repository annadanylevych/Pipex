/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adanylev <adanylev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 15:40:12 by adanylev          #+#    #+#             */
/*   Updated: 2024/05/11 17:59:17 by adanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	heredoc(t_pipex *pipex)
{
	int			fd;
	char		*line;

	(void)pipex;
	fd = -1;
	fd = open("/tmp/hd", O_CREAT | O_WRONLY | O_TRUNC, 0666);
	while (1)
	{
 		write(1, "> ", 2);
		line = get_next_line(0);
		if (line == NULL)
			break;
		if (!ft_strncmp(line, pipex->limiter, ft_strlen(line) - 1))
			break;
		ft_putstr_fd(line, fd);
		free(line);
	}
	close (fd);
	fd = open("/tmp/hd", O_RDONLY);
	return (fd);
}

char	**get_coms_here(char **argv, int argc)
{
	char **coms;
	int i;

	i = 0;
	coms = malloc(sizeof(char *) * (argc - 4));
	while (i < argc - 4)
	{
		coms[i] = argv[i + 3];
		i++;
	}
	coms[i] = NULL;
	return(coms);
}