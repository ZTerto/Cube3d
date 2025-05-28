/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajodar-c <ajodar-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 10:08:49 by ajodar-c          #+#    #+#             */
/*   Updated: 2024/10/03 12:55:37 by ajodar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;
	char	c;

	nb = n;
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb = -nb;
	}
	if (n == -2147483648)
	{
		write(fd, "2147483648", 10);
		return ;
	}
	if (nb > 9)
		ft_putnbr_fd(nb / 10, fd);
	c = (nb % 10) + 48;
	write(fd, &c, 1);
}
