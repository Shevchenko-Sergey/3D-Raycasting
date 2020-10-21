#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*current;

	if (!lst)
		return (NULL);
	new_list = ft_lstnew(f(lst->content));
	if (!(new_list))
	{
		return (NULL);
	}
	current = new_list;
	while (lst->next != NULL)
	{
		lst = lst->next;
		current = current->next;
		current = ft_lstnew(f(lst->content));
		if (!(current))
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, current);
	}
	return (new_list);
}
