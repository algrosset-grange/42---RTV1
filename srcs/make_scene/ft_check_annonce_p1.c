/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_annonce_p1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 13:47:58 by agrosset          #+#    #+#             */
/*   Updated: 2017/11/23 13:48:00 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int	ft_check_annonce_sphere(t_checkjson *check)
{
	if (!ft_str_is_c_before_c_tofind(check->line, '\"') &&
		!ft_str_char_occ_exc_wp(check->line, '"', 2, ':') &&
		!ft_str_is_c_after_c_tofind(check->line, '{'))
	{
		if (ft_match(check->line, "*\"sphere\"*:*{*") &&
		!ft_str_char_occ_exc_wp(check->line, ':', 1, '{'))
		{
			check->annonce_sphere = ONE;
			return (NO_ERROR);
		}
		else if ((ft_match(check->line, "*\"sphere\"*:*[*{*") &&
			!ft_str_char_occ_exc_wp(check->line, ':', 1, '[') &&
			!ft_str_char_occ_exc_wp(check->line, '[', 1, '{')))
		{
			check->annonce_sphere = MULTI;
			return (NO_ERROR);
		}
	}
	return (ft_check_error(check, ERROR_ANNONCE));
}

int	ft_check_annonce_plane(t_checkjson *check)
{
	if (!ft_str_is_c_before_c_tofind(check->line, '\"') &&
		!ft_str_char_occ_exc_wp(check->line, '"', 2, ':') &&
		!ft_str_is_c_after_c_tofind(check->line, '{'))
	{
		if (ft_match(check->line, "*\"plane\"*:*{*") &&
		!ft_str_char_occ_exc_wp(check->line, ':', 1, '{'))
		{
			check->annonce_plane = ONE;
			return (NO_ERROR);
		}
		else if ((!ft_match(check->line, "*\"plane\"*:*[*{*") &&
		!ft_str_char_occ_exc_wp(check->line, ':', 1, '[') &&
		!ft_str_char_occ_exc_wp(check->line, '[', 1, '{')))
		{
			check->annonce_plane = MULTI;
			return (NO_ERROR);
		}
	}
	return (ft_check_error(check, ERROR_ANNONCE));
}

int	ft_check_annonce_cone(t_checkjson *check)
{
	if (!ft_str_is_c_before_c_tofind(check->line, '\"') &&
		!ft_str_char_occ_exc_wp(check->line, '"', 2, ':') &&
		!ft_str_is_c_after_c_tofind(check->line, '{'))
	{
		if (ft_match(check->line, "*\"cone\"*:*{*") &&
		!ft_str_char_occ_exc_wp(check->line, ':', 1, '{'))
		{
			check->annonce_plane = ONE;
			return (NO_ERROR);
		}
		else if ((!ft_match(check->line, "*\"cone\"*:*[*{*") &&
		!ft_str_char_occ_exc_wp(check->line, ':', 1, '[') &&
		!ft_str_char_occ_exc_wp(check->line, '[', 1, '{')))
		{
			check->annonce_plane = MULTI;
			return (NO_ERROR);
		}
	}
	return (ft_check_error(check, ERROR_ANNONCE));
}

int	ft_check_annonce_cylinder(t_checkjson *check)
{
	if (!ft_str_is_c_before_c_tofind(check->line, '\"') &&
		!ft_str_char_occ_exc_wp(check->line, '"', 2, ':') &&
		!ft_str_is_c_after_c_tofind(check->line, '{'))
	{
		if (ft_match(check->line, "*\"cylinder\"*:*{*") &&
		!ft_str_char_occ_exc_wp(check->line, ':', 1, '{'))
		{
			check->annonce_plane = ONE;
			return (NO_ERROR);
		}
		else if ((!ft_match(check->line, "*\"cylinder\"*:*[*{*") &&
		!ft_str_char_occ_exc_wp(check->line, ':', 1, '[') &&
		!ft_str_char_occ_exc_wp(check->line, '[', 1, '{')))
		{
			check->annonce_plane = MULTI;
			return (NO_ERROR);
		}
	}
	return (ft_check_error(check, ERROR_ANNONCE));
}
