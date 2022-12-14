/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_sort_2_5.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/17 19:16:02 by mweverli      #+#    #+#                 */
/*   Updated: 2022/10/30 11:20:40 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <operations.h>
#include <list_utils.h>

size_t	get_lowest_position(t_stack *stk)
{
	size_t	min;
	size_t	size;
	size_t	nloc;
	t_node	*tmp;

	min = UINT_MAX;
	size = stack_size(stk);
	tmp = stk->top;
	while (size--)
	{
		if (min > tmp->n_val)
		{
			min = tmp->n_val;
			nloc = stack_size(stk) - size;
		}
		tmp = tmp->next;
	}
	return (nloc);
}

void	push_lowest(t_stack *a, t_stack *b)
{
	size_t	nloc;

	nloc = get_lowest_position(a);
	if (nloc == 5)
		rev_rotate(a, 1);
	else if (nloc == 4 && a->size == 5)
	{
		rev_rotate(a, 1);
		rev_rotate(a, 1);
	}
	else if (nloc == 4 && a->size == 4)
		rev_rotate(a, 1);
	else if (nloc == 3)
	{
		rotate(a, 1);
		rotate(a, 1);
	}
	else if (nloc == 2)
		rotate(a, 1);
	push(a, b, 1);
}

void	sort_3(t_stack *a)
{
	size_t	n1;
	size_t	n2;
	size_t	n3;

	n1 = a->top->n_val;
	n2 = a->top->next->n_val;
	n3 = a->top->next->next->n_val;
	if (n1 < n2 && n2 > n3 && n1 < n3)
	{
		rev_rotate(a, 1);
		swap(a, 1);
	}
	else if (n1 < n2 && n2 > n3 && n1 > n3)
		rev_rotate(a, 1);
	else if (n1 > n2 && n2 > n3 && n1 > n3)
	{
		rotate(a, 1);
		swap(a, 1);
	}
	else if (n1 > n2 && n2 < n3 && n1 < n3)
		swap(a, 1);
	else if (n1 > n2 && n2 < n3 && n1 > n3)
		rotate(a, 1);
}

void	sort_4(t_stack *a, t_stack *b)
{
	push_lowest(a, b);
	sort_3(a);
	push(b, a, 1);
}

void	sort_5(t_stack *a, t_stack *b)
{
	push_lowest(a, b);
	sort_4(a, b);
	push(b, a, 1);
}
