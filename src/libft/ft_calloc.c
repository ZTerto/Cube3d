/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajodar-c <ajodar-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 12:03:43 by ajodar-c          #+#    #+#             */
/*   Updated: 2024/09/27 12:46:51 by ajodar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	size_t			i;
	size_t			total;
	unsigned char	*ptr;

	i = 0;
	total = num * size;
	ptr = malloc(total);
	while (i < total)
	{
		ptr[i] = '\0';
		i++;
	}
	return ((void *)ptr);
}
