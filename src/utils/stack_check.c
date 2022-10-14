/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_check.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/13 20:45:29 by mweverli      #+#    #+#                 */
/*   Updated: 2022/10/14 17:57:45 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>
#include <list_utils.h>

int	check_stack(t_stack *a, t_stack *b)
{
	int		a_size;
	t_node	*tmp;

	if (b->size == 0)
		b->top = NULL;
	if (b->top != NULL)
		return (0);
	a_size = stack_size(a) - 1;
	tmp = a->top;
	while (a_size)
	{
		if (tmp->i_val > tmp->next->i_val)
			return (0);
		a_size--;
		tmp = tmp->next;
	}
	return (1);
}
