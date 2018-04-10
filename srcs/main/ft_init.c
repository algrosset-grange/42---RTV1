/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 12:30:37 by agrosset          #+#    #+#             */
/*   Updated: 2017/11/24 12:30:38 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int	ft_init_scene(t_scene *scene)
{
	scene->pixelwidth = 1000;
	scene->pixelheight = 1000;
	scene->precompwidth = -1.0f;
	scene->precompheight = -1.0f;
	scene->mlights = NULL;
	scene->mspheres = NULL;
	scene->mplanes = NULL;
	if ((scene->material_default = ft_n_material()) == NULL)
		return (ft_error(ERROR));
	scene->mmaterials = NULL;
	return (NO_ERROR);
}

static int	ft_init_image(t_rt *rt)
{
	if (((rt->ptr = mlx_init()) == NULL))
		return (ft_error(ERROR_MALLOC));
	if ((rt->img_ptr = mlx_new_image(rt->ptr, rt->scene->pixelwidth,
			rt->scene->pixelwidth)) == NULL)
		return (ft_error(ERROR_MALLOC));
	if ((rt->win = mlx_new_window(rt->ptr, rt->scene->pixelwidth,
				rt->scene->pixelheight, "rtv1")) == NULL)
		return (ft_error(ERROR_MALLOC));
	rt->img_data = mlx_get_data_addr(rt->img_ptr, &(rt->img_bits_per_pixel),
		&(rt->img_size_line), &(rt->img_endian));
	return (NO_ERROR);
}

static void	ft_init_rt(t_rt *rt)
{
	rt->ptr = NULL;
	rt->win = NULL;
	rt->img = NULL;
	rt->img_ptr = NULL;
	rt->img_data = NULL;
	rt->img_bits_per_pixel = 0;
	rt->img_size_line = -1;
	rt->img_endian = -1;
	rt->raytracing = NULL;
	rt->scene = NULL;
	rt->ray = NULL;
	rt->bol_fig_draw = TRUE;
	rt->bol_shadow_draw = FALSE;
	rt->bol_specular_draw = FALSE;
	rt->bol_diffuse_draw = FALSE;
}

int			ft_init_p2(t_rt *rt)
{
	if (ft_init_image(rt) == ERROR)
	{
		ft_free(rt);
		return (ERROR);
	}
	if ((rt->raytracing = ft_memalloc(sizeof(t_raytracer))) == NULL)
	{
		ft_free(rt);
		return (ft_error(ERROR_MALLOC));
	}
	if ((rt->ray = ft_memalloc(sizeof(t_raytracer))) == NULL)
	{
		ft_free(rt);
		return (ft_error(ERROR_MALLOC));
	}
	return (NO_ERROR);
}

int			ft_init(t_rt *rt)
{
	ft_init_rt(rt);
	if ((rt->scene = ft_memalloc(sizeof(t_scene))) == NULL)
	{
		ft_free(rt);
		return (ft_error(ERROR_MALLOC));
	}
	if (ft_init_scene(rt->scene) == ERROR)
	{
		ft_free(rt);
		return (ERROR);
	}
	return (ft_init_p2(rt));
}
