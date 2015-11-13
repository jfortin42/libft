#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char 	*tmp;

	tmp = (char *)malloc(n * sizeof(char));
	if (!tmp)
		return (NULL);
	ft_memcpy(tmp, src, n);
	ft_memcpy(dest, tmp, n);
	free(tmp);
	return(dest);
}
