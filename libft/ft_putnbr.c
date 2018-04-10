/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 10:00:23 by agrosset          #+#    #+#             */
/*   Updated: 2016/11/04 10:00:25 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	affiche_nb(long nb)
{
	char	c;
	int		coef;
	int		less;

	if (nb < 0)
	{
		ft_putchar('-');
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
		ft_putchar(c + 48);
		nb = nb - (less * coef);
		coef = coef / 10;
	}
}

void		ft_putnbr(int n)
{
	long nbr;

	nbr = (long)n;
	affiche_nb(nbr);
}
