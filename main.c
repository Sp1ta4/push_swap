/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggevorgi <sp1tak.gg@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 20:05:50 by ggevorgi          #+#    #+#             */
/*   Updated: 2025/02/13 15:46:42 by ggevorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_numarray (int *arr, int length)
{
	int i;

	i = -1;
	write(1, "[", 1);
	while (++i < length)
	{
		i + 1 == length ? printf("%d]\n", arr[i]) : printf("%d, ", arr[i]);
	}
}
void print_sizetarray (size_t *arr, int length)
{
	int i;

	i = -1;
	write(1, "[", 1);
	while (++i < length)
	{
		i + 1 == length ? printf("%ld]\n", arr[i]) : printf("%ld, ", arr[i]);
	}
}
void print_stack(t_stack_node *stack)
{
	if (!stack)
	{
		printf("пусто\n");
		return;
	}
	while (stack)
	{
		printf("%d ", stack->data);
		stack = stack->next;
	}
	printf("\n");
}
void print_stacks(t_stack_node *stack_a, t_stack_node *stack_b)
{
	printf("Stack A: ");
	print_stack(stack_a);

	printf("Stack B: ");
	print_stack(stack_b);
}



void init_stack(t_stack_node **stack, size_t *indexes_array, char **argv)
{
	char			**char_nums_array;
	int				*nums_array;
	size_t				nums_len;
	
	char_nums_array = create_splited_numbers(argv);
	// printf("%s\n", char_nums_array[0]);
	check_NULL(char_nums_array);
	nums_len = array_length(char_nums_array);
	nums_array = check_and_create_atoi_array(char_nums_array);
	check_nums_array(nums_array, char_nums_array);	
	indexes_array = take_sorted_indexes(nums_array, nums_len);
	check_indexes_arr(indexes_array, nums_array, char_nums_array);
	free_split(char_nums_array);
	// print_numarray(nums_array, nums_len);
	// print_sizetarray(indexes_array, nums_len);
	*stack = create_stack(nums_array, indexes_array, nums_len);
}

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

void create_butterfly(t_stack_node **a_stack, t_stack_node **b_stack)
{
    size_t counter;
    size_t available_number_range;

    if (!a_stack || !b_stack) // Проверка на NULL
        return;

    counter = 0;
    available_number_range = get_available_number_range(ft_lstsize(*a_stack));

    // Пока в стеке A есть элементы
    while (*a_stack)
    {
        // Если индекс текущего элемента в стеке A меньше или равен счетчику
        if ((*a_stack)->index <= counter)
        {
            push_second_to_first(b_stack, a_stack, "pb");  // Перемещение в стек B
            rotate_begin_to_end(b_stack, "rb");            // Вращение в стеке B
            ++counter;
        }
        // Если индекс текущего элемента в стеке A находится в допустимом диапазоне
        else if ((*a_stack)->index <= counter + available_number_range)
        {
            push_second_to_first(b_stack, a_stack, "pb");  // Перемещение в стек B
            ++counter;
        }
        // В противном случае вращаем в стеке A
        else
        {
            rotate_begin_to_end(a_stack, "ra");
        }
    }
}

void sort_stack(t_stack_node **a_stack, t_stack_node **b_stack)
{
	create_butterfly(a_stack, b_stack);
	// fill_a_stack(&a_stack, &b_stack);
}

int	main(int argc, char **argv)
{
	
	t_stack_node	*a_stack_begin;
	t_stack_node	*b_stack_begin;
	size_t				*indexes_array;

	if (argc > 2 && argv)
	{
		if (!is_valid_params(argv + 1, argc - 1))
			throw_error();
		b_stack_begin = NULL;
		a_stack_begin = NULL;
		indexes_array = NULL;
		init_stack(&a_stack_begin, indexes_array, argv + 1);
		b_stack_begin = (t_stack_node *)malloc(sizeof(t_stack_node));
		if(!b_stack_begin)
			exit(1);
		b_stack_begin->next = NULL;
		// print_stack(a_stack_begin);
		sort_stack(&a_stack_begin, &b_stack_begin);
 		print_stacks(a_stack_begin, b_stack_begin);

		// printf("%p\n", b_stack_begin);
		// printf("size---------------->%d\n", ft_lstsize(a_stack_begin));
		
		// printf("-------------------->%d\n", b_stack_begin->data);
		// b_stack_begin  = (t_stack_node *)malloc(sizeof(t_stack_node));
		// b_stack_begin->next = NULL;
		// print_stack(b_stack_begin);
		print_stacks(a_stack_begin, b_stack_begin);
		free_list(a_stack_begin);
		free_list(b_stack_begin);
	}
	return (0);
}