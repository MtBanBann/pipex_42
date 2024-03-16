/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavier <afavier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 09:35:57 by afavier           #+#    #+#             */
/*   Updated: 2024/03/05 13:55:39 by afavier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	path_cmd_one(char **argv, char **env, t_array *files)
{
	char	*path;
	char	**cmd;

	if (check_first_cmd(argv, 2) == -1)
		close_files_cmd_1(files, argv);
	else
	{
		path = find_exec_path(argv, env, 2, files);
		if (!path)
			error_path_cmd_one(files, argv);
		else
		{
			cmd = ft_split(argv[2], ' ');
			if (!cmd)
				error_cmd_one(files, path, cmd);
			else
			{
				cmd_one(path, cmd, env, files);
				free(path);
				free_tab(cmd);
			}
		}
	}
}

void	path_cmd_two(char **argv, char **env, t_array *files)
{
	char	*path;
	char	**cmd;

	files->i = 1;
	if (check_first_cmd(argv, 3) == -1)
		ft_dprintf(2, "pipex: %s: command not found\n", argv[3]);
	else
	{
		path = find_exec_path(argv, env, 3, files);
		if (!path)
			ft_dprintf(2, "pipex: %s: command not found\n", argv[3]);
		else
		{
			cmd = ft_split(argv[3], ' ');
			if (!cmd)
				error_cmd_two(files, path, cmd);
			else
			{
				cmd_two(path, cmd, env, files);
				free(path);
				free_tab(cmd);
			}
		}
	}
}

int	check_first_cmd(char **argv, int i)
{
	if (argv[i][0] != '.' && argv[i][0] != '/' && argv[i][0] != '[' &&
		argv[i][0] != '_' && argv[i][0] != '~' && !((argv[i][0] >= 'a'
					&& argv[i][0] <= 'z') || (argv[i][0] >= 'A'
					&& argv[i][0] <= 'Z')))
		return (-1);
	return (0);
}

void	error_path_cmd_one(t_array *files, char **argv)
{
	close(files->fd_cmd[1]);
	ft_dprintf(2, "pipex: %s: command not found\n", argv[2]);
}

void	close_files_cmd_1(t_array *files, char **argv)
{
	close(files->fd_cmd[1]);
	ft_dprintf(2, "pipex: %s: command not found\n", argv[2]);
}
