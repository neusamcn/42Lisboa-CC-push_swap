#include "ft_list.h"

void    ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
    while (begin_list)
    {
        f(begin_list->data);
        begin_list = begin_list->next;
    }
}

// // FOR TESTING ONLY:
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// // OPTION 1: Function to print a string (used with ft_list_foreach)
// void print_str(void *data)
// {
//     printf("%s\n", (char *)data);
// }

// // OPTION 2: Funtion to print int numbers
// void    print_int(void *data)
// {
//     printf("%d\n", *(int *)data);
// }

// // Helper function to create a new list node (from Libft)
// t_list	*ft_lstnew(void *data)
// {
// 	t_list	*node;

// 	node = malloc(sizeof(t_list));
// 	if (!node)
// 		return (NULL);
// 	node->data = data;
// 	node->next = NULL;
// 	return (node);
// }

// int main(void)
// {
//     // TESTING WITH STRINGS
//     // Creating 3 nodes for print_str
//     t_list *node1 = ft_lstnew(strdup("Hello"));
//     t_list *node2 = ft_lstnew(strdup("World"));
//     t_list *node3 = ft_lstnew(strdup("!"));

//     // Linking them
//     node1->next = node2;
//     node2->next = node3;

//     // Using ft_list_foreach to print each string
//     ft_list_foreach(node1, print_str);

//     // Free memory
//     free(node1->data); free(node1);
//     free(node2->data); free(node2);
//     free(node3->data); free(node3);


//     // TESTING WITH INT
//     // Allocate memory for integers
//     int *a = malloc(sizeof(int));
//     int *b = malloc(sizeof(int));
//     int *c = malloc(sizeof(int));

//     *a = 1;
//     *b = 2;
//     *c = 3;
    
//     // Creating 3 nodes for print_int
//     t_list  *node4 = ft_lstnew(a);
//     t_list  *node5 = ft_lstnew(b);
//     t_list  *node6 = ft_lstnew(c);

//     // Linking them
//     node4->next = node5;
//     node5->next = node6;

//     // Using ft_list_foreach to print each int
//     ft_list_foreach(node4, print_int);

//     // Free memory
//     free(a); free(node4);
//     free(b); free(node5);
//     free(c); free(node6);

//     return 0;
// }
