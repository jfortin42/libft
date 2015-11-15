#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	unsigned int	i;
	size_t			dest_len;

	i = 0;
	dest_len = ft_strlen(dest);
	while (src[i])
	{
		dest[i + dest_len] = src[i];
		i++;
	}
	dest[i + dest_len] = '\0'
	return (dest);
}
