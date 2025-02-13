/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggevorgi <sp1tak.gg@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 17:11:02 by ggevorgi          #+#    #+#             */
/*   Updated: 2025/02/13 17:52:42 by ggevorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void throw_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void free_ptr(void **p)
{
	if (p && *p) {
		free(*p);
		*p = NULL;
	}
}

void free_split(char **arr) {
    int i = 0;
    if (!arr)
        return;
    while (arr[i]) {
        free(arr[i]);
        i++;
    }
    free(arr);
}


void free_list(t_stack_node *list) {
    t_stack_node *tmp;
	
    while (list) {
        tmp = list->next;  // Сохраняем следующий узел
        free(list);  // Освобождаем текущий узел (НЕ передаём &list!)
        list = tmp;  // Переходим к следующему узлу
    }
}

