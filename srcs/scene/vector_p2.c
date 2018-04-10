/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_p2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 17:55:55 by agrosset          #+#    #+#             */
/*   Updated: 2017/11/23 17:55:57 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_vect_vect_multi_double(t_vector *v, const t_vector *v1,
	double multiple)
{
	v->x = v1->x * multiple;
	v->y = v1->y * multiple;
	v->z = v1->z * multiple;
}

void	ft_vect_vect_factor(t_vector *v, const t_vector *a, double factor,
	const t_vector *b)
{
	v->x = a->x + (factor * b->x);
	v->y = a->y + (factor * b->y);
	v->z = a->z + (factor * b->z);
}

void	ft_vect_vect_negation(t_vector *v, const t_vector *v1)
{
	v->x = -v1->x;
	v->y = -v1->y;
	v->z = -v1->z;
}

double	ft_get_length(const t_vector *v1)
{
	return (v1->x + v1->y + v1->z);
}

double	ft_get_square_length(const t_vector *v1)
{
	return ((v1->x * v1->x) + (v1->y * v1->y) + (v1->z * v1->z));
}
