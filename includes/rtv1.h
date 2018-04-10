/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 11:18:11 by agrosset          #+#    #+#             */
/*   Updated: 2017/01/25 11:18:13 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "libft.h"
# include "key_code.h"
# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include <unistd.h>

# include "checkjson.h"

# include "cla_element.h"
# include "fct_element.h"

# define C_YELLOW_WEST 0xFFFF00
# define C_RED_NORTH 0xFF0000
# define C_GREEN_EST 0x00FF00
# define C_BLUE_SOUTH 0x0000FF
# define C_SKY 0xACE5F0
# define C_WHITE_GROUND 0xFFFFFF
# define SIZE_BLOCK 64

# define SPHERE 10
# define PLANE 11
# define CYLINDER 12
# define CONE 13

void	compute_color(t_rt *rt, t_intersection_info *the_object,
			t_light *light, t_ray *ray);

int		ft_error(int type_error);
int		ft_check_error(t_checkjson *check, int type_error);

void	ft_free(t_rt *rt);
void	ft_putstr_color(t_color *color);
void	ft_putstr_vector(t_vector *vec);
void	ft_free_scene_p2(t_scene *scene);
void	ft_free_scene_p3(t_scene *scene);

void	ft_get_scene_info_p1(t_scene *scene);
void	ft_get_scene_info_p2(t_scene *scene);
void	ft_get_scene_info_p3(t_scene *scene);

void	ft_img_put_pixel(t_rt *rt, unsigned long x, unsigned long y, int rgb);
void	ft_img_put_pixel_tab(t_rt *rt, unsigned long *x_y, t_color *rgb);

int		ft_init(t_rt *rt);

void	ft_mlx(t_rt *rt);
int		ft_exit(t_rt *rt);

void	ft_putstr_vector(t_vector *vec);

void	ft_raytrace(t_rt *rt);

int		ft_render(t_rt *rt);

void	ft_rotate(t_vector *direction, t_vector *rot);

void	ft_rotate_scene_p1(t_scene *scene);
void	ft_rotate_scene_p2(t_scene *scene, t_vector *rotate);

int		ft_rtvo_move(int keycode, t_rt *rt);

void	ft_vector_normal(t_vector *n_xyz, t_intersection_info *the_object,
			t_ray *ray);

void	ft_intersect_sphere(const t_rt *rt);
void	ft_intersect_plane(const t_rt *rt);
void	ft_intersect_cylinder(const t_rt *rt);
void	ft_intersect_cone(const t_rt *rt);

void	ft_re_intersect_sphere(t_rt *rt, t_intersection_info *the_object);
void	ft_re_intersect_plane(t_rt *rt, t_intersection_info *the_object);
void	ft_re_intersect_cylinder(t_rt *rt, t_intersection_info *the_object);
void	ft_re_intersect_cone(t_rt *rt, t_intersection_info *the_object);

int		ft_scene_demo(t_scene *scene);
int		ft_scene_demo_p2(t_scene *scene);

void	graduate_color(t_color *finalcolor, t_color *obj_rgb,
			t_color *light_rgb, double coef);

#endif
