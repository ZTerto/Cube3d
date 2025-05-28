/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajodar-c <ajodar-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:19:08 by ajodar-c          #+#    #+#             */
/*   Updated: 2024/10/03 12:43:34 by ajodar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	char			*st;
	char			ch;

	i = 0;
	st = (char *)s;
	ch = (unsigned char)c;
	while (i < n)
	{
		st[i] = ch;
		i++;
	}
	return (st);
}
