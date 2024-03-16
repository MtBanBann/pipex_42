/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavier <afavier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:27:24 by afavier           #+#    #+#             */
/*   Updated: 2024/03/05 14:17:48 by afavier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/inc/ft_dprintf.h"
# include "../libft/inc/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

typedef struct s_array
{
	int	fd[2];
	int	fd_cmd[2];
	int	i;
}		t_array;

t_array	*initialize_array(char **argv);
char	*find_path(char **env);
void	cmd_one(char *path, char **cmd, char **env, t_array *files);
char	*find_exec_path(char **argv, char **env, int i, t_array *files);
void	cmd_two(char *path, char **cmd, char **env, t_array *files);
void	free_tab(char **tab);
char	*exec_is_good(char **cmd_path, char **cmd, int i, t_array *files);
int		open_fd_cmd_one(char **argv);
int		open_fd_cmd_two(char **argv);
void	number_args(int argc);
void	error_close_free(t_array *files, char *path, char **cmd);
void	close_files(t_array *files, char *path, char **cmd);
void	path_cmd_one(char **argv, char **env, t_array *files);
void	path_cmd_two(char **argv, char **env, t_array *files);
void	close_cmd_one_parent(t_array *files);
void	print_error_fd_cmd(t_array *files);
void	close_cmd_two_parent(t_array *files);
char	*access_path(char **cmd, char **env, t_array *files);
void	free_array(t_array *files);
void	free_cmd_one(char *path, char **cmd, t_array *files);
void	error_cmd_two(t_array *files, char *path, char **cmd);
void	error_cmd_one(t_array *files, char *path, char **cmd);
void	error_cmd_malloc(t_array *files);
void	error_access_path_malloc(t_array *files, char **cmd);
void	error_path_malloc(t_array *files, char **cmd_path, char **cmd);
void	error_temp_malloc(t_array *files, char **cmd_path, char **cmd,
			char *path_ex);
int		check_first_cmd(char **argv, int i);
void	error_path_cmd_one(t_array *files, char **argv);
void	error_exec_path_strdup(t_array *files, char **cmd);
void	close_files_cmd_1(t_array *files, char **argv);
void	close_files_fd_error(t_array *files, char *path, char **cmd);

#endif