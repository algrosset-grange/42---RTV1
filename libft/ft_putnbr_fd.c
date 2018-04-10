/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 15:52:51 by agrosset          #+#    #+#             */
/*   Updated: 2016/11/06 15:52:52 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	affiche_nb_fd(long nb, int fd)
{
	char	c;
	int		coef;
	int		less;

	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb = nb * -1;
	}
	coef = 1;
	while ((nb / coef) >= 10)
	{
		coef = coef * 10;
	}
	while (coef >= 1)
	{
		less = nb / coef;
		c = (nb / coef);
		ft_putchar_fd(c + 48, fd);
		nb = nb - (less * coef);
		coef = coef / 10;
	}
}

void		ft_putnbr_fd(int n, int fd)
{
	long nbr;

	nbr = (long)n;
	affiche_nb_fd(nbr, fd);
}
