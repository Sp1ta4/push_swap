/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggevorgi <sp1tak.gg@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:34:08 by ggevorgi          #+#    #+#             */
/*   Updated: 2025/02/14 09:10:15 by ggevorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_log2(size_t n)
{
	size_t log = 0;

	if (n == 0)
		return (0);
	while (n >>= 1)
		log++;
	return (log);
}

size_t	ft_sqrt(size_t n)
{
	size_t left;
	size_t right = n / 2 + 1;
	size_t mid;

	left = 1;
	if (n == 0 || n == 1)
		return (n);
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (mid > n / mid)
			right = mid - 1;
		else
		{
			if ((mid + 1) > n / (mid + 1))
				return (mid);
			left = mid + 1;
		}
	}
	return (0);
}

size_t get_available_number_range(size_t lstsize)
{
	return (ft_sqrt(lstsize) + ft_log2(lstsize) - 1);
}
