/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavier <afavier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:20:26 by afavier           #+#    #+#             */
/*   Updated: 2024/02/07 00:11:45 by afavier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	y;
	size_t	o;
	char	*s;

	o = 0;
	if (!s1 || !s2)
		return (NULL);
	y = 0;
	s = malloc(sizeof(char) * ((ft_strlen((char *)s1) + ft_strlen((char *)s2))
				+ 1));
	if (!s)
		return (NULL);
	while (s1[o])
	{
		s[o] = s1[o];
		o++;
	}
	while (s2[y])
	{
		s[o + y] = s2[y];
		y++;
	}
	s[o + y] = '\0';
	return (s);
}
