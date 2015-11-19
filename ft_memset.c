#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char *str;

	str = (char *)s;
	while (n)
	{
		str[n - 1] = c;
		n--;
	}
	return (s);
}
