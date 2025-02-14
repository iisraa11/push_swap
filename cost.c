/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isrguerr <isrguerr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:57:27 by isrguerr          #+#    #+#             */
/*   Updated: 2025/02/14 18:48:11 by isrguerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int	find_insert_position_cost(t_list *list, int value, int n)
{
	int		position;
	t_list	*current;

	position = 0;
	if (!list)
		return (position);

	if (n == 1)
	{
		current = list;
		while (current)
		{
			if (value > current->value)
				break ;
			position++;
			current = current->next;
		}
	}
	else
	{
		current = ft_lstlast(list);
		while (current)
		{
			if (value < current->value)
				break ;
			position++;
			current = current->prev;
		}
	}
	return (position);
}

int search_index(t_list *list, int value)
{
    int i;
    
    i = 0;
    while(list)
    {
        if (list->value == value)
            break;
        list = list->next;
        i++;
    }
    return (i);
}

int	ft_case_rarb(t_list **a, t_list **b, t_cost *cost, int value)
{
    cost->ra = 0;
    cost->rb = 0;
    cost->rra = 0;
    cost->rrb = 0;
    cost->index_a = search_index(*a, value);
    cost->ra = cost->index_a;
    cost->rb = find_insert_position_cost((*b), value, 0);
    return (cost->ra + cost->rb);
}

int	ft_case_rrarrb(t_list **a, t_list **b, t_cost *cost, int value)
{
    int sizea;
    
    cost->ra = 0;
    cost->rb = 0;
    cost->rra = 0;
    cost->rrb = 0;
    sizea = ft_lstsize(*a);
    cost->index_a = search_index(*a, value);
    cost->rra = sizea - cost->index_a;
    cost->rrb = find_insert_position_cost((*b), value, 1);
    return (cost->rra + cost->rrb);
}

int	ft_case_rarrb(t_list **a, t_list **b, t_cost *cost, int value)
{
    cost->ra = 0;
    cost->rb = 0;
    cost->rra = 0;
    cost->rrb = 0;
    cost->index_a = search_index(*a, value);
    cost->ra = cost->index_a;
    cost->rrb = find_insert_position_cost((*b), value, 1);
    return (cost->ra + cost->rrb);
}

int	ft_case_rrarb(t_list **a, t_list **b, t_cost *cost, int value)
{
    int sizea;

    cost->ra = 0;
    cost->rb = 0;
    cost->rra = 0;
    cost->rrb = 0;
    sizea = ft_lstsize(*a);
    cost->index_a = search_index(*a, value);
    cost->rra = sizea - cost->index_a;
    cost->rb = find_insert_position_cost((*b), value, 0);
    return (cost->rra + cost->rb);
}

int	calculate_cost(t_list **a, t_list **b, t_cost *cost, int value)
{
    int		total_cost;

    total_cost = INT_MAX;
        if (total_cost > ft_case_rarb(a, b, cost, value))
        {
            total_cost = ft_case_rarb(a, b, cost, value);
            printf("coste rarb %d\n", total_cost);  
        }
        if (total_cost > ft_case_rrarrb(a, b, cost, value))
        {
            total_cost = ft_case_rrarrb(a, b, cost, value);
            printf("coste rrarrb %d\n", total_cost);  
        }
        if (total_cost > ft_case_rarrb(a, b, cost, value))
        {
            total_cost = ft_case_rarrb(a, b, cost, value); 
            printf("coste rarrb %d\n", total_cost); 
        }
        if (total_cost > ft_case_rrarb(a, b, cost, value))
        {
            total_cost = ft_case_rrarb(a, b, cost, value);
            printf("coste rrarb %d\n", total_cost);  
        }
    cost->total_cost = total_cost;
    printf("coste retornado%d\n", total_cost);
    return (total_cost);
}

t_cost  min_cost(t_list **a, t_list **b)
{
    t_list	*current;
    t_cost  cost;
    t_cost  temp;
    
    current = *a;
    ft_bzero(&cost, sizeof(cost));
    cost.total_cost = INT_MAX;
    ft_bzero(&temp, sizeof(cost));
    while (current)
    {
        if (cost.total_cost > calculate_cost(a, b, &temp, current->value))
        {
            cost.ra = temp.ra;
            cost.rb = temp.rb;
            cost.rra = temp.rra;
            cost.rrb = temp.rrb;
            //if (cost.total_cost == 0)
                //return (cost);
        }
        current = current->next;
    }
    return (cost);
}
