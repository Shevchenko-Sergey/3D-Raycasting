#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list *current;

	current = lst;
	if (lst)
	{
		f(lst->content);
		while (current->next != NULL)
		{
			current = current->next;
			f(current->content);
		}
	}
}
