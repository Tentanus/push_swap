/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/07 18:48:53 by mweverli      #+#    #+#                 */
/*   Updated: 2022/10/17 23:00:56 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

// INCLUDES

# include <push_swap.h>

// FUNCTIONS

void	push(t_stack *from, t_stack *to);
void	swap(t_stack *stk, int v);
void	swapswap(t_stack *stk1, t_stack *stk2);
void	rotate(t_stack *stk, int v);
void	rev_rotate(t_stack *a, int v);
void	rotrot(t_stack *a, t_stack *b);
void	rev_rotrot(t_stack *a, t_stack *b);

#endif
