/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annadanylevych <annadanylevych@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 11:34:58 by annadanylev       #+#    #+#             */
/*   Updated: 2024/04/28 11:40:29 by annadanylev      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	error(int ernu, char *msg, int excode)
{
	if (ernu == 1)
	{
		write(2, "bash: ", 6);
		write(2, msg, ft_strlen(msg));
		write(2, ": Permission denied\n", 21);
	}
	else if (ernu == 2)
	{
		write(2, "bash: ", 6);
		write(2, msg, ft_strlen(msg));
		write(2, ": command not found\n", 21);
	}
	else if (ernu == 3)
	{
		write(2, "bash: ", 6);
		write(2, msg, ft_strlen(msg));
		write(2, ": No such file or directory\n", 29);
	}
	exit(excode);
}

int	error_other(char *txt)
{
	write(2, txt, ft_strlen(txt));
	exit(1);
}

void	free_parent(t_pipex *pipex)
{
	int	i;

	i = 0;
	close(pipex->fd[0]);
	close(pipex->fd[1]);
	close(pipex->infile);
	close(pipex->outfile);
	while (pipex->paths[i])
	{
		free(pipex->paths[i]);
		i++;
	}
	free(pipex->paths);
}