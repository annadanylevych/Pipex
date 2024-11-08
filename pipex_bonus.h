/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adanylev <adanylev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:51:19 by adanylev          #+#    #+#             */
/*   Updated: 2024/05/11 17:43:48 by adanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "lib/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_pipex
{
	int		infile;
	int		outfile;
	int		fd[2];
	pid_t	*son;
	char	**paths;
	char	**cmds;
	int		num_com;
	char	*limiter;
}			t_pipex;

char		**get_coms_here(char **argv, int argc);
int			heredoc(t_pipex *pipex);
int			count_coms(char **comds);
void		waiting(int *status, int argc);
void		pip(t_pipex *pipex, char **envp, int argc);
void		parse_path(char **envp, t_pipex *pipex);
char		*find_command(t_pipex *pipex, char **command);
void		son_process(t_pipex *pipex, char *cmds, char **envp);
void		daughter_process(t_pipex *pipex, char **argv, char **envp);
char		*find_command2(t_pipex *pipex);
int			error(int ernu, char *msg, int excode);
int			error_other(char *txt);
void		free_parent(t_pipex *pipex);
void		free_son(t_pipex *pipex);
char 		**cool_split(char *str, char c);
int			is_space(char c);
int			is_quote(char letter);
void		*my_malloc(size_t bytes);
#endif