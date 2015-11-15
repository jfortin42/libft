#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;

	i = ft_strlen(s) - 1;
	while (i >= 0)
	{
		if (s[i] == c)
			return ((char *)s + i);
		i--;
	}
	if (!c && !s[0])
		return ((char *)s);
	return (NULL);
}
