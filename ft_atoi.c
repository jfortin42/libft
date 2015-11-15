#include "libft.h"

int	ft_atoi(const char *nptr)
{
	unsigned int	i;
	long			nbr;
	long			sign;

	i = 0;
	nbr = 0;
	sign = 1;
	while (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\n'
			|| nptr[i] == '\r' || nptr[i] == '\v' || nptr[i] == '\f')
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i++] == '-')
			sign = -1;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nbr = nbr * 10 + nptr[i] - '0';
		i++;
	}
	return ((int)(nbr * sign));
}
