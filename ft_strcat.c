#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	unsigned int	i;

	i = 0;
	while (src[i])
	{
		dest[i + ft_strlen(dest)] = src[i];
		i++;
	}
	return (dest);
}
