/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggevorgi <sp1tak.gg@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:34:08 by ggevorgi          #+#    #+#             */
/*   Updated: 2025/02/17 09:15:50 by ggevorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	ft_log2(size_t n)
{
	size_t	log;

	if (n == 0)
		return (0);
	log = 0;
	while (n)
	{
		n >>= 1;
		log++;
	}
	return (log);
}

static size_t	ft_sqrt(size_t n)
{
	size_t	left;
	size_t	right;
	size_t	mid;
	size_t	res;

	if (n == 0 || n == 1)
		return (n);
	left = 1;
	right = n / 2 + 1;
	res = 0;
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (mid * mid == n)
			return (mid);
		else if (mid * mid < n)
		{
			left = mid + 1;
			res = mid;
		}
		else
			right = mid - 1;
	}
	return (res);
}

size_t	get_available_number_range(size_t lstsize)
{
	if (lstsize == 0)
		return (0);
	return ((ft_sqrt(lstsize) * 3) / 2 + ft_log2(lstsize) - 1);
}
