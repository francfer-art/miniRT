#include <minirt.h>

int	validate_cylinder(t_cylinder *cy)
{
	if (cy->id == NULL || ft_strcmp(cy->id, "cy") != 0)
	{
		ft_printf("Error: ID must be 'cy'.\n");
		return (0);
	}
	return (1);
}

t_cylinder	*parse_cylinder(char *tokens)
{
	t_cylinder *cy;
	char **token;

	cy = malloc(sizeof(t_cylinder));
	if (!cy)
		return (NULL);
	token = ft_split(tokens, ' ');
	if (!token)
		return (NULL);
	if (word_counter(tokens, ' ') != 6)
		return (NULL);
	cy->id = ft_strdup(token[0]);
	if (!parse_coordinates(token[1], &cy->x, &cy->y, &cy->z))
		return (NULL);
	cy->orientation_v = parse_vector(token[2]);
	if (!is_valid_number2(token[3]) || !is_valid_number2(token[4]))
		return (NULL);
	cy->diameter = atof(token[3]);
	cy->height = atof(token[4]);
	cy->color = get_color(token[5]);
	if (!validate_cylinder(cy))
		return (NULL);
	return (cy);
}