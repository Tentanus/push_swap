/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   op_rotate.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 18:48:53 by mweverli      #+#    #+#                 */
/*   Updated: 2022/10/17 17:40:46 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <list_utils.h>

void	rotate(t_stack *stk, int v)
{
	if (stk->top == NULL && ft_printf("rotate: %c = NULL\n", stk->name))
		return ;
	if (v)
		ft_printf("r%c\n", stk->name);
	stk->top = stk->top->next;
}

void	rev_rotate(t_stack *stk, int v)
{
	if (stk->top == NULL && ft_printf("rotate: %c = NULL\n", stk->name))
		return ;
	if (v)
		ft_printf("rr%c\n", stk->name);
	stk->top = stack_last(stk);
}

void	rotrot(t_stack *a, t_stack *b)
{
	rotate(a, 0);
	rotate(b, 0);
	ft_printf("rr\n");
}

void	rev_rotrot(t_stack *a, t_stack *b)
{
	rev_rotate(a, 0);
	rev_rotate(b, 0);
	ft_printf("rrr\n");
}
