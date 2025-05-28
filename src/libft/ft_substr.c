/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajodar-c <ajodar-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 12:18:51 by ajodar-c          #+#    #+#             */
/*   Updated: 2024/09/27 16:00:44 by ajodar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	e;
	char	*set;

	i = start;
	e = 0;
	if (s == NULL || s[0] == '\0' || len == 0 || start > ft_strlen(s))
	{
		set = ft_calloc(1, sizeof(char));
		return (set);
	}
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	set = malloc(sizeof(char ) * (len + 1));
	if (set == NULL)
		return (NULL);
	while (e < len && s[i] != '\0')
	{
		set[e] = s[i];
		i++;
		e++;
	}
	set [e] = '\0';
	return (set);
}
