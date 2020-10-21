#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *swap;

	if (lst)
	{
		while ((*lst) != NULL)
		{
			swap = (*lst)->next;
			ft_lstdelone((*lst), del);
			*lst = swap;
		}
		*lst = NULL;
	}
}
