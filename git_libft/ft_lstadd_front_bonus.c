
#include "libft.h"

void ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}
/* 
#include <stdio.h>

void print_lst(t_list *lst)
{
	while (lst)
	{
		printf("%s -> ", (char *)lst->content);
		lst = lst->next;
	}
	printf("NULL\n");
}

static void del(void *content)
{
	free(content);
}

int main()
{
	t_list *node1 = ft_lstnew(ft_strdup("4"));
	node1->next = ft_lstnew(ft_strdup("2"));
	node1->next->next = ft_lstnew(ft_strdup("21"));

	print_lst(node1);

	t_list *node2 = ft_lstnew(ft_strdup("node2"));
	ft_lstadd_front(&node1, node2);

	print_lst(node1);

	ft_lstclear(&node1, &del);
	return 0;
} */