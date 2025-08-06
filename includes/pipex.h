/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 pipex.h											:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: acarranz <marvin@42.fr>					+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2025/01/09 09:57:33 by acarranz		   #+#	  #+#			  */
/*	 Updated: 2025/01/09 09:57:33 by acarranz		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <sys/wait.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft.h"
# include "ft_printf.h"

typedef struct s_pipe
{
	char	**env;
	char	*args1;
	char	*args2;
	char	**com1;
	char	**com2;
	char	*path_1;
	char	*path_2;
	char	*file_int;
	char	*file_out;
	int		fd_int;
	int		fd[2];
	int		fd_out;
}			t_pipe;

void	ft_pipex(t_pipe *pipex);
void	free_pipex(t_pipe *pipex);
void	free_split(char **split);
char	*find_comand(const char **env, char *comand);
char	*check_command_access(char **all_path, char *comand);

#endif
