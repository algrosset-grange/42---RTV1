/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 13:33:16 by agrosset          #+#    #+#             */
/*   Updated: 2017/11/23 13:33:17 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int	ft_check_double(t_checkjson *check, char *str, double *var)
{
	char	*verif_val;
	double	nb;

	if (ft_find_number(check, str, &verif_val) == ERROR)
		return (ERROR);
	if (ft_take_double_until(verif_val, &nb, check->c_to_find) == ERROR)
		return (ft_check_error(check, ERROR_NOT_DOUBLE));
	*var = nb;
	return (NO_ERROR);
}

int	ft_check_uns_double(t_checkjson *check, char *str, double *var)
{
	char	*verif_val;
	double	nb;

	if (ft_find_number(check, str, &verif_val) == ERROR)
		return (ERROR);
	if (ft_take_uns_double_until(verif_val, &nb, check->c_to_find) == ERROR)
		return (ft_check_error(check, ERROR_NOT_UNS_DOUBLE));
	*var = nb;
	return (NO_ERROR);
}
