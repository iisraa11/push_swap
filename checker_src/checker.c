/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isrguerr <isrguerr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:47:47 by isrguerr          #+#    #+#             */
/*   Updated: 2025/02/21 15:04:58 by isrguerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../push_swap.h"

static char	*ft_check_mov(t_list **a, t_list **b, char *line)
{
	if (!ft_strncmp(line, "pa\n", 3))
		ft_push(a, b, 'a');
	else if (!ft_strncmp(line, "pb\n", 3))
		ft_push(b, a, 'b');
	else if (!ft_strncmp(line, "ra\n", 3))
		ft_rotate(a, 'a');
	else if (!ft_strncmp(line, "rb\n", 3))
		ft_rotate(b, 'b');
	else if (!ft_strncmp(line, "rr\n", 3))
		ft_rotate_both(a, b);
	else if (!ft_strncmp(line, "rra\n", 4))
		ft_reverse(a, 'a');
	else if (!ft_strncmp(line, "rrb\n", 4))
		ft_reverse(b, 'b');
	else if (!ft_strncmp(line, "rrr\n", 4))
		ft_reverse_both(a, b);
	else if (!ft_strncmp(line, "sa\n", 3))
		ft_swap(a, 'a');
	else if (!ft_strncmp(line, "sb\n", 3))
		ft_swap(b, 'b');
	else if (!ft_strncmp(line, "ss\n", 3))
		ft_swap_both(a, b);
	else
		return (NULL);
	return (get_next_line(0));
}

static void	ft_check_file(t_list **a, t_list **b, char *line)
{
	char	*temp;

	while (line && *line != '\n')
	{
		temp = line;
		line = ft_check_mov(a, b, line);
		free(temp);
	}
	if (*b)
		write(1, "KO\n", 3);
	else if (!is_sorted(*a, ft_lstsize(*a)))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	free(line);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	char	*line;

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
	line = get_next_line(0);
	if (!line && !is_sorted(a, ft_lstsize(a)))
		write(1, "KO\n", 3);
	else if (!line && is_sorted(a, ft_lstsize(a)))
		write(1, "OK\n", 3);
	else
		ft_check_file(&a, &b, line);
	ft_lstclear(&a);
	ft_lstclear(&b);
	return (0);
}
