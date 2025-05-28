/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajodar-c <ajodar-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 15:04:47 by ajodar-c          #+#    #+#             */
/*   Updated: 2024/10/03 12:45:24 by ajodar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*se1;
	unsigned char	*se2;
	size_t			i;

	se1 = (unsigned char *)s1;
	se2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (se1[i] != se2[i])
			return (se1[i] - se2[i]);
		i++;
	}
	return (0);
}
