/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggevorgi <sp1tak.gg@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 17:11:04 by ggevorgi          #+#    #+#             */
/*   Updated: 2025/02/10 17:14:23 by ggevorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <unistd.h>
# include <stdio.h>
# include <limits.h>


typedef struct s_stack_node
{
	int					data;
	size_t				index;
	struct s_stack_node	*next;
}	t_stack_node;

void	throw_error(void);
int		*check_and_create_atoi_array(char **nums_str);
int		array_length(char **str_arr);
int		is_valid_params(char **argv, int argc);
int		ft_isnotdigit(char *str);
char	**create_splited_numbers(char **str_arr);
int		is_str_repeat_in_array(char **str_nums_array);
long	ft_atol(const char *nptr);

#endif