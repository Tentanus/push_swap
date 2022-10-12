/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_init_utils.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 14:13:11 by mweverli      #+#    #+#                 */
/*   Updated: 2022/10/12 20:49:29 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

void	bub_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	int_arr_cmp(int *inp, int val, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (val == inp[i])
			return (1);
		i++;
	}
	return (0);
}
