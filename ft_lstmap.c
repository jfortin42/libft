#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newlist;

	if (lst && f)
	{
		newlist = f(lst);
		if (newlist && lst->next)
			newlist->next = ft_lstmap(lst->next, f);
		return (newlist);
	}
	return (NULL);
}
