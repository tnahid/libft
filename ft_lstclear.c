#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	if ((*lst)->next == NULL)
	{
		ft_lstdelone(*lst, del);
		return ;
	}
	ft_lstclear(&(*lst)->next, del);
}

void	del_fun(void *content)
{
	free(content);
}

int main()
{
	t_list **lst;

	*lst = ft_lstnew(NULL);
	char *a = ft_strdup("taha");
	char *b = ft_strdup(" na");
	char *c = ft_strdup("hid");
	t_list *a1 = ft_lstnew(a);
	t_list *b1 = ft_lstnew(b);
	t_list *c1 = ft_lstnew(c);
	printf("s1 = %d\n", ft_lstsize(*lst));
	ft_lstadd_back(lst, a1);
	printf("s2 = %d\n", ft_lstsize(*lst));
	ft_lstadd_back(lst, b1);
	printf("s3 = %d\n", ft_lstsize(*lst));
	ft_lstadd_back(lst, c1);
	printf("s4 = %d\n", ft_lstsize(*lst));
	ft_lstclear(lst, del_fun);
	printf("s5 = %d\n", ft_lstsize(*lst));
}

