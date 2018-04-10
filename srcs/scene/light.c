/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 18:16:51 by agrosset          #+#    #+#             */
/*   Updated: 2017/11/23 18:16:52 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_light	*ft_new_light(t_vector *position, t_color *color)
{
	t_light *light;

	if ((light = ft_memalloc(sizeof(t_light))) == NULL)
		return (NULL);
	light->next = NULL;
	ft_vect_equal_vect(&light->origin, position);
	ft_color_equal_color(&light->mcolor, color);
	return (light);
}

void	ft_light_new_light(t_light *light, t_vector *position,
	t_color *color)
{
	light->next = NULL;
	ft_vect_equal_vect(&light->origin, position);
	ft_color_equal_color(&light->mcolor, color);
}
