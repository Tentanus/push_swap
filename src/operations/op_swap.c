/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   op_swap.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/03 14:25:58 by mweverli      #+#    #+#                 */
/*   Updated: 2022/10/03 15:42:26 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	swap(t_stack *stack)
{
	t_node	*tmp;

	tmp = *(stack->top);


	node1 = *(stack->top);
	node2 = node1->next;
	node1->next = node2->next;
	node2->next = &node1;
	*(stack->top) = &node2;
}

void	swapswap(t_stack *stack_1, t_stack *stack_2)
{
	swap(stack_1);
	swap(stack_2);
}
