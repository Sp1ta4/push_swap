/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggevorgi <sp1tak.gg@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 11:12:01 by ggevorgi          #+#    #+#             */
/*   Updated: 2025/02/16 17:41:27 by ggevorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	sort_arr(int *arr, int length)
{
	int	i;
	int	j;
	int	is_swapped;

	i = 0;
	while (i < length - 1)
	{
		is_swapped = 0;
		j = 0;
		while (j < length - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(&arr[j], &arr[j + 1]);
				is_swapped = 1;
			}
			j++;
		}
		if (!is_swapped)
			break ;
		i++;
	}
}

size_t	ft_index_of(int *arr, int num, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		if (arr[i] == num)
			return (i);
		i++;
	}
	return (-1);
}

size_t	*take_sorted_indexes(int *arr, size_t length)
{
	size_t	*indexes;
	int		*sorted_arr;
	size_t	i;

	sorted_arr = (int *)malloc(sizeof(int) * length);
	if (!sorted_arr)
		return (NULL);
	indexes = (size_t *)malloc(sizeof(size_t) * length);
	if (!indexes)
		return (NULL);
	i = 0;
	while (i < length)
	{
		sorted_arr[i] = arr[i];
		i++;
	}
	sort_arr(sorted_arr, length);
	i = 0;
	while (i < length)
	{
		indexes[i] = ft_index_of(sorted_arr, arr[i], length);
		i++;
	}
	free(sorted_arr);
	return (indexes);
}
