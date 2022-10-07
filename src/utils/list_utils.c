/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_utils.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 12:05:18 by mweverli      #+#    #+#                 */
/*   Updated: 2022/10/07 21:04:41 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	stack_size(t_stack *stk)
{
	int		size;
	t_node	*lst;
	t_node	*top;

	lst = stk->top;
	top = stk->top;
	size = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		size++;
		if (lst == top)
			break ;
	}
	return (size);
}

t_node	*stack_last(t_stack *stk)
{
	int		size;
	t_node	*lst;

	size = stack_size(stk);
	lst = stk->top;
	while (size > 1)
	{
		lst = lst->next;
		size--;
	}
	return (lst);
}

void	stack_add_back(t_stack *stk, t_node *node)
{
	t_node	*tmp;

	if (stk->top == NULL)
	{
		node->next = node;
		stk->top = node;
		return ;
	}
	node->next = stk->top;
	tmp = stack_last(stk);
	tmp->next = node;
}

