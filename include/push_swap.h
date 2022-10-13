/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/01 17:59:48 by mweverli      #+#    #+#                 */
/*   Updated: 2022/10/13 22:00:57 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// EXTERNAL INCLUDES

# include <stdlib.h>
# include <libft.h>

// MACROS

// STRUCTURES

typedef struct s_node {
	int				i_val;
	size_t			n_val;
	struct s_node	*next;
}	t_node;

typedef struct s_vars {
	int		max_int;
	int		max_bit;
}	t_vars;

typedef struct s_stack {
	char	name;
	t_node	*top;
	size_t	size;
	t_vars	vars;
}	t_stack;


// FUNCTIONS

void	push_swap_init(char **inp, int argc, t_stack *a, t_stack *b);
void	push_swap_exit(void);

// utils
void	bub_swap(int *a, int *b);
int		int_arr_cmp(int *inp, int val, int size);

// stack_check
int		check_stack(t_stack *a, t_stack *b);

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
 * datastructure:
 * stacks consist of a linkd list of t_nodes
 *
 */
