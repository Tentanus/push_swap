/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_print.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/16 12:25:36 by mweverli      #+#    #+#                 */
/*   Updated: 2022/10/17 12:45:31 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#include <push_swap.h>

void	print_stkstk(t_stack a, t_stack b, int v)
{
	int		a_s;
	int		b_s;
	int		i;
	int		i_2;
	t_node	*tmp_a;
	t_node	*tmp_b;

	a_s = a.size;
	b_s = b.size;
	i = ft_ternary(a_s > b_s, a_s - b_s, b_s - a_s);
	i_2 = ft_ternary(a_s > b_s, a_s - i, b_s - i);
	if (a_s == b_s)
	{
		i_2 = a.size;
		i = 0;
	}
	tmp_a = a.top;
	tmp_b = b.top;
	ft_printf("\t=== STACK: A===\t\t\t=== STACK: B===\n");
	if (v)
	{
		ft_printf("name:\t%c\t\t\t\t%c\n", a.name, b.name);
		ft_printf("size:\t%d\t\t\t\t%d\n", a.size, b.size);
		ft_printf("nor/bit: %d / %d\n", a.vars.max_nor, a.vars.max_bit);
	}
//	ft_printf("decimal\tbinary\t\t\t\tdecimal\tbinary\n");
	while (i_2)
	{
		ft_printf("%d\t%b\t\t%d\t%b\n", tmp_a->i_val, tmp_a->n_val, tmp_b->i_val, tmp_b->n_val);
		tmp_a = tmp_a->next;
		tmp_b = tmp_b->next;
		i_2--;
	}
	while (i && a_s > b_s)
	{
		ft_printf("%d\t%b\n", tmp_a->i_val, tmp_a->n_val);
		tmp_a = tmp_a->next;
		i--;
	}
	while (i && b_s > a_s)
	{
		ft_printf("\t\t\t\t\t%d\t%b\n", tmp_b->i_val, tmp_b->n_val);
		tmp_b = tmp_b->next;
		i--;
	}
	ft_printf("\t\t\t=== ENDPRINT ===\n");
	return ;
}
