/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rtvo_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 11:01:25 by agrosset          #+#    #+#             */
/*   Updated: 2017/08/28 14:48:15 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	ft_rtvo_move_p1(int keycode, t_rt *rt)
{
	if (keycode == KEY_A)
		rt->scene->origin.x -= 2;
	if (keycode == KEY_D)
		rt->scene->origin.x += 2;
	if (keycode == KEY_W)
		rt->scene->origin.y -= 2;
	if (keycode == KEY_S)
		rt->scene->origin.y += 2;
	if (keycode == KEY_Q)
		rt->scene->origin.z -= 2;
	if (keycode == KEY_E)
		rt->scene->origin.z += 2;
	if (keycode == KEY_J)
		rt->scene->look_at.x -= 0.5;
	if (keycode == KEY_L)
		rt->scene->look_at.x += 0.5;
	if (keycode == KEY_I)
		rt->scene->look_at.y -= 0.5;
	if (keycode == KEY_K)
		rt->scene->look_at.y += 0.5;
	if (keycode == KEY_U)
		rt->scene->look_at.z -= 0.5;
	if (keycode == KEY_O)
		rt->scene->look_at.z += 0.5;
}

static void	ft_rtvo_move_p3(int keycode, t_rt *rt)
{
	if (keycode == KEY_3)
	{
		if (rt->bol_diffuse_draw == 1)
			rt->bol_diffuse_draw = 0;
		else if (rt->bol_diffuse_draw == 0)
			rt->bol_diffuse_draw = 1;
	}
	if (keycode == KEY_4)
	{
		if (rt->bol_specular_draw == 1)
			rt->bol_specular_draw = 0;
		else if (rt->bol_specular_draw == 0)
			rt->bol_specular_draw = 1;
	}
}

static void	ft_rtvo_move_p2(int keycode, t_rt *rt)
{
	if (keycode == KEY_1)
	{
		if (rt->bol_fig_draw == 1)
			rt->bol_fig_draw = 0;
		else if (rt->bol_fig_draw == 0)
			rt->bol_fig_draw = 1;
	}
	if (keycode == KEY_2)
	{
		if (rt->bol_shadow_draw == 1)
			rt->bol_shadow_draw = 0;
		else if (rt->bol_shadow_draw == 0)
			rt->bol_shadow_draw = 1;
	}
}

int			ft_rtvo_move(int keycode, t_rt *rt)
{
	char	*tmp;

	ft_rtvo_move_p1(keycode, rt);
	ft_rtvo_move_p2(keycode, rt);
	ft_rtvo_move_p3(keycode, rt);
	if (keycode == KEY_W || keycode == KEY_S || keycode == KEY_A ||
		keycode == KEY_D || keycode == KEY_Q || keycode == KEY_E ||
		keycode == KEY_I || keycode == KEY_K || keycode == KEY_J ||
		keycode == KEY_L || keycode == KEY_U || keycode == KEY_O ||
		keycode == KEY_1 || keycode == KEY_2 || keycode == KEY_3 ||
		keycode == KEY_4)
		ft_render(rt);
	ft_putstr("[");
	tmp = ft_itoa(keycode);
	ft_putstr(tmp);
	ft_memdel((void **)&tmp);
	ft_putstr("]\n");
	if (keycode == KEY_ECHAP)
		ft_exit(rt);
	return (0);
}
