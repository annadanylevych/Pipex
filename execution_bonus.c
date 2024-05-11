/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adanylev <adanylev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 20:44:23 by annadanylev       #+#    #+#             */
/*   Updated: 2024/05/11 16:12:40 by adanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*find_command(t_pipex *pipex, char **command)
{
	int		i;
	char	*tmp;
	char	*tmp2;

	i = 0;
	while (pipex->paths[i] != NULL)
	{
		tmp = ft_strjoin(pipex->paths[i], "/");
		tmp2 = ft_strjoin(tmp, command[0]);
		if (access(tmp2, X_OK) == 0)
		{
			free(tmp);
			return (tmp2);
		}
		free(tmp);
		free(tmp2);
		i++;
	}
	error(2, command[0], 127);
	return (0);
}

void	son_process(t_pipex *pipex, char *cmds, char **envp)
{
	char	*cmd_path;
    char    **command;

    command = ft_split(cmds, ' ');
	if (access(command[0], X_OK) >= 0)
		cmd_path = command[0];
	else
		cmd_path = find_command(pipex, command);
	if (access(cmd_path, X_OK) >= 0)
		execve(cmd_path, command, envp);
	error(1, *command, 126);
}

void	waiting(int *status, int argc)
{
	int	i;

	i = 0;
	while (i < argc - 3)
	{
		waitpid(-1, status, 0);
		i++;
	}
}