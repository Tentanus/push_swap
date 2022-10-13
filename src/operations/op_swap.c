/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   op_swap.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/03 14:25:58 by mweverli      #+#    #+#                 */
/*   Updated: 2022/10/13 22:41:06 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <list_utils.h>

void	swap(t_stack *stack)
{
	t_node	*node1;
	t_node	*node2;
	t_node	*node3;
	t_node	*last;

	if (stack->size < 2 && ft_printf("swap: %c->size < 2\n", stack->name))
		return ;
	node1 = stack->top;
	node2 = node1->next;
	node3 = node2->next;
	last = stack_last(stack);
	stack->top = node2;
	node2->next = node1;
	node1->next = node3;
	last->next = node2;
}

void	swapswap(t_stack *stack_1, t_stack *stack_2)
{
	swap(stack_1);
	swap(stack_2);
}

// Take car iwth SWAP it doesn't work with < 3 Items
