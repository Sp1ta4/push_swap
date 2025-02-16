/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggevorgi <sp1tak.gg@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:47:01 by ggevorgi          #+#    #+#             */
/*   Updated: 2025/02/16 17:42:07 by ggevorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	is_str_repeat_in_array(char **str_nums_array)
{
	int		i;
	int		j;
	size_t	istr_len;
	size_t	jstr_len;

	i = 0;
	while (str_nums_array[i])
	{
		istr_len = ft_strlen(str_nums_array[i]);
		j = i;
		while (str_nums_array[++j])
		{
			jstr_len = ft_strlen(str_nums_array[j]);
			if (jstr_len > istr_len)
			{
				if (!ft_strncmp(str_nums_array[i], str_nums_array[j], jstr_len))
					return (1);
			}
			else
				if (!ft_strncmp(str_nums_array[i], str_nums_array[j], istr_len))
					return (1);
		}
		i++;
	}
	return (0);
}

int	ft_isspace(char c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}

static char	*ft_trim_start(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && ft_isspace(str[i]))
		i++;
	return (&str[i]);
}

int	is_sorted(int *arr, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size - 1)
	{
		if (arr[i] > arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

long	ft_atol(const char *nptr)
{
	long	result;
	char	*nptr_cpy;
	int		is_negative;

	result = 0;
	nptr_cpy = ft_trim_start((char *)nptr);
	is_negative = 1;
	if (*nptr_cpy == '-' || *nptr_cpy == '+')
	{
		if (*nptr_cpy == '-')
			is_negative = -1;
		++nptr_cpy;
	}
	if (ft_atol_strlen(nptr) >= 19)
		throw_error();
	while (ft_isdigit(*nptr_cpy))
	{
		result = result * 10 + (*nptr_cpy - 48);
		nptr_cpy++;
	}
	return (result * is_negative);
}
