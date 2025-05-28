/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajodar-c <ajodar-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:04:14 by ajodar-c          #+#    #+#             */
/*   Updated: 2024/10/03 12:56:29 by ajodar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int c, size_t n)
{
	unsigned char	*p;
	unsigned char	v;
	size_t			i;

	p = (unsigned char *)ptr;
	v = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (p[i] == v)
			return ((char *)&p[i]);
		i++;
	}
	return (NULL);
}
