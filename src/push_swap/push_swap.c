/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/01 17:59:34 by mweverli      #+#    #+#                 */
/*   Updated: 2022/10/18 00:22:47 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <list_utils.h>

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
	push_swap_sort(&a, &b);
	push_swap_free(&a);
	return (0);
}
