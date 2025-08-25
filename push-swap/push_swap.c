/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 15:54:12 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/08/25 01:10:31 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"
#include <stdio.h>

int input_err(int list_item)
{
    
}

// HOW TO RECEIVE DATA AND INTERPRET IT INTO MY LIST
int main(int ac, char **av)
{
    int i_av;
    i_av = 1;
    if(ac > 1)
    {
        while(i_av < ac)
        {
            if(input_err(av[i_av]) == 1)
            {
                write(2, "Error\n", 6);
                exit(1) ; // yes?
            }
            i_av++;
        }
    }
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
the least anmount of operations to sort the given stack as argument


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