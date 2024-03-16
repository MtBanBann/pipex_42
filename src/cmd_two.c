/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_two.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavier <afavier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:44:23 by afavier           #+#    #+#             */
/*   Updated: 2024/03/05 14:18:17 by afavier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	cmd_two(char *path, char **cmd, char **env, t_array *files)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		ft_dprintf(2, "pipex: %s\n", strerror(errno));
		close_files(files, path, cmd);
	}
	if (pid == 0)
	{
		if (files->fd[1] < 0)
			error_close_free(files, path, cmd);
		if (dup2(files->fd_cmd[0], STDIN_FILENO) == -1)
			error_close_free(files, path, cmd);
		if (dup2(files->fd[1], STDOUT_FILENO) == -1)
			error_close_free(files, path, cmd);
		close_files(files, path, cmd);
		execve(path, cmd, env);
		free_cmd_one(path, cmd, files);
	}
	else
		close_cmd_two_parent(files);
}

void	close_cmd_two_parent(t_array *files)
{
	if (close(files->fd_cmd[0]) == -1)
	{
		if (files->fd[0] > 0)
			close(files->fd[0]);
		if (files->fd[1] > 0)
			close(files->fd[1]);
		exit(EXIT_FAILURE);
	}
}
