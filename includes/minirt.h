#ifndef MINIRT_H
# define MINIRT_H

# include <fcntl.h>
# include <libft.h>
# include <math.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include "../lib/MLX42/include/MLX42/MLX42.h"

typedef struct s_vector
{
	double			x;
	double			y;
	double			z;
}					t_vector;

typedef struct s_a_lightning
{
	char			*id;
	double			ratio;
	int				color;
}					t_a_lightning;

typedef struct s_camera
{
	char			*id;
	double			x;
	double			y;
	double			z;
	t_vector		orientation_v;
	int				fov;
}					t_camera;

typedef struct s_light
{
	char			*id;
	double			x;
	double			y;
	double			z;
	double			brightness;
	int				color;
}					t_light;

typedef struct s_sphere
{
	char			*id;
	double			x;
	double			y;
	double			z;
	double			diameter;
	int				color;
}					t_sphere;

typedef struct s_plane
{
	char			*id;
	double			x;
	double			y;
	double			z;
	t_vector		orientation_v;
	int				color;
}					t_plane;

typedef struct s_cylinder
{
	char			*id;
	double			x;
	double			y;
	double			z;
	t_vector		orientation_v;
	double			diameter;
	double			height;
	int				color;
}					t_cylinder;

typedef struct s_obj
{
	char			*type;
	void			*obj;
}					t_obj;

typedef struct s_objs
{
	t_obj			*obj;
	struct s_objs	*next;
}					t_objs;

// PARSE_A.c
unsigned int		get_rgba(int r, int g, int b);
int					is_valid_number(const char *str);
int					get_color(char *color);
t_a_lightning		*parse_a_lightning(char *tokens);

// PARSE_C.c
int					parse_coordinates(char *coords_str, double *x, double *y,
						double *z);
t_vector			parse_vector(char *str);
t_camera			*parse_camera(char *tokens);
int					word_counter(char const *s, char c);
int					is_valid_number2(const char *str);

// PARSE_L.c
t_light				*parse_light(char *tokens);
int					validate_light(t_light *light);

// PARSE_S.c
int					validate_sphere(t_sphere *sp);
t_sphere			*parse_sphere(char *tokens);

// PARSE_P.c
int					validate_plane(t_plane *pl);
t_plane				*parse_plane(char *tokens);

// PARSE_CY.c
int					validate_cylinder(t_cylinder *cy);
t_cylinder			*parse_cylinder(char *tokens);

#endif
