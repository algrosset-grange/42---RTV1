/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 18:11:43 by agrosset          #+#    #+#             */
/*   Updated: 2017/11/23 18:11:45 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_color_new_color(t_color *rgb, int r, int g, int b)
{
	rgb->r = r;
	rgb->g = g;
	rgb->b = b;
}

void	ft_color_n_color(t_color *rgb)
{
	ft_color_new_color(rgb, 0, 0, 0);
}

void	ft_color_equal_color(t_color *c1, const t_color *c2)
{
	c1->r = c2->r;
	c1->g = c2->g;
	c1->b = c2->b;
}

void	ft_normalize_color(t_color *color)
{
	if (color->r < 0)
		color->r = 0;
	if (color->g < 0)
		color->g = 0;
	if (color->b < 0)
		color->b = 0;
	if (color->r > 0xFF)
		color->r = 0xFF;
	if (color->g > 0xFF)
		color->g = 0xFF;
	if (color->b > 0xFF)
		color->b = 0xFF;
}
