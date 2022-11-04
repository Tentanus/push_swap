/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_init_utils.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 14:13:11 by mweverli      #+#    #+#                 */
/*   Updated: 2022/11/02 17:56:28 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <limits.h>

static void	bub_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	*bub_sort(int *arr, int size)
{
	int	i;
	int	*nor;

	i = 0;
	nor = ft_calloc(size, sizeof(int));
	if (!nor)
		push_swap_exit();
	while (i < size)
	{
		nor[i] = arr[i];
		i++;
	}
	while (size)
	{
		i = 0;
		while (i < (size - 1))
		{
			if (nor[i] > nor[i + 1])
				bub_swap(&nor[i], &nor[i + 1]);
			i++;
		}
		size--;
	}
	return (nor);
}
