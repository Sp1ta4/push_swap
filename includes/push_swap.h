/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggevorgi <sp1tak.gg@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 17:11:04 by ggevorgi          #+#    #+#             */
/*   Updated: 2025/02/17 09:46:04 by ggevorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include "libft.h"
# include <unistd.h>
# include <limits.h>

int				ft_isspace(char c);
void			throw_error(void);
int				*check_and_create_atoi_array(char **nums_str);
size_t			array_length(char **str_arr);
int				is_valid_params(char **argv, int argc);
int				ft_isnotdigit(char *str, int has_digit, int in_number);
void			check_null(void *arg);
int				is_repeat_num(int *arr, int length, long num);
void			swap(int *a, int *b);
int				is_sorted(int *arr, size_t size);
char			**create_splited_numbers(char **str_arr);
void			free_ptr(void **p);
void			check_nums_arr(int *num_arr, char **char_nums_arr, size_t len);
void			check_idx_arr(size_t *i_array, int *n_array, char **char_nums);
t_stack			*create_stack(int *nums_array, size_t *i_arr, size_t length);
void			rotate_begin_to_end_n(t_stack **stack, char *op, size_t n);
void			rr_begin_to_end_n(t_stack **stack, char *op, size_t n);
size_t			find_max_index_pos(t_stack *stack);
void			create_butterfly(t_stack **a_stack, t_stack **b_stack);
void			free_split(char **arr);
void			free_list(t_stack *list);
void			reverse_rotate_begin_to_end(t_stack **begin, char *msg);
void			rotate_begin_to_end(t_stack **begin, char *msg);
void			push_s_to_f(t_stack **f_stack, t_stack **s_stack, char *msg);
void			swap_begin_second(t_stack **stack, char *msg);
void			init_stack(t_stack **stack, size_t *indexes_array, char **argv);
void			sort_stack(t_stack **a_stack, t_stack **b_stack);
size_t			get_available_number_range(size_t lstsize);
size_t			*take_sorted_indexes(int *arr, size_t length);
int				is_str_repeat_in_array(char **str_nums_array);
long			ft_atol(const char *nptr);
size_t			ft_atol_strlen(const char *s);
#endif