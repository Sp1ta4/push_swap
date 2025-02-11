/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggevorgi <sp1tak.gg@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 17:11:04 by ggevorgi          #+#    #+#             */
/*   Updated: 2025/02/11 13:25:52 by ggevorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <unistd.h>
# include <stdio.h>
# include <limits.h>


void	throw_error(void);
int		*check_and_create_atoi_array(char **nums_str);
size_t		array_length(char **str_arr);
int		is_valid_params(char **argv, int argc);
int		ft_isnotdigit(char *str);
void	check_NULL(void *arg);
void	swap(int *a, int *b);
void	sort_arr(int *arr, int length);
char	**create_splited_numbers(char **str_arr);
size_t 	ft_index_of(int *arr, int num, size_t len);
int		is_sorted(int *arr);
void	free_ptr(void **p);

void	print_numarray (int *arr, int length);

size_t		*take_sorted_indexes(int *arr, size_t length);
int		is_str_repeat_in_array(char **str_nums_array);
long	ft_atol(const char *nptr);

#endif