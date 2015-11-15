#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!s1[0] && !s2[0] && !n)
		return ((char *)s1);
	while (s1[i] && i < n)
	{
		j = 0;
		while (s1[i + j] == s2[j] && s2[j] && i < n)
			j++;
		if (s2[j] == '\0')
			return ((char *)s1 + i);
		i++;
	}
	return (NULL);
}
