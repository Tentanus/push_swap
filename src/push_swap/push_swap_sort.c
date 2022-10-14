/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_sort.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/13 20:43:05 by mweverli      #+#    #+#                 */
/*   Updated: 2022/10/14 18:04:18 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <list_utils.h>
#include <operations.h>

void	push_swap_sort(t_stack *a, t_stack *b)
{
	int	bit;
	int	bit_max;
	int	size;

	bit_max = a->vars.max_bit;
	bit = 0;
	while (bit <= bit_max)
	{
		size = stack_size(a);
		while (size)
		{
			if (a->top->n_val >> bit & 1)
				rotate(a);
			else
				push(a, b);
			size--;
		}
		while (b->top != NULL)
			push(b, a);
		bit += 1;
	}
}
