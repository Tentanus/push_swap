/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_main.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/16 12:26:02 by mweverli      #+#    #+#                 */
/*   Updated: 2022/10/28 18:26:00 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <list_utils.h>
#include <operations.h>

void	push_swap_free(t_stack *stk)
{
	size_t	size;
	t_node	*tmp;
	t_node	*f;

	tmp = stk->top;
	size = stack_size(stk);
	while (size--)
	{
		f = tmp;
		tmp = tmp->next;
		free(f);
	}
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc < 2)
		return (1);
	push_swap_init((argv + 1), (argc - 1), &a, &b);
	if (check_stack(&a, &b))
	{
		push_swap_free(&a);
		return (0);
	}
	print_stkstk(a, b, 1);
	push(&a, &b);
	print_stkstk(a, b, 0);
	push(&a, &b);
	print_stkstk(a, b, 0);
	push(&a, &b);
	print_stkstk(a, b, 0);
	push(&a, &b);
	print_stkstk(a, b, 0);
	push(&b, &a);
	print_stkstk(a, b, 0);
	push(&b, &a);
	print_stkstk(a, b, 0);
	push(&b, &a);
	print_stkstk(a, b, 0);
	push(&b, &a);
	print_stkstk(a, b, 1);
	push_swap_free(&a);
	return (0);
}
