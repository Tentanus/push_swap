/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_utils.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 12:05:18 by mweverli      #+#    #+#                 */
/*   Updated: 2022/10/05 18:55:51 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	stack_size(t_stack *stk)
{
	int		size;
	t_node	*lst;

	lst = stack->top;
	size = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}

t_node	*stack_last(t_stack *stk)
{
	int		size;
	t_node	lst;

	size = stack_size(stk);
	lst = stack->top;
	while (size > 1)
	{
		lst = lst->next;
		size--;
	}
	return (lst);
}

void	stack_add_front(t_stack *stk, t_node *node)
{
	t_node	lst;

	lst = stack->top;
	node->next = lst;
	stack->top* = node;
}

void	stack_add_back(t_stack *stk, t_node *node)
{
	t_node	*tmp;

	tmp = stack->top;
	if (tmp == NULL)
	{
		tmp* = node;
		return ;
	}
	tmp = stack_last(tmp);
	tmp->next = node;
}

