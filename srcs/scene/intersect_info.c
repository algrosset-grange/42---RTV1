/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 18:15:36 by agrosset          #+#    #+#             */
/*   Updated: 2017/11/23 18:15:38 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_inter_info_new_inter_info(t_intersection_info *inter)
{
	inter->vec_mintersection.x = -1;
	inter->vec_mintersection.y = -1;
	inter->vec_mintersection.z = -1;
	inter->vec_mnormal.x = -1;
	inter->vec_mnormal.y = -1;
	inter->vec_mnormal.z = -1;
	inter->dist = 999999.9f;
	inter->mnode = NULL;
	inter->mmaterial = NULL;
}

void	ft_inter_equal_inter(t_intersection_info *inter1,
	const t_intersection_info *inter2)
{
	inter1->vec_mintersection.x = inter2->vec_mintersection.x;
	inter1->vec_mintersection.y = inter2->vec_mintersection.y;
	inter1->vec_mintersection.z = inter2->vec_mintersection.z;
	inter1->vec_mnormal.x = inter2->vec_mnormal.x;
	inter1->vec_mnormal.y = inter2->vec_mnormal.y;
	inter1->vec_mnormal.z = inter2->vec_mnormal.z;
	inter1->dist = inter2->dist;
	inter1->mnodetype = inter2->mnodetype;
	inter1->mnode = inter2->mnode;
	inter1->mmaterial = inter2->mmaterial;
}
