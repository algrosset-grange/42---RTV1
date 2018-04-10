/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_scene.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 14:49:18 by agrosset          #+#    #+#             */
/*   Updated: 2017/08/28 14:49:20 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int	ft_check_end(t_checkjson *check, t_scene *scene)
{
	check->error = NO_ERROR;
	if (check->nb_bracket || check->nb_curly_bracket)
	{
		check->error = ERROR_FIN_STRUCTURE_JSON;
		return (check->error);
	}
	if (scene->mlights == NULL)
		ft_make_new_light(check, scene);
	if (check->error != NO_ERROR)
		return (ERROR);
	return (NO_ERROR);
}

static int	ft_make_scene_p2(t_rt *rt, t_checkjson *check)
{
	int	bol_gnl;

	bol_gnl = 1;
	while (bol_gnl)
	{
		bol_gnl = ft_get_next_line(check->fd, &check->line);
		check->nu_line++;
		if (!ft_str_iswhitespace(check->line))
		{
			if ((check->error = ft_check_interlude(check)) != NO_ERROR)
				return (ERROR);
			if (ft_str_occurence(check->line, '"'))
			{
				if (ft_check(check, rt) == ERROR)
					return (ERROR);
			}
		}
	}
	if (check->bol_gnl == -1)
		return (ft_error(ERROR_LECTURE));
	return (ft_check_end(check, rt->scene));
}

int			ft_make_scene(t_rt *rt, char *file)
{
	t_checkjson	check;

	ft_check_init(&check, file);
	if ((check.fd = open(file, O_RDONLY)) == -1)
		return (ft_error(ERROR_OPEN_FILE));
	return (ft_make_scene_p2(rt, &check));
}
