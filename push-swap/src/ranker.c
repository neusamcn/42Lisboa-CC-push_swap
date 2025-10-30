/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ranker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 20:19:12 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/10/30 15:13:29 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../include/push_swap.h"

// REQUIRES TESTING:
int rank(t_stack *stack)
{
    t_circlist  *current;
    t_circlist  *start;
    int         max;
    int         rank;

    if (!stack || !stack->head)
        return (-1);
    max = stack->max;
    current = stack->head;
    start = current->previous;
    // 1st => rank == 0:
    rank = (int)stack->size - 1;
    while (max >= stack->min && rank >= 0)
    {
        if (current->content == max)
        {
            current->rank = rank;
            rank--;
            start = current->previous;
        }
        if (current == start)
            max--;
        current = current->next;
    }
    if (rank != -1)
        return (-1);
    return (0);
}
