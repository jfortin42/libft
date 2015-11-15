#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*m;

	m = malloc(size * sizeof(size_t));
	if (!m)
		return (NULL);
	return (ft_bzero(m, size));
}
