/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 16:09:27 by agrosset          #+#    #+#             */
/*   Updated: 2016/11/06 16:09:29 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_ltoa3(char *nbr, long nn, int tab[3])
{
	int		temp;
	int		iter;

	iter = 0;
	if (tab[1])
	{
		nbr[0] = '-';
		iter++;
	}
	while (iter < (tab[1] + tab[2]))
	{
		temp = nn / tab[0];
		nbr[iter] = '0' + temp;
		nn = nn - (temp * tab[0]);
		tab[0] = tab[0] / 10;
		iter++;
	}
	nbr[iter] = '\0';
}

static long	ft_ltoa2(long nn, int tab[3])
{
	tab[1] = 0;
	if (nn < 0)
	{
		tab[1] = 1;
		nn = nn * -1;
	}
	tab[2] = 0;
	tab[0] = 1;
	while (nn / tab[0] >= 10)
	{
		tab[0] = tab[0] * 10;
		tab[2]++;
	}
	tab[2]++;
	return (nn);
}

/*
**	tab[0] = exposant x 10
**	tab[1] = indique si negatif ou non
**	tab[2] = nbr de *10
*/

char		*ft_ltoa(long n)
{
	char	*nbr;
	long	nn;
	int		tab[3];

	nn = (long)n;
	nn = ft_ltoa2(nn, tab);
	if (tab[2] == 0)
		nbr = (char *)(malloc(sizeof(char) * 2));
	else
		nbr = (char *)(malloc(sizeof(char) * (tab[1] + tab[2] + 1)));
	if (nbr == NULL)
		return (NULL);
	if (tab[2] == 0)
	{
		nbr[0] = '0';
		nbr[1] = '\0';
	}
	else
		ft_ltoa3(nbr, nn, tab);
	return (nbr);
}
