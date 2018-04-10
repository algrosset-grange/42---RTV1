/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 12:48:27 by agrosset          #+#    #+#             */
/*   Updated: 2017/11/24 12:48:33 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	ft_rt_img_clear(t_rt *rt)
{
	unsigned long	x;
	unsigned long	y;

	x = 0;
	while (x < rt->scene->pixelwidth)
	{
		y = 0;
		while (y < rt->scene->pixelwidth)
		{
			ft_img_put_pixel(rt, x, y, 0);
			y++;
		}
		x++;
	}
}

int			main(int argc, char **argv)
{
	t_rt	rt;

	if (ft_init(&rt) == ERROR)
		return (0);
	if (argc != 2)
	{
		if (ft_scene_demo(rt.scene) == ERROR)
		{
			ft_free(&rt);
			return (0);
		}
	}
	else
	{
		if ((ft_make_scene(&rt, argv[1])) != NO_ERROR)
		{
			ft_free(&rt);
			return (0);
		}
	}
	ft_get_scene_info_p1(rt.scene);
	ft_rt_img_clear(&rt);
	ft_render(&rt);
	ft_mlx(&rt);
	return (0);
}
