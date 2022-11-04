/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/01 17:59:48 by mweverli      #+#    #+#                 */
/*   Updated: 2022/11/02 17:59:10 by mweverli      ########   odam.nl         */
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
	unsigned int	n_val;
	struct s_node	*next;
}	t_node;

typedef struct s_vars {
	int		max_nor;
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
void	push_swap_sort(t_stack *a, t_stack *b);

// UTILS
int		check_stack(t_stack *a, t_stack *b);
int		*bub_sort(int *arr, int size);

// SORTER
void	sort_2(t_stack *a);
void	sort_3(t_stack *a);
void	sort_4(t_stack *a, t_stack *b);
void	sort_5(t_stack *a, t_stack *b);
void	sort_radix(t_stack *a, t_stack *B);

// TEST FUNCTION
void	print_stkstk(t_stack a, t_stack b, int v);

#endif
