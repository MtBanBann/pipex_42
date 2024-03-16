/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_error_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavier <afavier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 21:44:21 by afavier           #+#    #+#             */
/*   Updated: 2024/03/05 11:12:30 by afavier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"
#include <sys/wait.h>

void	error_cmd_malloc(t_array *files)
{
	ft_dprintf(2, "pipex: Error malloc cmd\n");
	if (files->i == 1)
	{
		while (wait(NULL) > 0)
			;
	}
	if (files->fd[0] > 0)
		close(files->fd[0]);
	if (files->fd[1] > 0)
		close(files->fd[1]);
	close(files->fd_cmd[0]);
	close(files->fd_cmd[1]);
	free_array(files);
	exit(EXIT_FAILURE);
}

void	error_access_path_malloc(t_array *files, char **cmd)
{
	ft_dprintf(2, "pipex: Error malloc cmd_path\n");
	if (files->i == 1)
	{
		while (wait(NULL) > 0)
			;
	}
	if (files->fd[0] > 0)
		close(files->fd[0]);
	if (files->fd[1] > 0)
		close(files->fd[1]);
	close(files->fd_cmd[0]);
	close(files->fd_cmd[1]);
	free_array(files);
	free_tab(cmd);
	exit(EXIT_FAILURE);
}

void	error_path_malloc(t_array *files, char **cmd_path, char **cmd)
{
	ft_dprintf(2, "pipex: Error malloc path_ex\n");
	if (files->i == 1)
	{
		while (wait(NULL) > 0)
			;
	}
	if (files->fd[0] > 0)
		close(files->fd[0]);
	if (files->fd[1] > 0)
		close(files->fd[1]);
	close(files->fd_cmd[0]);
	close(files->fd_cmd[1]);
	free_tab(cmd_path);
	free_tab(cmd);
	free_array(files);
	exit(EXIT_FAILURE);
}

void	error_temp_malloc(t_array *files, char **cmd_path, char **cmd,
		char *path_ex)
{
	ft_dprintf(2, "pipex: Error malloc temp\n");
	if (files->i == 1)
	{
		while (wait(NULL) > 0)
			;
	}
	if (files->fd[0] > 0)
		close(files->fd[0]);
	if (files->fd[1] > 0)
		close(files->fd[1]);
	close(files->fd_cmd[0]);
	close(files->fd_cmd[1]);
	free_tab(cmd_path);
	free_tab(cmd);
	free(path_ex);
	free_array(files);
	exit(EXIT_FAILURE);
}

void	error_exec_path_strdup(t_array *files, char **cmd)
{
	ft_dprintf(2, "pipex: Error malloc path\n");
	if (files->i == 1)
	{
		while (wait(NULL) > 0)
			;
	}
	if (files->fd[0] > 0)
		close(files->fd[0]);
	if (files->fd[1] > 0)
		close(files->fd[1]);
	close(files->fd_cmd[0]);
	close(files->fd_cmd[1]);
	free_tab(cmd);
	free_array(files);
	exit(EXIT_FAILURE);
}
