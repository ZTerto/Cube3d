/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajodar-c <ajodar-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 15:29:38 by ajodar-c          #+#    #+#             */
/*   Updated: 2024/10/03 12:48:09 by ajodar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		j;
	char		*h;
	char		*n;

	i = 0;
	j = 0;
	h = (char *)haystack;
	n = (char *)needle;
	if (*n == '\0')
		return (h);
	while (h[i] != '\0' && i < len)
	{
		if (h[i] == n[0])
		{
			j = 0;
			while (n[j] != '\0' && h[i + j] == n[j] && (i + j) < len)
				j++;
			if (n[j] == '\0')
				return (&h[i]);
		}
		i++;
	}
	return (NULL);
}
