/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajodar-c <ajodar-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 19:23:35 by marvin            #+#    #+#             */
/*   Updated: 2024/09/30 14:51:37 by ajodar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strcount(char const *s, char c)
{
	int	i;
	int	w;

	i = 0;
	w = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != '\0')
			w++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (w);
}

static	void	ft_free(char **w, int i)
{
	while (i > 0)
		free(w[--i]);
	free(w);
	return ;
}

static int	ft_lookupwords(const char *s, int *i, char c)
{
	int	e;

	while (s[*i] == c && s[*i] != '\0')
		(*i)++;
	e = *i;
	while (s[*i] != c && s[*i] != '\0')
		(*i)++;
	return (e);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		e;
	int		w;
	char	**res;

	i = 0;
	w = 0;
	res = (char **)malloc((ft_strcount(s, c) + 1) * sizeof(char *));
	if (res == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		e = ft_lookupwords(s, &i, c);
		if (i > e)
		{
			res[w] = ft_substr(s, e, i - e);
			if (res[w] == NULL)
			{
				ft_free(res, w);
			}
			w++;
		}
	}
	res[w] = NULL;
	return (res);
}
