#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char			*str1;
	char			*str2;
	unsigned int	i;

	str1 = (char *)s1;
	str2 = (char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (str1[i] == str2[i] && str1[i] && i < n)
		i++;
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}
