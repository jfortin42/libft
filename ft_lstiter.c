#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	if (f)
	{
		while (lst->next)
		{
			f(lst);
			lst = lst->next;
		}
	}
}
