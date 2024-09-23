#include "libft.h"

void ft_lstadd_back(t_list **lst, t_list *new) {
	t_list *last;

	if (lst && new) {
		last = ft_lstlast(*lst);
		if (!last)
			*lst = new;
		else
			last->next = new;
	}
}

#include <stdio.h>

void print_list(t_list *lst) {
	while (lst) {
		printf("%s -> ", (char *)lst->content);
		lst = lst->next;
	}
	printf("NULL\n");
}

int main() {
	t_list *list = NULL;

	// Create new nodes
	t_list *node1 = ft_lstnew("Node 1");
	t_list *node2 = ft_lstnew("Node 2");
	t_list *node3 = ft_lstnew("Node 3");

	// Add nodes to the list
	ft_lstadd_back(&list, node1);
	ft_lstadd_back(&list, node2);
	ft_lstadd_back(&list, node3);

	// Print the list to verify
	print_list(list);

	return 0;
}