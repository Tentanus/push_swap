/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   op_swap.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/03 14:25:58 by mweverli      #+#    #+#                 */
/*   Updated: 2022/10/17 16:59:27 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <list_utils.h>

void	swap(t_stack *stk, int v)
{
	t_node	*node1;
	t_node	*node2;
	t_node	*last;

	if (stk->size < 2 && ft_printf("swap: %c->size < 2\n", stk->name))
		return ;
	if (v)
		ft_printf("s%c\n", stk->name);
	if (stk->size == 2)
	{
		stk->top = stk->top->next;
		return ;
	}
	node1 = stk->top;
	node2 = node1->next;
	last = stack_last(stk);
	stk->top = node2;
	node1->next = node2->next;
	node2->next = node1;
	last->next = node2;
}

void	swapswap(t_stack *stk_1, t_stack *stk_2)
{
	swap(stk_1, 0);
	swap(stk_2, 0);
	ft_printf("ss\n");
}
