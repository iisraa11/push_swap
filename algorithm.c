/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isrguerr <isrguerr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 17:44:29 by iisraa11          #+#    #+#             */
/*   Updated: 2025/02/14 17:46:06 by isrguerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	big_sort(t_list **a, t_list **b)
{
	t_cost	cost;

	while (ft_lstsize(*a) > 3)
	{
		cost = min_cost(a, b);
		while((cost.rra-- && cost.rrb--) && (cost.rra > 0) && (cost.rrb > 0))
			ft_reverse_both(a, b);
		while((cost.ra-- && cost.rb--) && (cost.ra > 0) && (cost.rb > 0))
			ft_rotate_both(a, b);
		while(cost.rra-- && cost.rra > 0)
			ft_reverse(a, 'a');
		while(cost.rrb-- && cost.rrb > 0)
			ft_reverse(b, 'b');
		while(cost.ra-- && cost.ra > 0)
			ft_rotate(a, 'a');
		while(cost.rb-- && cost.rb > 0)
			ft_rotate(b, 'b');
		ft_push(b, a, 'b');
	}
}

void sort_three(t_list **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && second < third && first < third)
		ft_swap(a, 'a');
	else if (first > second && second > third && first > third)
	{
		ft_swap(a, 'a');
		ft_reverse(a, 'a');
	}
	else if (first > second && second < third && first > third)
		ft_rotate(a, 'a');
	else if (first < second && second > third && first < third)
	{
		ft_swap(a, 'a');
		ft_rotate(a, 'a');
	}
	else if (first < second && second > third && first > third)
		ft_reverse(a, 'a');
}

void sort_five(t_list **a, t_list **b)
{
	while (ft_lstsize(*a) > 3)
		ft_push(b, a, 'b');
	sort_three(a);
	while (ft_lstsize(*b) > 0)
	{
		ft_push(a, b, 'a');
		if ((*a)->value > (*a)->next->value)
			ft_swap(a, 'a');
	}
}

void	sort_stack(t_list **a, t_list **b)
{
	int	size;

	size = ft_lstsize(*a);
	if (size == 2)
		ft_swap(a, 'a');
	else if (size == 3)
		sort_three(a);
	else if (size <= 5)
		sort_five(a, b);
	else
	{
		ft_push(b, a, 'b');
		ft_push(b, a, 'b');
		big_sort(a, b);
		sort_three(a);
		//back_to_a(a, b);
	}
}
