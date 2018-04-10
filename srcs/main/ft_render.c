/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 12:44:57 by agrosset          #+#    #+#             */
/*   Updated: 2017/11/24 12:44:58 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	ft_generateray(t_scene *scene, double x, double y, t_ray *ray)
{
	double ratio;
	double w;

	ratio = scene->pixelwidth / scene->pixelheight;
	w = tan((60 / 2) * M_PI / 180);
	ray->direction.x = ((2 * ((x + 0.5) / scene->pixelwidth)) - 1)
		* ratio * w;
	ray->direction.y = (1 - (2 * ((y + 0.5) / scene->pixelheight))) * w;
	ray->direction.z = 1;
	ft_vect_equal_vect(&ray->origin, &scene->origin);
}

static void	ft_progression(t_scene *scene, double *x_y)
{
	if (x_y[0] == 0 && x_y[1] == 0.25f * scene->pixelheight)
		ft_putstr("25 percent completed !\n");
	if (x_y[0] == 0 && x_y[1] == 0.5f * scene->pixelheight)
		ft_putstr("50 percent completed !\n");
	if (x_y[0] == 0 && x_y[1] == 0.75f * scene->pixelheight)
		ft_putstr("75 percent completed !\n");
	if (x_y[0] == 0 && x_y[1] == (scene->pixelheight - 1))
		ft_putstr("100 - 1 percent completed !\n");
	if (x_y[0] == scene->pixelwidth - 1 && x_y[1] == scene->pixelheight - 1)
		ft_putstr("100 percent completed !\n");
}

int			ft_render(t_rt *rt)
{
	unsigned long	x_y[2];
	double			fx_y[2];

	ft_rotate_scene_p1(rt->scene);
	x_y[0] = 0;
	while (x_y[0] < rt->scene->pixelwidth)
	{
		x_y[1] = 0;
		while (x_y[1] < rt->scene->pixelheight)
		{
			fx_y[0] = (double)x_y[0];
			fx_y[1] = (double)x_y[1];
			ft_generateray(rt->scene, fx_y[0], fx_y[1], rt->ray);
			ft_color_n_color(&rt->raytracing->finalcolor);
			if (rt->bol_fig_draw == TRUE)
				ft_raytrace(rt);
			ft_progression(rt->scene, fx_y);
			ft_img_put_pixel_tab(rt, x_y, &rt->raytracing->finalcolor);
			x_y[1]++;
		}
		x_y[0]++;
	}
	mlx_put_image_to_window(rt->ptr, rt->win, rt->img_ptr, 0, 0);
	return (0);
}
