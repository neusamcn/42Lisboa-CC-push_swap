/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 16:45:34 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/07/26 21:13:51 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
    t_list  *current;

    while (*begin_list)
    {
        if (cmp(data_ref, (*begin_list)->data) == 0)
        {
            current = (*begin_list)->next;
            free((*begin_list)->data);
            free(*begin_list);
            (*begin_list) = current;
        }
        begin_list = (*begin_list)->next;
    }
}
// FOR TESTING ONLY:
int *cmp(void *data_ref, void *data_lst)
{

    if (*data_lst == *data_ref)
        return (0);
    return (1);
}

int main()
{
    t_list *lst1;

    
    return (0);
}