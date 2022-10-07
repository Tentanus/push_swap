/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_init.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/03 16:48:51 by mweverli      #+#    #+#                 */
/*   Updated: 2022/10/07 15:11:07 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>

int	input_int(char **inp, int argc)
{
	int	index;
	int	n;

	index = 0;
	n = 0;
	while (index <= argc)
	{
		if (inp[index][0] == '-')
			n = 1;
		if (!ft_stris(&(inp[index][n]), ft_isdigit))
			return (0);
		n = 0;
		index++;
	}
	return (1);
}

void	push_swap_init(char **inp, int argc, t_stack *a, t_stack *b)
{
	if (argc < 2)
		return ;
	a->size = 0;
	b->size = 0;
	if (input_int(inp, argc))
		return ;
}
