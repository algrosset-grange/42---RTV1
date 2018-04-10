/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_element.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 11:18:11 by agrosset          #+#    #+#             */
/*   Updated: 2017/01/25 11:18:13 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FCT_ELEMENT_H
# define FCT_ELEMENT_H

# include "cla_element.h"

/*
** fonction t_intersection_info
*/

void				ft_inter_info_new_inter_info(t_intersection_info *inter);
void				ft_inter_equal_inter(t_intersection_info *inter1,
	const t_intersection_info *inter2);

/*
** fonction t_color[3]
*/
void				ft_color_new_color(t_color *rgb, int r, int g,
	int b);
void				ft_color_n_color(t_color *rgb);
void				ft_color_equal_color(t_color *c1, const t_color *c2);
t_color				*ft_color_multi_double(const t_color *c1, int multiple);
int					*ft_color_div_double(t_color *c1, int divi);
int					*ft_equal_color_div_int(t_color *c, const int *c1,
	int divi);
void				ft_normalize_color(t_color *color);

/*
** fonction t_vector
*/

void				ft_vect_n_vect(t_vector *vec);
void				ft_vect_new_vect(t_vector *vect, double x, double y,
	double z);
void				ft_vect_vect_add_vect(t_vector *v, const t_vector *v1,
	const t_vector *v2);
void				ft_vect_vect_less_vect(t_vector *v, const t_vector *v1,
	const t_vector *v2);
void				ft_vect_vect_multi_double(t_vector *v, const t_vector *v1,
	double multiple);
void				ft_vect_equal_vect(t_vector *v1, const t_vector *v2);
void				ft_vect_vect_negation(t_vector *v, const t_vector *v1);
double				ft_dot_product(const t_vector *v1, const t_vector *v2);
double				ft_get_magnitude(const t_vector *v1);
void				ft_vect_normalize(t_vector *v1);
void				ft_vect_vect_normalize(t_vector *v, t_vector *v1);
double				ft_get_square_length(const t_vector *v1);
void				ft_vect_vect_factor(t_vector *v, const t_vector *a,
	double factor, const t_vector *b);
double				ft_vect_cos_angle(t_vector *a, t_vector *b);

/*
** fonction t_light
*/

t_light				*ft_new_light(t_vector *position, t_color *color);
void				ft_light_new_light(t_light *light, t_vector *position,
	t_color *color);
int					ft_light_intersectsnode(t_light *light, const t_ray *ray,
	t_intersection_info *intersectinfo);

/*
**	fonction t_material
**	scene/material.c
*/

t_material			*ft_n_material(void);
t_material			*ft_new_material(t_color *diffuse_color);
void				ft_material_new_material(t_material *mat,
	t_color *color_diffuse);
t_material			*ft_material_multi_double(const t_material *mat,
	double multi);
t_material			*ft_material_add_material(const t_material *mat,
	const t_material *mat2);
void				ft_material_add_equal_material(t_material *mat,
	const t_material *mat2);
t_material			*ft_interpolate_materials(const t_material *mat,
	const t_material *mat2);

/*
** fonction t_plane
** scene/plane.c
*/

t_plane				*ft_new_plane(const t_vector *orig, const t_vector *direc,
	t_material *mat);
void				ft_plane_new_plane(t_plane *plan, const t_vector *orig,
	const t_vector *direc, t_material *mat);
int					ft_plane_intersectsnode(t_plane *plan, const t_ray *ray,
	t_intersection_info *intersectinfo);

/*
** fonction t_cylinder
** scene/cylinder.c
*/

t_cylinder			*ft_new_cylinder(const t_vector *origin,
	const t_vector *direction, double radius, t_material *mat);
void				ft_cylinder_new_cylinder(t_cylinder *cyl,
	t_vector *origin_direction, double radius, t_material *mat);
int					ft_cylinder_intersectsnode(t_cylinder *cyl,
	t_ray *ray, t_intersection_info *intersectinfo);

/*
** fonction t_cone
** scene/cone.c
*/

t_cone				*ft_new_cone(const t_vector *orig, const t_vector *direc,
	const double radius, t_material *mat);
void				ft_cone_new_cone(t_cone *cone, t_vector *orig_dir,
	double radius, t_material *mat);
int					ft_cone_intersectsnode(t_cone *cone, t_ray *ray,
	t_intersection_info *intersectinfo);

/*
** fonction t_sphere
** scene/sphere.c
*/

t_sphere			*ft_new_sphere(t_vector *center, double radius,
	t_material *mat);
void				ft_sphere_new_sphere(t_sphere *sphere, t_vector *center,
	double radius, t_material *mat);
int					ft_sphere_intersectsnode(t_sphere *sphere,
	const t_ray *ray, t_intersection_info *intersectinfo);

/*
** fonction pour set les different élement de scene
** set_scene.c
*/

void				updateparameters(t_scene *scene);
void				setorientation(t_scene *scene, const double *orientation);
void				ft_scene_init(t_scene *scene);

#endif
