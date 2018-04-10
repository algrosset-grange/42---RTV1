/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img_put_pixel.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 14:25:24 by agrosset          #+#    #+#             */
/*   Updated: 2017/01/14 14:25:26 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_img_put_pixel(t_rt *rt, unsigned long x, unsigned long y, int rgb)
{
	unsigned long		i;

	if (x < rt->scene->pixelwidth &&
		y < rt->scene->pixelheight)
	{
		i = x * 4 + y * (unsigned long)rt->img_size_line;
		rt->img_data[i + 2] = rgb / (0x10000);
		rgb %= 0x10000;
		rt->img_data[i + 1] = rgb / 0x100;
		rgb %= 0x100;
		rt->img_data[i] = rgb;
		rt->img_data[i + 3] = 0;
	}
}

void	ft_img_put_pixel_tab(t_rt *rt, unsigned long *x_y, t_color *color)
{
	unsigned long i;

	if (x_y[0] < rt->scene->pixelwidth &&
		x_y[1] < rt->scene->pixelheight)
	{
		i = x_y[0] * 4 + x_y[1] * rt->img_size_line;
		rt->img_data[i] = color->b;
		rt->img_data[i + 1] = color->g;
		rt->img_data[i + 2] = color->r;
		rt->img_data[i + 3] = 0;
	}
}
