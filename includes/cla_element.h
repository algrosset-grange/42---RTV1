/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cla_element.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 11:18:11 by agrosset          #+#    #+#             */
/*   Updated: 2017/01/25 11:18:13 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLA_ELEMENT_H
# define CLA_ELEMENT_H

typedef struct			s_color
{
	int					r;
	int					g;
	int					b;
}						t_color;

typedef struct			s_vector
{
	double				x;
	double				y;
	double				z;
}						t_vector;

typedef struct			s_material
{
	int					num_material;
	struct s_material	*next;
	t_color				mdiffuse;
}						t_material;

typedef struct			s_intersection_info
{
	t_vector			vec_mintersection;
	t_vector			vec_mnormal;
	double				dist;
	void				*mnode;
	int					mnodetype;
	t_material			*mmaterial;
}						t_intersection_info;

typedef struct			s_light
{
	struct s_light		*next;
	t_vector			origin;
	t_color				mcolor;
}						t_light;

typedef struct			s_sphere
{
	int					num_sphere;
	struct s_sphere		*next;
	t_material			*mmaterial;
	t_vector			origin;
	double				mradius;
}						t_sphere;

typedef struct			s_plane
{
	int					num_plane;
	struct s_plane		*next;
	t_material			*mmaterial;
	t_vector			direction;
	t_vector			origin;
	t_vector			rotation;
}						t_plane;

typedef struct			s_cyl_cone_coef
{
	double				a;
	double				b;
	double				c;
	double				d;
	double				dot_a;
	double				dot_b;
	double				csq;
	double				ssq;
	t_vector			sca_a;
	t_vector			sca_b;
	t_vector			sub_a;
	t_vector			sub_b;
	t_vector			tmp;
}						t_cyl_cone_coef;

typedef struct			s_cylinder
{
	struct s_cylinder	*next;
	t_material			*mmaterial;
	t_vector			direction;
	t_vector			origin;
	t_vector			rotation;
	double				mradius;
}						t_cylinder;

typedef struct			s_cone
{
	struct s_cone		*next;
	t_material			*mmaterial;
	t_vector			direction;
	t_vector			origin;
	t_vector			rotation;
	double				mradius;
}						t_cone;

typedef struct			s_ray
{
	t_vector			origin;
	t_vector			direction;
	double				mt;
}						t_ray;

typedef struct			s_raytracer
{
	int					bool_init;

	t_color				finalcolor;
	t_intersection_info	tmpinterinfo;
	t_intersection_info	closestinterinfo;
	int					lightblocked;
	t_vector			vec_light;
	double				lighttoobjdist;
	double				lighttointerdist;
	t_ray				lightray;
	t_intersection_info	lightinterinfo;
}						t_raytracer;

typedef struct			s_scene
{
	t_vector			origin;
	t_vector			look_at;
	t_vector			rotation;

	t_vector			orientation_u;
	t_vector			orientation_v;

	unsigned long		pixelwidth;
	unsigned long		pixelheight;

	double				precompwidth;
	double				precompheight;

	t_material			*material_default;

	t_material			*mmaterials;
	t_light				*mlights;
	t_sphere			*mspheres;
	t_plane				*mplanes;
	t_cylinder			*mcylinders;
	t_cone				*mcones;
}						t_scene;

typedef struct			s_rt
{
	void				*ptr;
	void				*win;
	struct s_img		*img;

	void				*img_ptr;
	char				*img_data;
	int					img_bits_per_pixel;
	int					img_size_line;
	int					img_endian;

	t_raytracer			*raytracing;
	t_scene				*scene;
	t_ray				*ray;

	int					bol_fig_draw;
	int					bol_shadow_draw;
	int					bol_specular_draw;
	int					bol_diffuse_draw;
}						t_rt;

#endif
