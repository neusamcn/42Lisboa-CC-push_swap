This project has been created as part of the 42 curriculum by ncruz-ne.

Description
The push_swap project is an algorithmic challenge: a set of integer values is provided as argument(s) for the created C program that must sort them in ascending order in stack a while only using a set of instructions that manipulate both stacks a and b.

Instructions to manipulate stacks:
sa (swap a): Swap the first 2 elements at the top of stack a. Do nothing if there is only one element or none.
sb (swap b): Swap the first 2 elements at the top of stack b. Do nothing if there is only one element or none.
ss : sa and sb at the same time.
pa (push a): Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
pb (push b): Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
ra (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one.
rb (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.
rr : ra and rb at the same time.
rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.
rrb (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.
rrr : rra and rrb at the same time.

Benchmarks:
• For maximum project validation (100%) and eligibility for bonuses:
◦ Sort 100 random numbers in fewer than 700 operations.
◦ Sort 500 random numbers in no more than 5500 operations.
• For minimal project validation (which implies a minimum grade of 80%), success can be obtained with different averages:
◦ 100 numbers in under 1100 operations and 500 numbers in under
8500 operations
◦ 100 numbers in under 700 operations and 500 numbers in under
11500 operations
◦ 100 numbers in under 1300 operations and 500 numbers in under
5500 operations


Instructions
This project can be compiled in 2 ways:
1. for debugging: make debug
2. for defense: make all

The debugging option will compile the project in a TEST directory as push_swap_db.
This file is optimised for debugging, which can be verified through the Makefile.

To delete all debugging and testing files use make tclean.
To delete the main program, library and all associated object files use make fclean.


Resources
[radix video]