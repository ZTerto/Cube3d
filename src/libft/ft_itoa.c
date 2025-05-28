/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajodar-c <ajodar-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 12:35:55 by ajodar-c          #+#    #+#             */
/*   Updated: 2024/10/03 12:51:31 by ajodar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(int n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*ft_iszero(void)
{
	char	*str;

	str = malloc(2);
	if (str == NULL)
		return (NULL);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

static char	*ft_createstring(long nb, size_t sign)
{
	size_t	len;
	char	*str;

	len = ft_numlen (nb) + sign;
	str = malloc(len + 1);
	if (str == NULL)
		return (NULL);
	if (sign == 1)
		str[0] = '-';
	str[len] = '\0';
	while (len > sign)
	{
		str[--len] = '0' + (nb % 10);
		nb = nb / 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	size_t	sign;
	long	nb;

	sign = 0;
	nb = n;
	if (n == 0)
		return (ft_iszero());
	if (nb < 0)
	{
		nb = -nb;
		sign = 1;
	}
	return (ft_createstring (nb, sign));
}
