/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 11:01:25 by agrosset          #+#    #+#             */
/*   Updated: 2017/08/28 14:48:15 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int			ft_exit(t_rt *rt)
{
	ft_free(rt);
	exit(0);
}

static int	ft_button_press_hook(int button, int x, int y, t_rt *rt)
{
	(void)x;
	(void)y;
	if (button == 4 || button == 5 || button == 1 || button == 2)
	{
		ft_putstr("rt->scene->origin :\n");
		ft_putstr_vector(&rt->scene->origin);
		ft_putstr("rt->scene->look_at :\n");
		ft_putstr_vector(&rt->scene->look_at);
	}
	return (0);
}

void		ft_mlx(t_rt *rt)
{
	mlx_do_key_autorepeaton(rt->ptr);
	mlx_hook(rt->win, KEY_PRESS, KEY_PRESS_MASK, ft_rtvo_move, rt);
	mlx_hook(rt->win, DESTROY_NOTIFY, STRUCTURE_NOTIFY_MASK,
		ft_exit, rt);
	mlx_hook(rt->win, BUTTON_PRESS, BUTTON_PRESS, ft_button_press_hook, rt);
	mlx_loop(rt->ptr);
}
