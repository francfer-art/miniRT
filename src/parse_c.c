#include <minirt.h>

int is_valid_number2(const char *str) {
    // Verificar que la cadena no esté vacía
    if (*str == '\0') {
        return 0;
    }

    // Si el primer carácter es un signo, avanzar al siguiente carácter
    if (*str == '+' || *str == '-') {
        str++;
    }

    // Verificar que al menos haya un dígito después del signo
    if (*str == '\0') {
        return 0;
    }

    int has_digits = 0;   // Indica si se han encontrado dígitos
    int has_decimal = 0;  // Indica si se ha encontrado un punto decimal

    // Verificar que los caracteres sean dígitos o un único punto decimal
    while (*str) {
        if (*str >= '0' && *str <= '9') {
            has_digits = 1; // Encontramos un dígito
        } else if (*str == '.') {
            // Si ya hay un punto decimal, el número no es válido
            if (has_decimal) {
                return 0;
            }
            has_decimal = 1; // Marcar que se encontró un punto decimal
            // Debe haber al menos un dígito antes del punto decimal
            if (!has_digits) {
                return 0;
            }
            // Restablecer has_digits para verificar al menos un dígito después del punto
            has_digits = 0;
        } else {
            // Si encontramos un carácter que no es ni dígito ni punto, no es válido
            return 0;
        }
        str++;
    }

    // Para ser válido, debe haber al menos un dígito al final
    return has_digits;
}

int	parse_coordinates(char *coords_str, double *x, double *y, double *z)
{
	char	*token;
	double	coords[3];
	int		i;

	i = 0;
	// Dividir la cadena usando comas como delimitadores
	token = ft_strtok(coords_str, ",");
	while (token != NULL)
	{
		if (i >= 3)
		{
			ft_printf("Error: Too many components in input string.\n");
			return (0);
		}
		if (is_valid_number2(token))
		{
			coords[i] = atof(token);
			token = ft_strtok(NULL, ",");
			i++;
		}
		else
			exit (1);
	}
	// Verificar que se hayan obtenido exactamente tres componentes
	if (i != 3)
	{
		ft_printf("Error: Insufficient components in input string.\n");
		return (0);
	}
	// Asignar los valores a las variables pasadas por referencia
	*x = coords[0];
	*y = coords[1];
	*z = coords[2];
	return (1); // Retornar 1 para indicar éxito
}
t_vector	parse_vector(char *str)
{
	t_vector	vec;

	parse_coordinates(str, &vec.x, &vec.y, &vec.z);
	return (vec);
}

int	validate_camera(t_camera *camera)
{
	if (camera->id == NULL || ft_strcmp(camera->id,"C") != 0)
	{
		ft_printf("Error: ID must be 'C'.\n");
		return (0);
	}
	if (camera->orientation_v.x < -1.0 || camera->orientation_v.x > 1.0
		|| camera->orientation_v.y < -1.0 || camera->orientation_v.y > 1.0
		|| camera->orientation_v.z < -1.0 || camera->orientation_v.z > 1.0)
	{
		ft_printf("Error: Orientation vector components must be in the range [-1,1].\n");
		return (0);
	}
	if (camera->fov < 0 || camera->fov > 180)
	{
		ft_printf("Error: FOV must be in the range [0, 180].\n");
		return (0);
	}
	return (1);
}
int	word_counter(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
		{
			i++;
		}
		if (s[i] != c && s[i])
		{
			j++;
		}
		while (s[i] != c && s[i])
		{
			i++;
		}
	}
	return (j);
}

t_camera	*parse_camera(char *tokens)
{
	t_camera *cam;
	char **token;
	cam = malloc(sizeof(t_camera));
	if (!cam)
		return (NULL);
	token = ft_split(tokens, ' ');
	if (word_counter(tokens, ' ') != 4)
		return(NULL);
	cam->id = ft_strdup(token[0]);
	parse_coordinates(token[1], &cam->x, &cam->y, &cam->z);
	cam->orientation_v = parse_vector(token[2]);
	if (!is_valid_number2(token[3]))
		return (NULL);
	cam->fov = ft_atoi(token[3]);
	if (!validate_camera(cam))
		return (NULL);
	return (cam);
}