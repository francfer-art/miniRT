#include <minirt.h>

void    v_normalize(t_vector **vector)
{
    double  len;

    len = vector_len(*vector);
    (*vector)->x /= len;
    (*vector)->x /= len;
    (*vector)->x /= len;
}

double	vector_len(t_vector *vector)
{
	double	len;

	len = vector_len2(vector);
	if (len == 0)
		return (1);
	return (sqrt(len));
}
double	sqr(double num)
{
	return (num * num);
}

double	vector_len2(t_vector *vector)
{
	return (sqr(vector->x) + sqr(vector->y) + sqr(vector->z));
}

t_vector	vector_sum(t_vector *v1, t_vector *v2)
{
	t_vector	v3;

	v3.x = v1->x + v2->x;
	v3.y = v1->y + v2->y;
	v3.z = v1->z + v2->z;
	return (v3);
}

t_vector	vector_minus(t_vector *v1, t_vector *v2)
{
	t_vector	v3;

	v3.x = v1->x - v2->x;
	v3.y = v1->y - v2->y;
	v3.z = v1->z - v2->z;
	return (v3);
}

t_vector	vector_mult(t_vector *v1, float a)
{
	t_vector	v3;

	v3.x = v1->x * a;
	v3.y = v1->y * a;
	v3.z = v1->z * a;
	return (v3);
}

t_vector	vector_div(t_vector *v1, t_vector *v2)
{
	v1->x /= v2->x;
	v1->y /= v2->y;
	v1->z /= v2->z;
	return (*v1);
}

double	vector_mult(t_vector *v1, t_vector *v2)
{
	double res;

	return (v1->x * v2->x + v1->y * v2->y + v1->z * v2->z);
}

t_vector    vector_cross(t_vector *v1, t_vector *v2)
{
    t_vector    v3;

    v3.x = v1->y * v2->z - v1->z * v2->y;
    v3.y = v1->z * v2->x - v1->x * v2->z;
    v3.z = v1->x * v2->y - v1->y * v2->x;
    return(v3);
}