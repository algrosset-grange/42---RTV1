/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 16:09:27 by agrosset          #+#    #+#             */
/*   Updated: 2016/11/06 16:09:29 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_dtoa2(double n)
{
	int		i;
	double	deci;

	if (n < 0.0)
		n *= -1.0;
	deci = n - (int)n;
	i = 0;
	while (deci - (double)((int)deci) != 0)
	{
		if (i == 10)
		{
			ft_putstr("(env)");
			break ;
		}
		deci *= 10.0;
		i++;
	}
	return ((int)deci);
}

char		*ft_dtoa(double n)
{
	char	*real;
	int		n_deci;
	char	*deci;

	real = ft_itoa((int)n);
	n_deci = ft_dtoa2(n);
	deci = ft_itoa(n_deci);
	ft_str_realloc_cat(&real, ".");
	ft_str_realloc_cat(&real, deci);
	ft_memdel((void **)&deci);
	return (real);
}
