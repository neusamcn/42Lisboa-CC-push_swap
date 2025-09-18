/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 15:54:12 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/09/18 22:39:35 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft/libft.h"
#include "push_swap.h"

// TESTER:
void	print_stack(t_stack *stack, char stack_name)
{
	t_circlist	*current;
	t_circlist	*start;

	current = stack->head;
	start = stack->head;
	printf("STACK_%c:\n", stack_name);
	printf("stack_%c: %p\n", stack_name + 32, stack);
	printf("head: %p\n", stack->head);
	printf("size: %lu\n", stack->size);
	printf("min: %d\n", stack->min);
	printf("max: %d\n", stack->max);
	printf("sorted: %d\n\n", stack->sorted);
	while (current != NULL)
	{
		printf("node: %p\n", current);
		printf("content: %d\n", current->content);
		printf("index: %d\n", current->index);
		printf("rank: %d\n", current->rank);
		printf("inversions: %d\n", current->inversions);
		printf("previous: %p\n", current->previous);
		printf("next: %p\n------------\n\n", current->next);
		current = current->next;
		if (current == start)
			break ;
	}
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac < 3)
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE); // yes? or only in main?
	}
	stack_a = parser(ac, av);
	stack_b = create_empty_stack();
	// TESTS START
	print_stack(stack_a, 'A');
	printf("><><><><><><><><><><><><><\n");
	print_stack(stack_b, 'B');
	printf("><><><><><><><><><><><><><\n");
	printf("pb(stack_a, stack_b) = %d\n", pb(stack_a, stack_b));
	printf("><><><><><><><><><><><><><\n");
	print_stack(stack_a, 'A');
	printf("><><><><><><><><><><><><><\n");
	print_stack(stack_b, 'B');
	// TESTS END
	free_circlst_stack(stack_a);
	free_circlst_stack(stack_b);
	return (0);
}

/* TO-DO:

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

push() to insert an element into the stack.
pop() to remove an element from the stack.
top() Returns the top element of the stack.
isEmpty() returns true if stack is empty else false.

peak() to check for each BUILD operation
if(BUILD == RADIX){print("BUILD");}

BUILD:
sa: swap a
sb: swap b
pa: push a
pb
ra: rotate a
rb
rra: reverse rotate a
rrb

bucketsort:  how do i make me some buckets?
*/