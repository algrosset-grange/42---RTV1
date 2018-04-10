/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkjson.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 17:32:40 by agrosset          #+#    #+#             */
/*   Updated: 2017/11/21 17:32:48 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKJSON_H
# define CHECKJSON_H

# include "cla_element.h"
# include "libft.h"

# define TRUE 1
# define FALSE 0

# define NO_ERROR -3
# define NOT_DONE 0
# define IN_PROGRE -1
# define DONE -2

# define ERROR 1
# define ERROR_OPEN_FILE 3
# define ERROR_INIT_IMAGE 4
# define ERROR_MALLOC 5
# define ERROR_LECTURE 6
# define ERROR_FIN_STRUCTURE_JSON 7
# define ERROR_STRUCTURE_BRACKET 8
# define ERROR_STRUCTURE_CURLY_BRACKET 9
# define ERROR_STRUCTURE_NB_PAREN 10
# define ERROR_ANNONCE 11
# define ERROR_STRUCTURE_NUMBER 12
# define ERROR_NOT_INT 13
# define ERROR_NOT_DOUBLE 14
# define ERROR_NOT_UNS_INT 15
# define ERROR_NOT_UNS_DOUBLE 16
# define ERROR_STRUCTURE_END_LINE 17
# define ERROR_BAD_VAR 18
# define ERROR_LIGNE_NO_USE 19

# define ONE -4
# define MULTI -5

typedef struct	s_checkjson
{
	int			fd;
	char		*line;
	int			bol_gnl;
	char		*file;
	int			nu_line;

	int			error;

	int			nb_curly_bracket;
	int			nb_bracket;

	char		c_to_find;

	int			annonce_vector;
	int			origin;
	int			direction;
	int			translation;
	int			rotation;
	double		vec_x;
	double		vec_y;
	double		vec_z;
	int			mat;
	int			num_mat;
	int			radius;
	double		size_radius;
	int			annonce_color;
	int			color;
	int			color_r;
	int			color_g;
	int			color_b;
	int			scene_origin;
	int			scene_look_at;
	int			scene_translation;
	int			scene_rotation;
	int			height;
	int			width;
	int			material;
	int			annonce_material;
	int			new_material;
	int			light;
	int			annonce_light;
	int			new_light;
	int			sphere;
	int			annonce_sphere;
	int			new_sphere;
	int			plane;
	int			annonce_plane;
	int			new_plane;
	int			cylinder;
	int			annonce_cylinder;
	int			new_cylinder;
	int			cone;
	int			annonce_cone;
	int			new_cone;
	int			annonce_scene;
}				t_checkjson;

/*
**	check_double_p1.c
*/

int				ft_check_uns_double(t_checkjson *check, char *str, double *var);
int				ft_check_double(t_checkjson *check, char *str, double *var);

/*
**	check_double_p2.c
*/

int				ft_take_double_until(char *str, double *nb, char c);
int				ft_take_uns_double_until(char *str, double *nb, char c);

/*
**	check_int.c
*/

int				ft_check_int(t_checkjson *check, char *str, int *var);
int				ft_check_uns_int(t_checkjson *check, char *str, int *var);

/*
**	check_re_init_p1.c
*/

void			ft_re_init_color(t_checkjson *check);
void			ft_re_init_vect(t_checkjson *check);
void			ft_re_init_scene(t_checkjson *check);
void			ft_re_init_material(t_checkjson *check);
void			ft_re_init_light(t_checkjson *check);

/*
**	check_re_init_p2.c
*/

void			ft_re_init_sphere(t_checkjson *check);
void			ft_re_init_plane(t_checkjson *check);
void			ft_re_init_cylinder(t_checkjson *check);
void			ft_re_init_cone(t_checkjson *check);

/*
**	ft_check.c
*/

int				ft_check(t_checkjson *check, t_rt *rt);

/*
**	ft_check_annonce_p1.c
*/

int				ft_check_annonce_sphere(t_checkjson *check);
int				ft_check_annonce_plane(t_checkjson *check);
int				ft_check_annonce_cone(t_checkjson *check);
int				ft_check_annonce_cylinder(t_checkjson *check);

/*
**	ft_check_annonce_p2.c
*/

int				ft_check_annonce_light(t_checkjson *check);
int				ft_check_annonce_material(t_checkjson *check);
int				ft_check_annonce_scene(t_checkjson *check);

/*
**	ft_check_init.c
*/

int				ft_check_init(t_checkjson *check, char *file);

/*
**	ft_check_interlude.c
*/

int				ft_check_interlude(t_checkjson *check);

/*
**	ft_check_part_cone_p1.c
*/

int				ft_check_part_cone(t_checkjson *check, t_scene *scene);

/*
**	ft_check_part_cone_p2.c
*/

int				ft_origin_cone(t_checkjson *check, t_scene *scene);
int				ft_direction_cone(t_checkjson *check, t_scene *scene);

/*
**	ft_check_part_cone_p3.c
*/

int				ft_translation_cone(t_checkjson *check, t_scene *scene);
int				ft_rotation_cone(t_checkjson *check, t_scene *scene);

