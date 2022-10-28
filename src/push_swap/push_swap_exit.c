/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_exit.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/10 16:00:20 by mweverli      #+#    #+#                 */
/*   Updated: 2022/10/27 14:57:38 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	push_swap_exit(void)
{
	write(2, "ERROR\n", 6);
	exit(EXIT_SUCCESS);
}
