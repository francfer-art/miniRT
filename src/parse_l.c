#include <minirt.h>

int	validate_light(t_light *light)
{
	if (light->id == NULL || ft_strcmp(light->id, "L") != 0)
	{
		ft_printf("Error: ID must be 'L'.\n");
		return (0);
	}
	if (light->brightness < 0.0 || light->brightness > 1.0)
	{
		printf("Error: Brigtness must be between 0 and 1.\n");
		return (0);
	}
	return (1);
}

t_light	*parse_light(char *tokens)
{
	t_light *light;
	char **token;

	token = ft_split(tokens, ' ');
	if (!token)
		return (NULL);
	light = malloc(sizeof(t_light));
	if (!light)
		return (NULL);
	if (word_counter(tokens, ' ') != 4)
		return (NULL);
	light->id = strdup(token[0]);
	if (!parse_coordinates(token[1], &light->x, &light->y, &light->z))
		return (NULL);
	if (!is_valid_number2(token[2]))
		return (NULL);
	light->brightness = atof(token[2]);
	light->color = get_color(token[3]);
	if (!validate_light(light))
		return (NULL);
	return (light);
}