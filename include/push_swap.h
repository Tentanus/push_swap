/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/01 17:59:48 by mweverli      #+#    #+#                 */
/*   Updated: 2022/10/03 15:46:22 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// INCLUDES

# include <stdlib.h>

// MACROS

// STRUCTURES

typedef struct s_node {
	int				i_val;
	size_t			n_val;
	struct s_node	*next;
}	t_node;

typedef struct s_stack {
	char	name;
	t_node	**top;
	size_t	size_stack;
}i	t_stack;

// FUNCTIONS

#endif

/*
 * Redix sort
 * Bubble sort
 *
 * Bitshifting
 *
 *
 * Allowed functions
 * read, write		unistd.h
 * malloc free		stdlib.h
 * exit				stdlib.h
 *
 *
 */
