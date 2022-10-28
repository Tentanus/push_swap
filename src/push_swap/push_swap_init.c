/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_init.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/03 16:48:51 by mweverli      #+#    #+#                 */
/*   Updated: 2022/10/21 19:40:34 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <list_utils.h>

static int	check_str(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	*check_int(char **inp, int argc)
{
	int	*arr;
	int	index;

	arr = ft_calloc(argc, sizeof(int));
	index = 0;
	errno = 0;
	while (index < argc)
	{
		if (!(check_str(inp[index])))
			push_swap_exit();
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
	stk->vars.max_nor = size - 1;
}

void	set_val(t_stack *a, t_stack *b)
{
	int	bit;
	int	max_nor;

	bit = 0;
	max_nor = a->vars.max_nor;
	a->name = 'a';
	b->name = 'b';
	b->size = 0;
	b->top = NULL;
	while (max_nor)
	{
		max_nor /= 2;
		bit++;
	}
	a->vars.max_bit = bit;
	b->vars.max_bit = bit;
	b->vars.max_nor = a->vars.max_nor;
}

void	push_swap_init(char **inp, int argc, t_stack *a, t_stack *b)
{
	int	*arr;
	int	*nor;

	a->size = 0;
	a->top = NULL;
	arr = check_int(inp, argc);
	nor = bub_sort(arr, argc);
	fill_stack(arr, nor, a, argc);
	set_val(a, b);
	free(arr);
	free(nor);
}
