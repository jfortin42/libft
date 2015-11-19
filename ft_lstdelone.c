#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	if (del && alst)
	{
		del((**alst).content, (**alst).content_size);
		free((**alst).content);
		*alst = NULL;
	}
}
