/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   op_push.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/03 16:45:50 by mweverli      #+#    #+#                 */
/*   Updated: 2022/10/06 12:12:44 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	push(t_stack *from, t_stack *to)
{
	t_node	*node1;
	t_node	*node2;

	node1 = from->top;
	node2 = node1->next;
	node1->next = to->top;
	to->top = node1;
	from->top = node2;
}
