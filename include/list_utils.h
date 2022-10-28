/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_utils.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 12:06:26 by mweverli      #+#    #+#                 */
/*   Updated: 2022/10/28 18:21:14 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_UTILS_H
# define LIST_UTILS_H

// INCLUDES

# include <push_swap.h>

// FUNCTIONS

t_node	*stack_last(t_stack *stk);
t_node	*stack_take_front(t_stack *stk);
int		stack_size(t_stack *stk);
void	stack_add_front(t_stack *stk, t_node *node);
void	stack_add_back(t_stack *stk, t_node *node);

#endif

// if stack_add_front not used remove it
