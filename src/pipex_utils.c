/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavier <afavier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 06:02:12 by afavier           #+#    #+#             */
/*   Updated: 2024/03/05 11:12:35 by afavier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

char	*find_path(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (!ft_strncmp("PATH", env[i], 4))
		{
			return (env[i] + 5);
		}
		i++;
	}
	return (NULL);
}

char	*find_exec_path(char **argv, char **env, int i, t_array *files)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(argv[i], ' ');
	if (!cmd || !cmd[0])
	{
		error_cmd_malloc(files);
		exit(EXIT_FAILURE);
	}
	if (access(cmd[0], X_OK | F_OK) == -1)
	{
		path = access_path(cmd, env, files);
		if (!path)
		{
			free_tab(cmd);
			return (NULL);
		}
		free_tab(cmd);
		return (path);
	}
	path = ft_strdup(cmd[0]);
	if (!path)
		error_exec_path_strdup(files, cmd);
	free_tab(cmd);
	return (path);
}

char	*access_path(char **cmd, char **env, t_array *files)
{
	char	**cmd_path;
	char	*path_exec;
	char	*path;

	path = find_path(env);
	if (!path)
		return (NULL);
	cmd_path = ft_split(path, ':');
	if (!cmd_path)
		error_access_path_malloc(files, cmd);
	path_exec = exec_is_good(cmd_path, cmd, 0, files);
	if (!path_exec)
	{
		free_tab(cmd_path);
		return (NULL);
	}
	free_tab(cmd_path);
	return (path_exec);
}

char	*exec_is_good(char **cmd_path, char **cmd, int i, t_array *files)
{
	char	*path_ex;
	char	*temp;

	while (cmd_path[i])
	{
		path_ex = ft_strjoin(cmd_path[i], "/");
		if (!path_ex)
			error_path_malloc(files, cmd_path, cmd);
		temp = ft_strjoin(path_ex, cmd[0]);
		if (!temp)
			error_temp_malloc(files, cmd_path, cmd, path_ex);
		free(path_ex);
		if (access(temp, X_OK | F_OK) == 0)
			return (temp);
		free(temp);
		i++;
	}
	return (NULL);
}

void	free_tab(char **tab)
{
	size_t	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
