/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   op_rotate.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 18:48:53 by mweverli      #+#    #+#                 */
/*   Updated: 2022/10/10 12:25:48 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <list_utils.h>

void	rotate(t_stack *stk)
{
	stk->top = stk->top->next;
}

void	rev_rotate(t_stack *stk)
{
	stk->top = stack_last(stk);
}

void	rotrot(t_stack *a, t_stack *b);
{
	rotate(a);
	rotate(b);
}

void	rev_rotrot(t_stack *a, t_stack *b);
{
	rev_rotate(a);
	rev_rotate(b);
}
