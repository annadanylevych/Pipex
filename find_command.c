/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adanylev <adanylev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 22:29:09 by adanylev          #+#    #+#             */
/*   Updated: 2023/12/14 13:18:03 by adanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_command(t_pipex *pipex)
{
	int		i;
	char	*tmp;
	char	*tmp2;

	i = 0;
	while (pipex->paths[i] != NULL)
	{
		tmp = ft_strjoin(pipex->paths[i], "/");
		tmp2 = ft_strjoin(tmp, pipex->cmd1[0]);
		if (access(tmp2, X_OK) == 0)
		{
			free(tmp);
			return (tmp2);
		}
		free(tmp);
		free(tmp2);
		i++;
	}
	error(2, pipex->cmd1[0], 127);
	return (0);
}

char	*find_command2(t_pipex *pipex)
{
	int		i;
	char	*tmp;
	char	*tmp2;

	i = 0;
	while (pipex->paths[i] != NULL)
	{
		tmp = ft_strjoin(pipex->paths[i], "/");
		tmp2 = ft_strjoin(tmp, pipex->cmd2[0]);
		free(tmp);
		if (access(tmp2, X_OK) == 0)
			return (tmp2);
		free(tmp2);
		++i;
	}
	error(2, pipex->cmd2[0], 127);
	return (0);
}
