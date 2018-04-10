/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 12:25:14 by agrosset          #+#    #+#             */
/*   Updated: 2017/11/24 12:25:22 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	ft_free_scene(t_rt *rt)
{
	ft_free_scene_p2(rt->scene);
	ft_free_scene_p3(rt->scene);
	ft_memdel((void **)&rt->scene);
}

static void	ft_free_image(t_rt *rt)
{
	if (rt->img_ptr != NULL)
		mlx_destroy_image(rt->ptr, rt->img_ptr);
}

void		ft_free(t_rt *rt)
{
	ft_free_scene(rt);
	ft_free_image(rt);
}
