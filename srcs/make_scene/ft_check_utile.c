/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_utile.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 14:02:19 by agrosset          #+#    #+#             */
/*   Updated: 2017/11/23 14:02:20 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int			ft_check_annonce(t_checkjson *check, char *str, int *annonce)
{
	if (ft_str_is_c_before_c_tofind(check->line, '\"') ||
		!ft_match(check->line, str) ||
		ft_str_char_occ_exc_wp(check->line, '"', 2, ':') ||
		ft_str_char_occ_exc_wp(check->line, ':', 1, '{') ||
		ft_str_is_c_after_c_tofind(check->line, '{'))
		return (ft_check_error(check, ERROR_ANNONCE));
	*annonce = DONE;
	return (NO_ERROR);
}

static int	ft_check_final_line_p2(t_checkjson *check, char *line)
{
	if (ft_match(check->line, "*\"*\"*:*},*") &&
		ft_str_occurence(line, '}') == 1)
	{
		check->c_to_find = '}';
		return (NO_ERROR);
	}
	if (ft_match(check->line, "*\"*\"*:*,*") &&
		ft_str_occurence(line, '}') == 0)
	{
		check->c_to_find = ',';
		return (NO_ERROR);
	}
	return (ft_check_error(check, ERROR_STRUCTURE_END_LINE));
}

int			ft_check_final_line(t_checkjson *check, char *line)
{
	if (ft_str_occurence(line, ',') != 1)
		return (ft_check_error(check, ERROR_STRUCTURE_END_LINE));
	if (ft_match(check->line, "*\"*\"*:*}}],*") &&
		ft_str_occurence(line, '}') == 2)
	{
		check->c_to_find = '}';
		return (NO_ERROR);
	}
	if (ft_match(check->line, "*\"*\"*:*}],*") &&
		ft_str_occurence(line, '}') == 1)
	{
		check->c_to_find = '}';
		return (NO_ERROR);
	}
	if (ft_match(check->line, "*\"*\"*:*}},*") &&
		ft_str_occurence(line, '}') == 2)
	{
		check->c_to_find = '}';
		return (NO_ERROR);
	}
	return (ft_check_final_line_p2(check, line));
}

int			ft_find_number(t_checkjson *check, char *str, char **verif_val)
{
	if (ft_str_is_c_before_c_tofind(check->line, '\"') ||
		!ft_match(check->line, str) ||
		ft_str_char_occ_exc_wp(check->line, '\"', 2, ':'))
		return (ft_check_error(check, ERROR_STRUCTURE_NUMBER));
	if (ft_check_final_line(check, check->line) == ERROR)
		return (ft_check_error(check, ERROR_STRUCTURE_END_LINE));
	if (ft_str_is_c_after_c_tofind(check->line, ',') == ERROR)
		return (ft_check_error(check, ERROR_STRUCTURE_END_LINE));
	*verif_val = ft_strstr_char_occ(check->line, ':', 1) + 1;
	while (ft_iswhitespace(**verif_val))
		*verif_val += 1;
	return (NO_ERROR);
}
