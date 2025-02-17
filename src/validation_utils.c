/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggevorgi <sp1tak.gg@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 13:55:13 by ggevorgi          #+#    #+#             */
/*   Updated: 2025/02/17 09:46:44 by ggevorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**create_splited_numbers(char **str_arr)
{
	char	*joined_str;
	char	**result;
	char	*tmp;
	int		i;

	i = 0;
	joined_str = ft_strdup("");
	if (!joined_str)
		return (NULL);
	while (str_arr[i])
	{
		tmp = ft_strjoin(joined_str, str_arr[i]);
		free(joined_str);
		if (!tmp)
			return (NULL);
		joined_str = ft_strjoin(tmp, " ");
		free(tmp);
		if (!joined_str)
			return (NULL);
		i++;
	}
	result = ft_split(joined_str, ' ');
	free(joined_str);
	return (result);
}

int	ft_isnotdigit(char *str, int has_digit, int in_number)
{
	while (*str)
	{
		if (ft_isspace(*str))
		{
			in_number = 0;
			str++;
			continue ;
		}
		if (*str == '-' || *str == '+')
		{
			if (in_number || *(str + 1) < '0' || *(str + 1) > '9')
				return (1);
		}
		else if (*str < '0' || *str > '9')
			return (1);
		else
		{
			has_digit = 1;
			in_number = 1;
		}
		str++;
	}
	return (!has_digit);
}

int	is_valid_params(char **argv, int argc)
{
	int	i;

	i = -1;
	while (++i < argc)
	{
		if (ft_isnotdigit(argv[i], 0, 0))
			return (0);
	}
	return (1);
}

size_t	array_length(char **str_arr)
{
	size_t	len;

	len = 0;
	while (str_arr[len])
	{
		++len;
	}
	return (len);
}

int	*check_and_create_atoi_array(char **nums_str)
{
	int		*res;
	int		i;
	long	tmp;

	if ((!nums_str && !*nums_str))
		return (NULL);
	if (is_str_repeat_in_array(nums_str))
		throw_error();
	i = -1;
	res = (int *)malloc((sizeof(int) * array_length(nums_str)));
	check_null(res);
	while (nums_str[++i])
	{
		tmp = ft_atol(nums_str[i]);
		if (tmp < INT_MIN || tmp > INT_MAX || is_repeat_num(res, i + 1, tmp))
		{
			free(res);
			throw_error();
		}
		res[i] = tmp;
	}
	return (res);
}
