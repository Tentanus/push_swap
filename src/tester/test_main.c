/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_main.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/16 12:26:02 by mweverli      #+#    #+#                 */
/*   Updated: 2022/10/17 21:57:12 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <operations.h>

void	print_stkstk(t_stack a, t_stack b, int v);
void	sort_decide(t_stack *a, t_stack *b, int bit);

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc < 2)
		return (1);
	push_swap_init(argv + 1, argc - 1, &a, &b);
	sort_radix(&a, &b);
	print_stkstk(a, b, 0);
	if (check_stack(&a, &b))
		write(1, "SOLVED\n", 7);
	else
		write(1, "WRONG\n", 6);
}
