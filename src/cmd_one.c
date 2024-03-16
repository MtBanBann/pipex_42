/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_one.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavier <afavier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:44:18 by afavier           #+#    #+#             */
/*   Updated: 2024/03/05 14:16:29 by afavier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"
#include <sys/wait.h>

void	cmd_one(char *path, char **cmd, char **env, t_array *files)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		error_close_free(files, path, cmd);
	if (pid == 0)
	{
		if (files->fd[0] < 0)
			error_close_free(files, path, cmd);
		if (dup2(files->fd_cmd[1], STDOUT_FILENO) == -1)
			error_close_free(files, path, cmd);
		if (dup2(files->fd[0], STDIN_FILENO) == -1)
			error_close_free(files, path, cmd);
		close_files(files, path, cmd);
		if (close(files->fd_cmd[1]) == -1)
			print_error_fd_cmd(files);
		execve(path, cmd, env);
		free_cmd_one(path, cmd, files);
	}
	else
		close_cmd_one_parent(files);
}

void	close_cmd_one_parent(t_array *files)
{
	if (close(files->fd_cmd[1]) == -1)
	{
		if (files->fd[0] > 0)
			close(files->fd[0]);
		if (files->fd[1] > 0)
			close(files->fd[1]);
		close(files->fd_cmd[0]);
		exit(EXIT_FAILURE);
	}
}

void	print_error_fd_cmd(t_array *files)
{
	ft_dprintf(2, "pipex: %d: %s\n", files->fd_cmd[1], strerror(errno));
	exit(EXIT_FAILURE);
}

void	free_cmd_one(char *path, char **cmd, t_array *files)
{
	ft_dprintf(2, "pipex: %s : %s\n", path, strerror(errno));
	free(path);
	free_tab(cmd);
	free_array(files);
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	exit(127);
}
