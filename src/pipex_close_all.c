/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_close_all.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavier <afavier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:52:52 by afavier           #+#    #+#             */
/*   Updated: 2024/03/05 14:19:38 by afavier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"
#include <sys/wait.h>

void	error_close_free(t_array *files, char *path, char **cmd)
{
	if (files->fd[0] > 0)
		close(files->fd[0]);
	if (files->fd[1] > 0)
		close(files->fd[1]);
	close(files->fd_cmd[0]);
	close(files->fd_cmd[1]);
	free(path);
	free_tab(cmd);
	free_array(files);
	exit(EXIT_FAILURE);
}

void	close_files(t_array *files, char *path, char **cmd)
{
	if (files->fd[0] > 0)
		if (close(files->fd[0]) == -1)
			close_files_fd_error(files, path, cmd);
	if (files->fd[1] > 0)
		if (close(files->fd[1]) == -1)
			close_files_fd_error(files, path, cmd);
	if (close(files->fd_cmd[0]) == -1)
		close_files_fd_error(files, path, cmd);
}

void	error_cmd_one(t_array *files, char *path, char **cmd)
{
	ft_dprintf(2, "pipex: Error malloc\n");
	if (files->fd[0] > 0)
		close(files->fd[0]);
	if (files->fd[1] > 0)
		close(files->fd[1]);
	close(files->fd_cmd[0]);
	close(files->fd_cmd[1]);
	free(path);
	free_tab(cmd);
	free_array(files);
	exit(EXIT_FAILURE);
}

void	error_cmd_two(t_array *files, char *path, char **cmd)
{
	ft_dprintf(2, "pipex: Error malloc\n");
	while (wait(NULL) > 0)
		;
	if (files->fd[0] > 0)
		close(files->fd[0]);
	if (files->fd[1] > 0)
		close(files->fd[1]);
	close(files->fd_cmd[0]);
	close(files->fd_cmd[1]);
	free(path);
	free_tab(cmd);
	free_array(files);
	exit(EXIT_FAILURE);
}

void	close_files_fd_error(t_array *files, char *path, char **cmd)
{
	ft_dprintf(2, "pipex: Error close file\n");
	free(path);
	free_tab(cmd);
	free_array(files);
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	exit(127);
}
