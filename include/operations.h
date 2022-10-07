/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/07 18:48:53 by mweverli      #+#    #+#                 */
/*   Updated: 2022/10/07 21:04:38 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

// INCLUDES

#include <push_swap.h>

// FUNCTIONS

void	swap(t_stack *stack);
void	swapswap(t_stack *stack1, t_stack *stack2);
void	push(t_stack *from, t_stack *to);

#endif
