/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajodar-c <ajodar-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:03:29 by ajodar-c          #+#    #+#             */
/*   Updated: 2024/10/03 12:42:40 by ajodar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	e;
	size_t	j;
	size_t	l;

	i = 0;
	e = 0;
	j = 0;
	while (dst[i] != '\0' && i < size)
		i++;
	while (src[e] != '\0')
		e++;
	if (i >= size)
		return (size + e);
	l = i;
	while (src[j] != '\0' && (l + 1) < size)
	{
		dst[l] = src[j];
		l++;
		j++;
	}
	dst[l] = '\0';
	return (i + e);
}
