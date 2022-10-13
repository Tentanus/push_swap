/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   op_push.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/03 16:45:50 by mweverli      #+#    #+#                 */
/*   Updated: 2022/10/13 22:38:21 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <list_utils.h>

void	push(t_stack *from, t_stack *to)
{
	t_node	*f_node1;
	t_node	*f_last;
	t_node	*t_last;

	if (from->top == NULL && ft_printf("push:(%c)->top = NULL\n", from->name))
		return ;
	f_node1 = from->top;
	f_last = stack_last(from);
	from->top = from->top->next;
	f_last->next = from->top;
	from->size--;
	if (from->size == 0)
		from->top = NULL;
	to->size++;
	if (to->top == NULL)
	{
		to->top = f_node1;
		f_node1->next = to->top;
		return ;
	}
	t_last = stack_last(to);
	f_node1->next = to->top;
	to->top = f_node1;
	t_last->next = f_node1;
}
