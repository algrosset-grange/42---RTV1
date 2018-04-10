/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_scene_info_p1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 12:29:13 by agrosset          #+#    #+#             */
/*   Updated: 2017/11/24 12:29:14 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		ft_putstr_vector(t_vector *vec)
{
	char *tmp;

	ft_putstr("\t\t\tx = ");
	tmp = ft_dtoa(vec->x);
	ft_putstr(tmp);
	ft_memdel((void **)&tmp);
	ft_putstr("\n");
	ft_putstr("\t\t\ty = ");
	tmp = ft_dtoa(vec->y);
	ft_putstr(tmp);
	ft_memdel((void **)&tmp);
	ft_putstr("\n");
	ft_putstr("\t\t\tz = ");
	tmp = ft_dtoa(vec->z);
	ft_putstr(tmp);
	ft_memdel((void **)&tmp);
	ft_putstr("\n");
}

void		ft_putstr_color(t_color *color)
{
	char *tmp;

	ft_putstr("\t\t\tr = ");
	tmp = ft_itoa(color->r);
	ft_putstr(tmp);
	ft_memdel((void **)&tmp);
	ft_putstr("\n");
	ft_putstr("\t\t\tg = ");
	tmp = ft_itoa(color->g);
	ft_putstr(tmp);
	ft_memdel((void **)&tmp);
	ft_putstr("\n");
	ft_putstr("\t\t\tb = ");
	tmp = ft_itoa(color->b);
	ft_putstr(tmp);
	ft_memdel((void **)&tmp);
	ft_putstr("\n");
}

static void	ft_get_scene_info(t_scene *scene)
{
	char *tmp;

	ft_putstr("\nft_get_scene_info\n");
	ft_putstr("\tpixelwidth = ");
	tmp = ft_ltoa(scene->pixelwidth);
	ft_putstr(tmp);
	ft_memdel((void **)&tmp);
	ft_putstr("\n\tpixelheight = ");
	tmp = ft_ltoa(scene->pixelheight);
	ft_putstr(tmp);
	ft_memdel((void **)&tmp);
	ft_putstr("\nscene->origin\n");
	ft_putstr_vector(&scene->origin);
	ft_putstr("scene->look_at\n");
	ft_putstr_vector(&scene->look_at);
}

void		ft_get_scene_info_p1(t_scene *scene)
{
	ft_get_scene_info(scene);
	ft_get_scene_info_p2(scene);
	ft_get_scene_info_p3(scene);
}
