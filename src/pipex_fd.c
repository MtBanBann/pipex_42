/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavier <afavier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:48:31 by afavier           #+#    #+#             */
/*   Updated: 2024/03/05 13:05:08 by afavier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	open_fd_cmd_one(char **argv)
{
	int	fd_child;

	fd_child = open(argv[1], O_RDONLY);
	if (fd_child < 0)
		ft_dprintf(2, "pipex: %s: %s\n", argv[1], strerror(errno));
	return (fd_child);
}

int	open_fd_cmd_two(char **argv)
{
	int	fd_parent;

	fd_parent = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_parent < 0)
		return (-1);
	return (fd_parent);
}
