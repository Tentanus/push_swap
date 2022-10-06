/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   op_swap.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/03 14:25:58 by mweverli      #+#    #+#                 */
/*   Updated: 2022/10/06 12:09:01 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	swap(t_stack *stack)
{
	t_node	*node1;
	t_node	*node2;
	t_node	*node3;

	node1 = stack->top;
	node2 = node1->next;
	node3 = node2->next;
	stack->top = node2;
	node2->next = node1;
	node1->next = node3;
}

void	swapswap(t_stack *stack_1, t_stack *stack_2)
{
	swap(stack_1);
	swap(stack_2);
}
