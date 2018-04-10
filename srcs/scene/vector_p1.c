/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_p1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 17:55:55 by agrosset          #+#    #+#             */
/*   Updated: 2017/11/23 17:55:57 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_vect_new_vect(t_vector *vect, double x, double y, double z)
{
	vect->x = x;
	vect->y = y;
	vect->z = z;
}

void	ft_vect_n_vect(t_vector *vec)
{
	ft_vect_new_vect(vec, 0.0f, 0.0f, 0.0f);
}

void	ft_vect_equal_vect(t_vector *v1, const t_vector *v2)
{
	v1->x = v2->x;
	v1->y = v2->y;
	v1->z = v2->z;
}

void	ft_vect_vect_add_vect(t_vector *v, const t_vector *v1,
	const t_vector *v2)
{
	v->x = v1->x + v2->x;
	v->y = v1->y + v2->y;
	v->z = v1->z + v2->z;
}

void	ft_vect_vect_less_vect(t_vector *v, const t_vector *v1,
	const t_vector *v2)
{
	v->x = v1->x - v2->x;
	v->y = v1->y - v2->y;
	v->z = v1->z - v2->z;
}
