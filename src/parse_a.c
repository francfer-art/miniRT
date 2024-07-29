#include <minirt.h>

unsigned int	get_rgba(int r, int g, int b)
{
	return (r << 24 | g << 16 | b << 8 | 255);
}

// Helper function to check if a string is a valid integer
int	is_valid_number(const char *str)
{
	// Check if the string is not empty and all characters are digits
	if (*str == '\0')
		return (0);
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
		{
			return (0);
		}
		str++;
	}
	return (1);
}

// Function to get color from a comma-separated string
int	get_color(char *color)
{
	char	*token;
	int		rgb[3];
	int		i;

	i = 0;
	// Use strtok to split the string by commas
	token = ft_strtok(color, ",");
	while (token != NULL)
	{
		// Ensure that we have exactly three components
		if (i >= 3)
		{
			ft_printf("Error: Too many components in input string.\n");
			exit (1);
		}
		// Validate and convert each component
		if (is_valid_number(token))
		{
			rgb[i] = ft_atoi(token);
			if (rgb[i] < 0 || rgb[i] > 255)
			{
				ft_printf("Error: Color component%d is out of range (0-255).\n",
					rgb[i]);
				exit(1);
			}
		}
		else
		{
			ft_printf("Error: Invalid number '%s'.\n", token);
			exit(1);
		}
		// Get the next token
		token = ft_strtok(NULL, ",");
		i++;
	}
	// Check if we have exactly three components
	if (i != 3)
	{
		ft_printf("Error: Insufficient components in input string.\n");
		return (-1);
	}
	// Get and return the RGBA value
	return (get_rgba(rgb[0], rgb[1], rgb[2]));
}

int	validate_a_lightning(t_a_lightning *lightning)
{
	// Check if the first character of id is 'A'
	if (lightning->id == NULL || ft_strcmp(lightning->id, "A") != 0)
	{
		printf("Error: ID must start with 'A'.\n");
		return (0);
	}
	// Check if the ratio is between 0 and 1 (inclusive)
	if (lightning->ratio < 0.0 || lightning->ratio > 1.0)
	{
		printf("Error: Ratio must be between 0 and 1.\n");
		return (0);
	}
	// Check if color is not -1
	if (lightning->color == -1)
	{
		printf("Error: Color must not be -1.\n");
		return (0);
	}
	// All checks passed
	return (1);
}

t_a_lightning	*parse_a_lightning(char *tokens)
{
	char			**token;
	t_a_lightning	*al;

	token = ft_split(tokens, ' ');
	if (!token)
		return (NULL);
	al = malloc(sizeof(t_a_lightning));
	if (!al)
		return (NULL);
	if (word_counter(tokens, ' ') != 3)
		return (NULL);
	al->id = ft_strdup(token[0]);
	al->ratio = atof(token[1]);
	al->color = get_color(token[2]);
	if (!validate_a_lightning(al))
		return (NULL);
	return (al);
}