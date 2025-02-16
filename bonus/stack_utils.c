/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggevorgi <sp1tak.gg@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:57:12 by ggevorgi          #+#    #+#             */
/*   Updated: 2025/02/16 17:41:06 by ggevorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_stack	*create_stack(int *nums_array, size_t *i_arr, size_t length)
{
	t_stack	*stack;
	t_stack	*tmp_lst;
	size_t	i;

	stack = ft_lstnew(nums_array[0], i_arr[0]);
	if (!stack)
		return (NULL);
	i = 0;
	while (++i < length)
	{
		tmp_lst = ft_lstnew(nums_array[i], i_arr[i]);
		if (!tmp_lst)
			return (NULL);
		ft_lstadd_back(&stack, tmp_lst);
	}
	free_ptr((void **)&nums_array);
	free_ptr((void **)&i_arr);
	return (stack);
}

void	swap_begin_second(t_stack **stack, char *msg)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
	if (msg)
		ft_putstr_fd(msg, 1);
}

void	push_s_to_f(t_stack **f_stack, t_stack **s_stack, char *msg)
{
	t_stack	*tmp;

	if (!f_stack || !s_stack || !*s_stack)
		return ;
	tmp = *s_stack;
	*s_stack = (*s_stack)->next;
	tmp->next = *f_stack;
	*f_stack = tmp;
	if (msg)
		ft_putstr_fd(msg, 1);
}

void	rotate_begin_to_end(t_stack **begin, char *msg)
{
	t_stack	*tmp;

	if (!begin || !*begin || !(*begin)->next)
		return ;
	tmp = *begin;
	*begin = (*begin)->next;
	tmp->next = NULL;
	ft_lstadd_back(begin, tmp);
	if (msg)
		ft_putstr_fd(msg, 1);
}

void	reverse_rotate_begin_to_end(t_stack **begin, char *msg)
{
	t_stack	*tmp;
	t_stack	*prev;

	if (!begin || !*begin || !(*begin)->next)
		return ;
	tmp = *begin;
	while (tmp->next->next)
		tmp = tmp->next;
	prev = tmp;
	tmp = tmp->next;
	prev->next = NULL;
	tmp->next = *begin;
	*begin = tmp;
	if (msg)
		ft_putstr_fd(msg, 1);
}
