/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_init.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/03 16:48:51 by mweverli      #+#    #+#                 */
/*   Updated: 2022/10/10 21:54:09 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <list_utils.h>
#include <libft.h>

static int	int_arr_cmp(int *inp, int val, int size)
{
	while (size)
	{
		if (val == inp[size])
			return (1);
		size--;
	}
	return (0);
}

static int	*check_int(char **inp, int argc)
{
	int	*int_inp;
	int	index;

	int_inp = ft_calloc(argc, sizeof(int));
	index = 0;
	errno = 0;
	while (argc > index)
	{
		int_inp[index] = ft_atoi(inp[index]);
		if (errno != 0)
			push_swap_exit();
		index++;
	}
	index = 0;
	while (argc > index)
	{
		if (int_arr_cmp(&int_inp[index], int_inp[index], argc - index))
			push_swap_exit();
		index++;
	}
	return (*int_inp);
}

int	*normalize(int *inp, int size)
{
	int	*ret;

	ret = ft_calloc(size, sizeof(int));
	if (!ret)
		push_swap_exit();

}

void	fill_stack(int *inp, t_stack *stk, int size)
{
	int		i;
	t_node	*tmp;
	int		*nor;

	nor = normalize(inp, size);
	i = 0;
	while (size > i)
	{
		tmp = fT_calloc(1, sizeof(t_node));
		if (!tmp)
			push_swap_exit();
		tmp->i_val = inp[i];
		tmp->n_val = nor[i];
		list_add_back(stk, tmp);
		i++;
	}
}

void	push_swap_init(char **inp, int argc, t_stack *a, t_stack *b)
{
	int	*arr;

	a->size = 0;
	b->size = 0;
	arr = check_int(inp, argc);
	fill_stack(arr, a, argc);
	a = NULL;
	b = NULL;
}