/*
**	ft_check_part_cone_p4.c
*/

int				ft_check_multi_cone(t_checkjson *check, t_scene *scene);
int				ft_make_new_cone(t_checkjson *check, t_scene *scene);
int				ft_check_add_mat_cone(t_checkjson *check, t_scene *scene);
int				ft_radius_cone(t_checkjson *check, t_scene *scene);

/*
**	ft_check_part_cylinder_p1.c
*/

int				ft_check_part_cylinder(t_checkjson *check, t_scene *scene);

/*
**	ft_check_part_cylinder_p2.c
*/

int				ft_origin_cylinder(t_checkjson *check, t_scene *scene);
int				ft_direction_cylinder(t_checkjson *check, t_scene *scene);

/*
**	ft_check_part_cylinder_p3.c
*/

int				ft_translation_cylinder(t_checkjson *check, t_scene *scene);
int				ft_rotation_cylinder(t_checkjson *check, t_scene *scene);

/*
**	ft_check_part_cylinder_p4.c
*/

int				ft_check_multi_cylinder(t_checkjson *check, t_scene *scene);
int				ft_make_new_cylinder(t_checkjson *check, t_scene *scene);
int				ft_check_add_mat_cylinder(t_checkjson *check, t_scene *scene);
int				ft_radius_cylinder(t_checkjson *check, t_scene *scene);

/*
**	ft_check_part_light_p1.c
*/

int				ft_check_part_light(t_checkjson *check, t_scene *scene);

/*
**	ft_check_part_light_p2.c
*/

int				ft_origin_light(t_checkjson *check, t_scene *scene);
int				ft_translation_light(t_checkjson *check, t_scene *scene);

/*
**	ft_check_part_light_p3.c
*/

int				ft_check_multi_light(t_checkjson *check, t_scene *scene);
int				ft_color_light(t_checkjson *check, t_scene *scene);
int				ft_make_new_light(t_checkjson *check, t_scene *scene);

/*
**	ft_check_part_material_p1.c
*/

int				ft_check_part_material(t_checkjson *check, t_scene *scene);

/*
**	ft_check_part_material_p2.c
*/

int				ft_check_multi_material(t_checkjson *check, t_scene *scene);
int				ft_color_material(t_checkjson *check, t_scene *scene);
int				ft_make_new_material(t_checkjson *check, t_scene *scene);

/*
**	ft_check_part_p1.c
*/

int				ft_check_part_p1(t_checkjson *check, t_rt *rt);

/*
**	ft_check_part_plane_p1.c
*/

int				ft_check_part_plane(t_checkjson *check, t_scene *scene);

/*
**	ft_check_part_plane_p2.c
*/

int				ft_origin_plane(t_checkjson *check, t_scene *scene);
int				ft_direction_plane(t_checkjson *check, t_scene *scene);

/*
**	ft_check_part_plane_p3.c
*/

int				ft_translation_plane(t_checkjson *check, t_scene *scene);
int				ft_rotation_plane(t_checkjson *check, t_scene *scene);

/*
**	ft_check_part_plane_p4.c
*/
int				ft_check_multi_plane(t_checkjson *check, t_scene *scene);
int				ft_make_new_plane(t_checkjson *check, t_scene *scene);
int				ft_check_add_mat_plane(t_checkjson *check, t_scene *scene);

/*
**	ft_check_part_scene_p1.c
*/

int				ft_check_part_scene(t_checkjson *check, t_scene *scene);

/*
**	ft_check_part_scene_p2.c
*/

int				ft_origin_scene(t_checkjson *check, t_scene *scene);
int				ft_look_at_scene(t_checkjson *check, t_scene *scene);

/*
**	ft_check_part_scene_p3.c
*/

int				ft_translation_scene(t_checkjson *check, t_scene *scene);
int				ft_rotation_scene(t_checkjson *check, t_scene *scene);

/*
**	ft_check_part_sphere_p1.c
*/

int				ft_check_part_sphere(t_checkjson *check, t_scene *scene);

/*
**	ft_check_part_sphere_p2.c
*/

int				ft_origin_sphere(t_checkjson *check, t_scene *scene);
int				ft_translation_sphere(t_checkjson *check, t_scene *scene);

/*
**	ft_check_part_sphere_p3.c
*/

int				ft_check_multi_sphere(t_checkjson *check, t_scene *scene);
int				ft_make_new_sphere(t_checkjson *check, t_scene *scene);
int				ft_check_add_mat_sphere(t_checkjson *check, t_scene *scene);
int				ft_radius_sphere(t_checkjson *check, t_scene *scene);

/*
**	ft_check_utile.c
*/

int				ft_check_annonce(t_checkjson *check, char *str, int *annonce);
int				ft_check_final_line(t_checkjson *check, char *line);
int				ft_find_number(t_checkjson *check, char *str,
					char **verif_val);

/*
**	ft_make_scene.c
*/

int				ft_make_scene(t_rt *rt, char *file);

#endif
