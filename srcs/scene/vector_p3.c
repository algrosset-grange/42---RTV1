/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_p3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 17:55:55 by agrosset          #+#    #+#             */
/*   Updated: 2017/11/23 17:55:57 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double	ft_get_magnitude(const t_vector *v1)
{
	return ((double)sqrt(ft_get_square_length(v1)));
}

void	ft_vect_normalize(t_vector *v1)
{
	double mag;

	mag = ft_get_magnitude(v1);
	v1->x /= mag;
	v1->y /= mag;
	v1->z /= mag;
}

void	ft_vect_vect_normalize(t_vector *v, t_vector *v1)
{
	double mag;

	mag = ft_get_magnitude(v1);
	v->x = v1->x / mag;
	v->y = v1->y / mag;
	v->z = v1->z / mag;
}

double	ft_dot_product(const t_vector *v1, const t_vector *v2)
{
	return ((v1->x * v2->x) + (v1->y * v2->y) + (v1->z * v2->z));
}

double	ft_vect_cos_angle(t_vector *a, t_vector *b)
{
	double	scalar;

	scalar = ft_dot_product(a, b);
	scalar /= ft_get_magnitude(a);
	scalar /= ft_get_magnitude(b);
	return (scalar);
}
