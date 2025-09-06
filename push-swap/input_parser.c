/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 20:30:34 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/09/06 17:01:48 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft/libft.h"
#include "push_swap.h"
#include <stdio.h>

int input_err(char *list_item)
{
    int i;

    i = 0;
    while (list_item[i])
    {
        if (!(list_item[i] >= '0' && list_item[i] <= '9'))
            return (1);
        i++;
    }
    return (0);
}

// REQUIRES TESTING:
// int ft_mk_lst_rank()
// {
//     t_circlist  *lst;
    
//     lst->rank = ft_mk_lst_rank();
//     lst->inversions = ;
//     return ();
// }

// REQUIRES TESTING:
t_circlist  *mk_circlst()
{
    t_circlist  *circlst;

    circlst = malloc(sizeof(t_circlist));
    if (!circlst)
        return (NULL);
    return (circlst);
}

// REQUIRES TESTING:
t_stack  *mk_stack(int max_rows_cont, char **rows_cont)
{
    t_stack     *stack;
    t_circlist  *current_node;
    t_circlist  *previous_node;
    int         row;

    stack = malloc(sizeof(t_stack));
    if (!stack)
        return (NULL);
    stack->head = NULL;
    stack->size = 0;
    stack->min = 0;
    stack->max = 0;
    stack->sorted = 0;
    row = 1;
    previous_node = NULL;
    while (row < max_rows_cont)
    {
        current_node = malloc(sizeof(t_circlist));
        if (!current_node)
        {    
            free_err_stack(stack);
            free(previous_node);
            return (NULL);
        }
        current_node->content = ft_atoi(rows_cont[row++]);
        current_node->index = stack->size++;
        current_node->rank = 0;
        current_node->inversions = 0;
        if (!stack->head)
            stack->head = current_node;
        if (row <= max_rows_cont)
        {
            current_node->previous = previous_node;
            if (previous_node)
                previous_node->next = current_node;
            previous_node = current_node;
            if (row == max_rows_cont)
            {
                current_node->next = stack->head;
                stack->head->previous = current_node;
            }
        }
        if (row < max_rows_cont)
            current_node->next = NULL;
        current_node = current_node->next;
    }
    // function for ranks, inversions and stack's min, max and sorted
    return (stack);
}

// REQUIRES TESTING:
t_stack *parser(int ac, char **av) // should it return a pointer?
{
    int     row;
    // t_circlist  *lst_a;
    // t_circlist  *lst_b;
    t_stack *stack_a;
    // t_stack *stack_b;
    
    row = 1;
    while (row < ac)
    {
        if (input_err(av[row++]) == 1)
        {
            write(2, "Error\n", 6);
            exit(EXIT_FAILURE); // yes? or only in main?
        }
    }
    // convert char to long int in linked list and link it all together
    stack_a = mk_stack(ac, av);
    return (stack_a);
}