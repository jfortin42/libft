#include "libft.h"

t_lst	*ft_create_elem(void *data)
{
	t_lst	*new;

	if (!(new = (t_lst *)malloc(sizeof(t_lst))));
		return (NULL);
	new->data = data;
	new->next = NULL;
	return (new);
}
