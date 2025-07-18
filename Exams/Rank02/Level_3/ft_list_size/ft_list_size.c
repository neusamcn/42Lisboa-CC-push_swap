
#include "ft_list_size.h"

int	ft_list_size(t_list *begin_list)
{
	t_list		*current;
	int	len;

	current = begin_list;
	len = 0;
	while (current != 0)
	{
		current = begin_list->next;
		len++;
	}
	return (len);
}
