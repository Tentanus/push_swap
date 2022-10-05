// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        ::::::::            */
// /*   push_swap.c                                        :+:    :+:            */
// /*                                                     +:+                    */
// /*   By: mweverli <mweverli@student.codam.n>          +#+                     */
// /*                                                   +#+                      */
// /*   Created: 2022/10/01 17:59:34 by mweverli      #+#    #+#                 */
// /*   Updated: 2022/10/03 17:56:32 by mweverli      ########   odam.nl         */
// /*                                                                            */
// /* ************************************************************************** */

// #include <push_swap.h>

// int	main(int argc, char **argv)
// {
// 	t_stack	a;
// 	t_stack	b;

// 	if (argc < 1)
// 		return (1);
// 	push_swap_init((argv + 1), --argc, &a, &b);
// 	return (0);
// }

#include <stdio.h>
#include <push_swap.h>
#include <list_utils.h>

void	print_stack(t_stack *stack)
{
	t_node	*node = stack->top;

	while (node)
	{
		printf("%d ", node->i_val);
		node = node->next;
	}
	printf("\n");
}


int	main(void)
{
	t_stack	stack1;
	t_stack	stack2;
	int		test1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	// int		test2[] = {11, 12, 13, 14, 15 ,16,17,18,19};

	stack1.top = NULL;
	stack2.top = NULL;
	for (int i = 9; i; i--)
	{
		t_node *new = malloc(sizeof(t_node));
		new->i_val = test1[i];
		stack_add_front(&stack1, new);
	}
	print_stack(&stack1);
	return (0);
}
