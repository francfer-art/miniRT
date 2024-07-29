#include <minirt.h>

char	**read_map(char *file)
{
	char	*line;
	char	*new_temp;
	char	*temp;
	int		fd;
	char	**map;

	temp = ft_strdup("");
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("File doesnt exist\n");
		exit(1);
	}
	line = get_next_line(fd);
	while (line)
	{
		new_temp = ft_strjoin(temp, line);
		free(temp);
		temp = new_temp;
		free(line);
		line = get_next_line(fd);
	}
	map = ft_split(new_temp, '\n');
	return (map);
}
/* t_obj	*add_object(char *tokens)
{
	char	**token;
	
	token = ft_split(tokens, ' ');
	if (!token)
		return (NULL);
	// Determina el tipo de objeto y lo parsea
	if (strcmp(tokens[0], "A") == 0)
	{
		return ((void *)parse_a_lightning(tokens));
	}
	else if (strcmp(tokens[0], "C") == 0)
	{
		return ((void *)parse_camera(tokens));
	}
	else if (strcmp(tokens[0], "L") == 0)
	{
		return ((void *)parse_light(tokens));
	}
	else if (strcmp(tokens[0], "sp") == 0)
	{
		return ((void *)parse_sphere(tokens));
	}
	else if (strcmp(tokens[0], "pl") == 0)
	{
		return ((void *)parse_plane(tokens));
	}
	else if (strcmp(tokens[0], "cy") == 0)
	{
		return ((void *)parse_cylinder(tokens));
	}
	else
	{
		return (NULL);
	}
} */
int	main(int args, char **argv)
{
	char		**map;
	t_camera	*cam;
	t_light		*light;
	t_sphere	*sp;
	t_plane		*pl;
	t_cylinder	*cy;

	map = NULL;
	if (args != 2)
		return (printf("Wrong number of arguments!\n"), 0);
	if (ft_strlen(argv[1]) < 3 || ft_strcmp(&argv[1][ft_strlen(argv[1]) - 3],
			".rt") != 0)
		return (printf("Wrong format file!\n Only .rt is allowed\n"), 0);
	map = read_map(argv[1]);
	cam = parse_camera(map[0]);
	if (cam)
	{
		printf("ID: %s\n", cam->id);
		printf("COORDENADAS: %lf   %lf   %lf\n", cam->x, cam->y, cam->z);
		printf("VECTOR: %lf   %lf   %lf\n", cam->orientation_v.x,
			cam->orientation_v.y, cam->orientation_v.z);
		printf("FOV: %d\n", cam->fov);
	}
	light = parse_light(map[1]);
	if (light)
	{
		printf("ID: %s\n", light->id);
		printf("COORDENADAS: %lf   %lf   %lf\n", light->x, light->y, light->z);
		printf("BRIGHTNESS: %lf\n", light->brightness);
		printf("COLOR: %u\n", light->color);
	}
	sp = parse_sphere(map[2]);
	if (sp)
	{
		printf("ID: %s\n", sp->id);
		printf("COORDENADAS: %lf   %lf   %lf\n", sp->x, sp->y, sp->z);
		printf("DIAMETER: %lf\n", sp->diameter);
		printf("COLOR: %u\n", sp->color);
	}
	pl = parse_plane(map[3]);
	if (pl)
	{
		printf("ID: %s\n", pl->id);
		printf("COORDENADAS: %lf   %lf   %lf\n", pl->x, pl->y, pl->z);
		printf("VECTOR: %lf   %lf   %lf\n", pl->orientation_v.x,
			pl->orientation_v.y, pl->orientation_v.z);
		printf("COLOR: %u\n", sp->color);
	}
	cy = parse_cylinder(map[4]);
	if (cy)
	{
		printf("ID: %s\n", cy->id);
		printf("COORDENADAS: %lf   %lf   %lf\n", cy->x, cy->y, cy->z);
		printf("VECTOR: %lf   %lf   %lf\n", cy->orientation_v.x,
			cy->orientation_v.y, cy->orientation_v.z);
		printf("DIAMETER: %lf\n", cy->diameter);
		printf("HEIGHT: %lf\n", cy->height);
		printf("COLOR: %u\n", cy->color);
	}
}
