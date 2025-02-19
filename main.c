/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isrguerr <isrguerr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:54:31 by isrguerr          #+#    #+#             */
/*   Updated: 2025/02/19 18:24:16 by isrguerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	print_node_value(int content)
{
	printf("%d\n", content);
}

int	is_sorted(t_list *stack, int size)
{
	int	i;

	if (stack == NULL || size <= 1)
		return (1);
	i = 0;
	while (stack->next != NULL && i < size - 1)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
		i++;
	}
	return (1);
}

void	free_stack(t_list **a)
{
	t_list	*temp;

	while (*a != NULL)
	{
		temp = (*a)->next;
		free(*a);
		*a = temp;
	}
	*a = NULL;
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (1);
	else if (argc == 2)
	{
		argv = ft_split(argv[1], 32);
		stack_init(&a, argv);
	}
	else
		stack_init(&a, argv + 1);
	if (!is_sorted(a, ft_lstsize(a)))
		sort_stack(&a, &b);
	ft_lstiter(a, print_node_value);
	free_stack(&a);
	return (0);
}
