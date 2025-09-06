/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 15:54:12 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/09/06 16:38:32 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft/libft.h"
#include "push_swap.h"
#include <stdio.h>

int main(int ac, char **av)
{
    t_stack *stack_a;
    
    if (ac > 1)
    {
        stack_a = parser(ac, av);
    }
    // TESTS START
    printf("STACK_A:\n");
    printf("head: %p\n", stack_a->head);
    printf("size: %lu\n", stack_a->size);
    printf("min: %d\n", stack_a->min);
    printf("max: %d\n", stack_a->max);
    printf("sorted: %d\n\n", stack_a->sorted);

    while(stack_a)
    {
        printf("node: %p\n", stack_a->head);
        printf("content: %d\n", stack_a->head->content);
        printf("index: %d\n", stack_a->head->index);
        printf("rank: %d\n", stack_a->head->rank);
        printf("inversions: %d\n", stack_a->head->inversions);
        printf("previous: %p\n", stack_a->head->previous);
        printf("next: %p\n------------\n\n", stack_a->head->next);
        if ((size_t)stack_a->head->index == stack_a->size - 1)
            break;
        stack_a->head = stack_a->head->next;

    }
    // TESTS END
    free_circlst_stack(stack_a);
    return (0);
}

/* TO-DO:
- STACK STRUCT:
-- len : size of the array;
-- max : highest value;
-- min : lowest value; 

LOCICAL STEPS:
1. normalize input data (add left 0s)
separate negatives from positives - if(a[i] < 0){pb;}
    > stacks a (pos) && b (neg) to join w/ pa() after sort
(maybe) quick sort up to N items (due to speed)
2. radix sort on a && b - bucket by lsd
inverted sort on negative stack - if(sort(a){+>-}){sort(b){->+}}
join positive stack to negative stack - while(b){pa++;}

MAIN MECHANISM:
- the least anmount of operations to sort the given stack as argument
p


peak() to check for each BUILD operation
if(BUILD == RADIX){print("BUILD");} 

BUILD:
sa: swap a
sb: swap b
ss: sa + sb
pa: push a
pb
ra: rotate a
rb
rr: ra + rb
rra: reverse rotate a
rrb
rrr: rra + rrb

bucketsort:  how do i make me some buckets?
*/