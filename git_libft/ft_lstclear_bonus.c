#include "libft.h"

void ft_lstclear(t_list **lst) {
	t_list *current;
	t_list *next;

	if (lst) {
		current = *lst;
		while (current) {
			next = current->next;
			free(current);
			current = next;
		}
		*lst = NULL;
	}
}