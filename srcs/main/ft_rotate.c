/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 18:17:21 by agrosset          #+#    #+#             */
/*   Updated: 2017/11/24 18:17:23 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	ft_rotate_x(t_vector *v, double rot)
{
	t_vector tmp;

	tmp.x = v->x;
	tmp.y = v->y * ft_cos_deg(rot) + v->z * -ft_sin_deg(rot);
	tmp.z = v->z * ft_cos_deg(rot) + v->y * ft_sin_deg(rot);
	ft_vect_equal_vect(v, &tmp);
}

static void	ft_rotate_y(t_vector *v, double rot)
{
	t_vector tmp;

	tmp.x = v->x * ft_cos_deg(rot) + v->z * ft_sin_deg(rot);
	tmp.y = v->y;
	tmp.z = v->z * ft_cos_deg(rot) + v->x * -ft_sin_deg(rot);
	ft_vect_equal_vect(v, &tmp);
}

static void	ft_rotate_z(t_vector *v, double rot)
{
	t_vector tmp;

	tmp.x = v->x * ft_cos_deg(rot) + v->y * -ft_sin_deg(rot);
	tmp.y = v->y * ft_cos_deg(rot) + v->x * ft_sin_deg(rot);
	tmp.z = v->z;
	ft_vect_equal_vect(v, &tmp);
}

void		ft_rotate(t_vector *direction, t_vector *rot)
{
	ft_rotate_x(direction, rot->x);
	ft_rotate_y(direction, rot->y);
	ft_rotate_z(direction, rot->z);
}
