/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_init_utils.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 14:13:11 by mweverli      #+#    #+#                 */
/*   Updated: 2022/10/31 19:27:32 by mweverli      ########   odam.nl         */
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

void	check_overflow_duplication(char **inp, int *arr)
{
	int		i;
	int		len;
	char	*tmp;

	i = 0;
	while (inp[i])
	{
		if (!inp[i] || !arr[i])
			push-swap_exit();
		len = ft_strlen(inp[i]);
		tmp = ft_itoa(arr[i]);
		if (!ft_strncmp(inp[i], tmp, len))
			push_swap_exit();
		free(tmp);
		i++;
	}
}
