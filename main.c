/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggevorgi <sp1tak.gg@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 20:05:50 by ggevorgi          #+#    #+#             */
/*   Updated: 2025/02/08 21:51:25 by ggevorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

char **create_splited_numbers(char **str_arr)
{
	char *joined_str;
	char **result;
	int	i;

	i = 0;
	joined_str = "";
	while (str_arr[i])
	{
		joined_str = ft_strjoin(joined_str, str_arr[i]);
		joined_str = ft_strjoin(joined_str, " ");
		if(!joined_str)
			break ;
		i++;
	}
	if (!joined_str)
		return (NULL);
	result = ft_split(joined_str, ' ');
	if (!result)
	{
		free(joined_str);
		return (NULL);
	}
	free(joined_str);
	return (result);
}

int ft_isnotdigit(char *str)
{
	while(*str)
	{
		if (*str < '0' && *str > '9')
			return (1);
		str++;
	}
	return (0);
}

int is_valid_params(char **argv)
{
	int	i;

	i = -1;
	while(argv[++i])
	{
		if(ft_isnotdigit(argv[1]))
			return (0);
	}
	return (1);
}

int array_length(char **str_arr)
{
	int len;

	len = -1;
	while(str_arr[++len])
		continue;
	return (len);
}

int *check_and_create_atoi_array(char **nums_str)
{
	int *res;
	int i;
	long tmp;

	if(!nums_str && !*nums_str)
		return (NULL);
	i = -1;
	res = (int *)malloc((sizeof(int) * array_length(nums_str)) + 1);
	if (!res)
		return (NULL);
	while(nums_str[++i])
	{
		tmp = ft_atoi(*nums_str);
		if (tmp < INT_MIN || tmp > INT_MAX)
		{
			free(res);
			throw_error();
			return (NULL);
		}
		res[i] = tmp;
	}
	res[i] = 0;
	return (res);
}
int	main(int argc, char **argv)
{
	char **char_nums_array;
	int *nums_array;
	
	if (argc > 1 && argv)
	{
		if (!is_valid_params(argv + 1))
		{
			throw_error();
			exit(1);
		}
		char_nums_array = create_splited_numbers(argv + 1);
		if (!char_nums_array)
			exit(1);
		nums_array = check_and_create_atoi_array(char_nums_array);
		if (!nums_array)
			exit(1);
		while(nums_array)
		{
			printf("%d\n", *nums_array);
			nums_array++;
		}
		
	}
	return (0);
}
