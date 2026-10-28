/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnahid <tnahid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 23:10:40 by tnahid            #+#    #+#             */
/*   Updated: 2026/10/28 23:21:45 by tnahid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	void	*con;
	t_list	*new;
	t_list	*head;

	head = NULL;
	if (!lst || !f)
		return (NULL);
	while (lst)
	{
		con = f(lst->content);
		new = ft_lstnew(con);
		if (!new)
		{
			if (del)
				del(con);
			ft_lstclear(&head, del);
			return (NULL);
		}
		ft_lstadd_back(&head, new);
		lst = lst->next;
	}
	return (head);
}
