/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_annonce_p2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 13:48:06 by agrosset          #+#    #+#             */
/*   Updated: 2017/11/23 13:48:07 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int	ft_check_annonce_light(t_checkjson *check)
{
	if (!ft_str_is_c_before_c_tofind(check->line, '\"') &&
		!ft_str_char_occ_exc_wp(check->line, '"', 2, ':') &&
		!ft_str_is_c_after_c_tofind(check->line, '{'))
	{
		if (ft_match(check->line, "*\"light\"*:*{*") &&
		!ft_str_char_occ_exc_wp(check->line, ':', 1, '{'))
		{
			check->annonce_plane = ONE;
			return (NO_ERROR);
		}
		else if ((!ft_match(check->line, "*\"light\"*:*[*{*") &&
		!ft_str_char_occ_exc_wp(check->line, ':', 1, '[') &&
		!ft_str_char_occ_exc_wp(check->line, '[', 1, '{')))
		{
			check->annonce_plane = MULTI;
			return (NO_ERROR);
		}
	}
	return (ft_check_error(check, ERROR_ANNONCE));
}

int	ft_check_annonce_material(t_checkjson *check)
{
	if (!ft_str_is_c_before_c_tofind(check->line, '\"') &&
		!ft_str_char_occ_exc_wp(check->line, '"', 2, ':') &&
		!ft_str_is_c_after_c_tofind(check->line, '{'))
	{
		if (ft_match(check->line, "*\"material\"*:*{*") &&
		!ft_str_char_occ_exc_wp(check->line, ':', 1, '{'))
		{
			check->annonce_plane = ONE;
			return (NO_ERROR);
		}
		else if ((!ft_match(check->line, "*\"material\"*:*[*{*") &&
		!ft_str_char_occ_exc_wp(check->line, ':', 1, '[') &&
		!ft_str_char_occ_exc_wp(check->line, '[', 1, '{')))
		{
			check->annonce_plane = MULTI;
			return (NO_ERROR);
		}
	}
	return (ft_check_error(check, ERROR_ANNONCE));
}

int	ft_check_annonce_scene(t_checkjson *check)
{
	if (check->annonce_scene == NOT_DONE)
	{
		if (!ft_str_is_c_before_c_tofind(check->line, '\"') &&
		!ft_str_char_occ_exc_wp(check->line, '\"', 2, ':') &&
		!ft_str_is_c_after_c_tofind(check->line, '{'))
		{
			if (ft_match(check->line, "*\"scene\"*:*{*") &&
			!ft_str_char_occ_exc_wp(check->line, ':', 1, '{'))
			{
				check->annonce_scene = ONE;
				return (NO_ERROR);
			}
		}
	}
	return (ft_check_error(check, ERROR_ANNONCE));
}
