#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	void	*con;
	t_list	*new;
	t_list	*head;

	head = NULL;
	if (!lst || !del || !f)
		return (NULL);
	while (lst)
	{
		con = f(lst->content);
		new = ft_lstnew(con);
		if (!new)
		{
			del(con);
			ft_lstclear(&head, del);
			return (NULL);
		}
		ft_lstadd_back(&head, new);
		lst = lst->next;
	}
	return (head);
}
