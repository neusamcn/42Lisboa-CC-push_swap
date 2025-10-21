/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 15:54:12 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/10/20 11:24:29 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// TESTERS:
void	print_stack(t_stack *stack, char stack_name)
{
	t_circlist	*current;
	t_circlist	*start;

	current = stack->head;
	start = stack->head;
	printf("STACK_%c: %p\n", stack_name, stack);
	printf("head: %p\n", stack->head);
	printf("size: %lu\n", stack->size);
	printf("min: %d\n", stack->min);
	printf("max: %d\n", stack->max);
	printf("sorted: %d\n\n", stack->sorted);
	while (current)
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

	// if (ac < 3)
	// {
	// 	write(2, "Error\n", 6);
	// 	exit(EXIT_FAILURE); // yes? or only in main?
	// }
	stack_a = parser(ac, av);
	stack_b = create_empty_stack();
	// TESTS START
	print_stack(stack_a, 'A');
	printf("><><><><><><><><><><><><><\n");
	print_stack(stack_b, 'B');
	printf("><><><><><><><><><><><><><\n");
	int	max_index = (int)stack_a->size - 1;
	int	moves = inv_algo(stack_a, stack_b, max_index);
	// printf("traverse2tail(stack_a, stack_b) moves = %d\n", moves);
	// printf("sa_or_ss(stack_a, stack_b, moves) moves = %d\n", moves = sa_or_ss(stack_a, stack_b, max_index, moves));
	// printf("traverse2head(stack_a, stack_b, moves) moves = %d\n", traverse2head(stack_a, stack_b, max_index, moves));
	printf("inv_algo(stack_a, stack_b, max_index) moves = %d\n", moves);	
	printf("><><><><><><><><><><><><><\n");
	print_stack(stack_a, 'A');
	printf("><><><><><><><><><><><><><\n");
	print_stack(stack_b, 'B');
	// TESTS END
	free_circlst_stack(stack_a);
	free_circlst_stack(stack_b);
	exit(EXIT_SUCCESS);
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
quick_sort

bucketsort:  how do i make me some buckets?

7 digits visualizer:
https://push-swap42-visualizer.vercel.app/
pb
pb
ra
ra
ra
ss
ra
pa
rra
pa
rra
rra
sa
rra
sa

4 0 1 6 2 5 3
12 instructions:
pb
ra
ra
pb
ra
ss
ra
pa
ra
ra
pa
ra
*/