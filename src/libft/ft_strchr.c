/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajodar-c <ajodar-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 11:50:09 by ajodar-c          #+#    #+#             */
/*   Updated: 2024/10/04 11:56:37 by ajodar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	*sptr;

	i = 0;
	sptr = (char *)str;
	while (sptr[i] != '\0')
	{
		if ((char)sptr[i] == (char)c)
			return (&sptr[i]);
		i++;
	}
	if ((char)c == '\0')
		return (&sptr[i]);
	return (NULL);
}
