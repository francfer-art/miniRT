#include <minirt.h>

int	validate_sphere(t_sphere *sp)
{
	if (sp->id == NULL || ft_strcmp(sp->id, "sp") != 0)
	{
		ft_printf("Error: ID must be 'sp'.\n");
		return (0);
	}
	return (1);
}

t_sphere	*parse_sphere(char *tokens)
{
	t_sphere	*sp;
    char		**token;

    sp = malloc(sizeof(t_sphere));
	if (!sp)
		return (NULL);
	token = ft_split(tokens, ' ');
	if (!token)
		return(NULL);
	if (word_counter(tokens, ' ') != 4)
		return (NULL);
	sp->id = ft_strdup(token[0]);
	if (!parse_coordinates(token[1], &sp->x, &sp->y, &sp->z))
        return (NULL);
	if (!is_valid_number2(token[2]))
		return (NULL);
	sp->diameter = atof(token[2]);
	sp->color = get_color(token[3]);
	if (!validate_sphere(sp))
		return (NULL);
	return (sp);
}