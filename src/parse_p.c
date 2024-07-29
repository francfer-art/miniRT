#include <minirt.h>

int	validate_plane(t_plane *pl)
{
	if (pl->id == NULL || ft_strcmp(pl->id, "pl") != 0)
	{
		ft_printf("Error: ID must be 'sp'.\n");
		return (0);
	}
	return (1);
}

t_plane	*parse_plane(char *tokens)
{
	t_plane	*pl;
    char	**token;

    pl = malloc(sizeof(t_plane));
	if (!pl)
		return (NULL);
	token = ft_split(tokens, ' ');
	if (!token)
		return (NULL);
	if (word_counter(tokens, ' ') != 4)
		return (NULL);
	pl->id = strdup(token[0]);
	if (!parse_coordinates(token[1], &pl->x, &pl->y, &pl->z))
        return (NULL);
	pl->orientation_v = parse_vector(token[2]);
	pl->color = get_color(token[3]);
	ft_putstr_fd("LLego\n", 1);
	if (!validate_plane(pl))
		return (NULL);
	return (pl);
}