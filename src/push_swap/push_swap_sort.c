/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_sort.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/13 20:43:05 by mweverli      #+#    #+#                 */
/*   Updated: 2022/10/28 19:25:00 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <list_utils.h>
#include <operations.h>

void	decide_radix(t_stack *a, t_stack *b, int bit)
{
	int		size;
	t_node	*tmp_a;

	size = stack_size(a);
	while (size--)
	{
		tmp_a = a->top;
		if ((tmp_a->n_val >> bit) & 1)
			rotate(a, 1);
		else
			push(a, b, 1);
	}
}

void	sort_radix(t_stack *a, t_stack *b)
{
	int	bit;
	int	bit_max;

	bit_max = a->vars.max_bit;
	bit = 0;
	while (bit <= bit_max)
	{
		decide_radix(a, b, bit);
		while (b->top != NULL)
			push(b, a, 1);
		bit++;
		if (check_stack(a, b))
			break ;
	}
}

void	sort_2(t_stack *a)
{
	size_t	n1;
	size_t	n2;

	n1 = a->top->n_val;
	n2 = a->top->next->n_val;
	if (n1 > n2)
		swap(a, 1);
	return ;
}

void	push_swap_sort(t_stack *a, t_stack *b)
{
	if (a->size == 1)
		return ;
	else if (a->size == 2)
		sort_2(a);
	else if (a->size == 3)
		sort_3(a);
	else if (a->size == 4)
		sort_4(a, b);
	else if (a->size == 5)
		sort_5(a, b);
	else
		sort_radix(a, b);
}
