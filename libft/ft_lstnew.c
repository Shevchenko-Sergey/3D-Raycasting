#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *head;

	head = malloc(sizeof(t_list));
	if (head)
	{
		head->next = NULL;
		head->content = content;
	}
	return (head);
}
