/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_init.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/03 16:48:51 by mweverli      #+#    #+#                 */
/*   Updated: 2022/10/12 20:53:15 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <list_utils.h>
#include <libft.h>

int	*bub_sort(int *arr, int size)
{
	int	i;
	int	*nor;

	i = -1;
	nor = ft_calloc(size, sizeof(int));
	if (!nor)
		push_swap_exit();
	while (++i < size)
		nor[i] = arr[i];
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

static int	*check_int(char **inp, int argc)
{
	int	*arr;
	int	index;

	arr = ft_calloc(argc, sizeof(int));
	index = 0;
	errno = 0;
	while (argc > index)
	{
		arr[index] = ft_atoi(inp[index]);
		if (errno != 0)
			push_swap_exit();
		index++;
	}
	return (arr);
}

static void	fill_stack(int *inp, int *nor, t_stack *stk, int size)
{
	int		i;
	int		j;
	t_node	*tmp;

	i = -1;
	while (++i < (size - 1))
		if (nor[i] == nor [i + 1])
			push_swap_exit();
	i = 0;
	while (i < size)
	{
		tmp = ft_calloc(1, sizeof(t_node));
		if (!tmp)
			push_swap_exit();
		tmp->i_val = inp[i];
		j = 0;
		while (j < size)
			if (inp[i] == nor[j++])
				break ;
		tmp->n_val = (j - 1);
		stack_add_back(stk, tmp);
		i++;
	}
}

void	push_swap_init(char **inp, int argc, t_stack *a, t_stack *b)
{
	int	*arr;
	int	*nor;

	a->name = 'a';
	b->name = 'b';
	a->size = 0;
	b->size = 0;
	arr = check_int(inp, argc);
	nor = bub_sort(arr, argc);
	fill_stack(arr, nor, a, argc);
	free(arr);
	ft_printf("push_swap_init FINISHED");
}
