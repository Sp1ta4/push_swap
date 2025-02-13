/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggevorgi <sp1tak.gg@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:57:12 by ggevorgi          #+#    #+#             */
/*   Updated: 2025/02/13 17:54:34 by ggevorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node *create_stack(int *nums_array, size_t *indexes_array, size_t length)
{
	t_stack_node	*stack;
	t_stack_node	*tmp_lst;
	size_t				i;

	stack = ft_lstnew(nums_array[0], indexes_array[0]);
	if (!stack)
		return (NULL);
	i = 0;
	while (++i < length)
	{
		tmp_lst = ft_lstnew(nums_array[i], indexes_array[i]);
		if (!tmp_lst)
			return (NULL);
		ft_lstadd_back(&stack, tmp_lst);	
	}
	free_ptr((void **)&nums_array);
	free_ptr((void **)&indexes_array);
	return (stack);
}

void swap_begin_second(t_stack_node **stack, char *msg)
{
    t_stack_node *first;
    t_stack_node *second;

	if (!stack || !*stack || !(*stack)->next)
        return;
	first = *stack;
    second = first->next;
    first->next = second->next;
    second->next = first;
    *stack = second;
    if (msg)
		ft_putstr_fd(msg, 1);
}
 
void push_second_to_first(t_stack_node **f_stack, t_stack_node **s_stack, char *msg)
{
    t_stack_node *tmp;

    if (!f_stack || !s_stack || !*s_stack)
        return;

    tmp = *s_stack;
    *s_stack = (*s_stack)->next;
    tmp->next = *f_stack;  // Вставляем в начало f_stack
    *f_stack = tmp;        // Обновляем f_stack

    if (msg)
        ft_putstr_fd(msg, 1);
}


void rotate_begin_to_end(t_stack_node **begin, char *msg)
{
	t_stack_node *tmp;
	
	if (!begin || !*begin || !(*begin)->next)
		return ;
	tmp = *begin;
	*begin = (*begin)->next;
	tmp->next = NULL;
	ft_lstadd_back(begin, tmp);
	if (msg)
		ft_putstr_fd(msg, 1);
}
void reverse_rotate_begin_to_end(t_stack_node **begin, char *msg)
{
    t_stack_node *tmp;
    t_stack_node *prev;

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
