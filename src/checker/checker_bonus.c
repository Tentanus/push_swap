/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker_bonus.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/28 13:59:55 by mweverli      #+#    #+#                 */
/*   Updated: 2022/10/30 13:08:50 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <list_utils.h>
#include <operations.h>
#include <unistd.h>

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

char	**read_input(void)
{
	char	**ret;
	char	*inst;
	char	buff[101];
	int		read_ret;

	inst = ft_calloc(sizeof(char), 1);
	while (1)
	{
		read_ret = read(0, buff, 100);
		if (read_ret == -1)
			push_swap_exit();
		if (!read_ret)
			break ;
		buff[read_ret] = '\0';
		inst = ft_strjoin_fs1(inst, buff);
		if (inst == NULL)
			push_swap_exit();
	}
	ret = ft_split(inst, '\n');
	if (!ret)
		push_swap_exit();
	free(inst);
	return (ret);
}

void	decide(char *inp, t_stack *a, t_stack *b)
{
	if (!ft_strncmp(inp, "sa", 3))
		swap(a, 0);
	else if (!ft_strncmp(inp, "sb", 3))
		swap(b, 0);
	else if (!ft_strncmp(inp, "pa", 3))
		push(b, a, 0);
	else if (!ft_strncmp(inp, "pb", 3))
		push(a, b, 0);
	else if (!ft_strncmp(inp, "ra", 3))
		rotate(a, 0);
	else if (!ft_strncmp(inp, "rb", 3))
		rotate(b, 0);
	else if (!ft_strncmp(inp, "rr", 3))
		rotrot(a, b, 0);
	else if (!ft_strncmp(inp, "rra", 4))
		rev_rotate(a, 0);
	else if (!ft_strncmp(inp, "rrb", 4))
		rev_rotate(b, 0);
	else if (!ft_strncmp(inp, "rrr", 4))
		rev_rotrot(a, b, 0);
	else
		push_swap_exit();
	return ;
}

void	checker(t_stack *a, t_stack *b)
{
	char	**inst;
	char	**top;
	char	*tmp;

	inst = read_input();
	top = inst;
	while (*inst)
	{
		decide(*inst, a, b);
		tmp = *inst;
		inst++;
		free(tmp);
	}
	free(top);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc < 2)
		return (1);
	push_swap_init((argv + 1), (argc - 1), &a, &b);
	checker(&a, &b);
	if (check_stack(&a, &b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	push_swap_free(&a);
	return (0);
}
