/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   op_push.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/03 16:45:50 by mweverli      #+#    #+#                 */
/*   Updated: 2022/10/30 12:46:10 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <list_utils.h>

void	push(t_stack *from, t_stack *to, int v)
{
	t_node	*node;

	if (from->top == NULL)
		return ;
	node = stack_take_front(from);
	if (v)
		ft_printf("p%c\n", to->name);
	if (from->size == 0)
		from->top = NULL;
	stack_add_front(to, node);
}
