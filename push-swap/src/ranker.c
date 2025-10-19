/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ranker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 20:19:12 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/10/19 21:11:00 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int rank(t_stack *stack)
{
    t_circlist  *current;
    int         max;
    int         rank;

    if (!stack || !stack->head)
        return (-1);
    max = stack->max;
    current = stack->head;
    // 1st => rank == 0:
    rank = (int)stack->size - 1;
    while (current && rank >= 0)
    {
        if (current->content == max)
        {
            current->rank = rank;
            max--;
            rank--;
        }
        current = current->next;
    }
    if (rank != -1 || max != stack->min - 1)
        return (-1);
    return (0);
}
