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

//remove print functions
void	print_stkstk(t_stack a, t_stack b, int v);

void	sort_decide(t_stack *a, t_stack *b, int bit)
{
	int		size;
	t_node	*tmp_a;

	size = stack_size(a);
	while (size--)
	{
		tmp_a = a->top;
		if ((tmp_a->n_val >> bit) & 1)
			rotate(a);
		else
			push(a, b);
	}
}

void	push_swap_sort(t_stack *a, t_stack *b)
{
	int	bit;
	int	bit_max;

	bit_max = a->vars.max_bit;
	bit = 0;
	while (bit <= bit_max)
	{
	ft_printf("run %d\n", bit);
		sort_decide(a, b, bit);
		print_stkstk(*a, *b, 0);
		while (b->top != NULL)
			push(b, a);
		bit++;
	}
}
