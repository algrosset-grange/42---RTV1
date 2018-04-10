/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_interlude.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 14:49:18 by agrosset          #+#    #+#             */
/*   Updated: 2017/08/28 14:49:20 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int	ft_check_bracket(t_checkjson *check)
{
	int	tmp;

	tmp = 0;
	if ((tmp = ft_str_occurence(check->line, '[')) > 1)
		return (ERROR);
	check->nb_bracket += tmp;
	if (check->nb_bracket < 0)
		return (ERROR);
	if ((tmp = ft_str_occurence(check->line, ']')) > 1)
		return (ERROR);
	check->nb_bracket -= tmp;
	if (check->nb_bracket > 4)
		return (ERROR);
	return (NO_ERROR);
}

static int	ft_check_curly_bracket(t_checkjson *check)
{
	int	tmp;

	tmp = 0;
	if ((tmp = ft_str_occurence(check->line, '}')) > 2)
		return (ERROR);
	check->nb_curly_bracket -= tmp;
	if (check->nb_curly_bracket < 0)
		return (ERROR);
	if ((tmp = ft_str_occurence(check->line, '{')) > 1)
		return (ERROR);
	check->nb_curly_bracket += tmp;
	if (check->nb_curly_bracket > 4)
		return (ERROR);
	return (NO_ERROR);
}

static int	ft_check_parenthese(t_checkjson *check)
{
	int	tmp;

	tmp = 0;
	if ((tmp = ft_str_occurence(check->line, '"')) > 2 ||
		(tmp % 2) != 0)
		return (ERROR);
	return (NO_ERROR);
}

int			ft_check_interlude(t_checkjson *check)
{
	if (ft_check_bracket(check) == ERROR)
		return (ft_check_error(check, ERROR_STRUCTURE_BRACKET));
	if (ft_check_curly_bracket(check) == ERROR)
		return (ft_check_error(check, ERROR_STRUCTURE_CURLY_BRACKET));
	if (ft_check_parenthese(check) == ERROR)
		return (ft_check_error(check, ERROR_STRUCTURE_NB_PAREN));
	return (NO_ERROR);
}
