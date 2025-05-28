/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajodar-c <ajodar-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 10:23:04 by ajodar-c          #+#    #+#             */
/*   Updated: 2024/10/03 13:55:59 by ajodar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_strlookup(const char *str, char c)
{
	while (*str)
	{
		if (c == *str)
			return (1);
		str++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		ini;
	int		end;
	int		i;

	ini = 0;
	end = ft_strlen(s1) - 1;
	i = 0;
	while (s1[ini] && ft_strlookup(set, s1[ini]))
	{
		ini++;
	}
	while (end > ini && s1[end] && ft_strlookup(set, s1[end]))
	{
		end--;
	}
	str = (char *)malloc(sizeof(char) * (end - ini + 2));
	if (str == NULL)
		return (NULL);
	while (ini <= end)
	{
		str[i++] = s1[ini++];
	}
	str[i] = '\0';
	return (str);
}
