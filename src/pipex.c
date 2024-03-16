/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavier <afavier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:52:53 by afavier           #+#    #+#             */
/*   Updated: 2024/03/05 13:06:02 by afavier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"
#include <sys/wait.h>

int	main(int argc, char **argv, char **env)
{
	t_array	*files;

	number_args(argc);
	files = initialize_array(argv);
	if (!files)
		exit(EXIT_FAILURE);
	path_cmd_one(argv, env, files);
	if (files->fd[1] != -1)
		path_cmd_two(argv, env, files);
	while (wait(NULL) > 0)
		;
	if (files->fd[1] == -1)
		ft_dprintf(2, "pipex: %s: Permission denied\n", argv[4]);
	if (files->fd[0] != -1)
		close(files->fd[0]);
	if (files->fd[1] != -1)
		close(files->fd[1]);
	close(files->fd_cmd[0]);
	close(files->fd_cmd[1]);
	free_array(files);
	return (0);
}

t_array	*initialize_array(char **argv)
{
	t_array	*new_array;

	new_array = malloc(sizeof(t_array));
	if (!new_array)
		return (NULL);
	new_array->fd[0] = open_fd_cmd_one(argv);
	new_array->fd[1] = open_fd_cmd_two(argv);
	if (pipe(new_array->fd_cmd) == -1)
	{
		ft_dprintf(2, "pipex: %s\n", strerror(errno));
		if (new_array->fd[0] > 0)
			close(new_array->fd[0]);
		close(new_array->fd[1]);
		free(new_array);
		return (NULL);
	}
	new_array->i = 0;
	return (new_array);
}

void	number_args(int argc)
{
	if (argc != 5)
	{
		ft_dprintf(2, "pipex: Error argument\n");
		exit(EXIT_FAILURE);
	}
}

void	free_array(t_array *files)
{
	if (files)
		free(files);
}
