/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajodar-c <ajodar-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:23:56 by ajodar-c          #+#    #+#             */
/*   Updated: 2024/10/03 12:45:31 by ajodar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	*dst;

	i = 0;
	str = (unsigned char *)src;
	dst = (unsigned char *)dest;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (dest == src || n == 0)
		return (dest);
	while (i < n)
	{
		dst[i] = str[i];
		i++;
	}
	return (dest);
}
