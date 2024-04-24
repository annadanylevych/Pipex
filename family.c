/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   family.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adanylev <adanylev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 18:14:02 by adanylev          #+#    #+#             */
/*   Updated: 2023/12/06 13:20:18 by adanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	son_process(t_pipex *pipex, char **argv, char **envp)
{
	char	*cmd_path;

	close(pipex->fd[0]);
	if (access(argv[1], F_OK) == -1)
		error(3, argv[1], 127);
	if (access(argv[1], R_OK) == -1)
		error(1, argv[1], 126);
	dup2(pipex->infile, STDIN_FILENO);
	dup2(pipex->fd[1], STDOUT_FILENO);
	close(pipex->infile);
	if (access(pipex->cmd1[0], R_OK) >= 0)
		cmd_path = pipex->cmd1[0];
	else
		cmd_path = find_command(pipex);
	if (access(cmd_path, X_OK) >= 0)
		execve(cmd_path, pipex->cmd1, envp);
	error(1, *pipex->cmd1, 126);
}

void	daughter_process(t_pipex *pipex, char **argv, char **envp)
{
	char	*cmd_path;

	close(pipex->fd[1]);
	dup2(pipex->fd[0], STDIN_FILENO);
	dup2(pipex->outfile, STDOUT_FILENO);
	close(pipex->outfile);
	close(pipex->fd[0]);
	if (access(argv[4], R_OK | W_OK) == -1)
		error(1, argv[4], 1);
	if (access(pipex->cmd2[0], R_OK) >= 0)
		cmd_path = pipex->cmd2[0];
	else
		cmd_path = find_command2(pipex);
	if (access(cmd_path, X_OK) >= 0)
		execve(cmd_path, pipex->cmd2, envp);
	error(1, *pipex->cmd2, 126);
}
