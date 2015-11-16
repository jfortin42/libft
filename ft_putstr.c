#include "libft.h"

void	ft_putstr(char const *s)
{
	write(1, s, ft_strlen(s));
}
