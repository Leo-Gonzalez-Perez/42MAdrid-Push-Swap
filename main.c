/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   marzo_20_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgonzal2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:30:07 by lgonzal2          #+#    #+#             */
/*   Updated: 2023/03/29 12:35:12 by lgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ordering(t_list **head_a, t_list **head_b, int nbr_nodes)
{
	int	h;
	int	i;
	int	j;
	int	count;

	h = 1;
	j = 0;
	count = 0;
	while (h <= nbr_nodes)
	{
		i = -1;
		while (++i < nbr_nodes)
		{
			if ((((*head_a)->nbr >> j) & 1) == 0)
				go_to_b(head_a, head_b, &count);
			else
				ra(head_a);
		}
		while (count > 0)
			return_to_a(head_a, head_b, &count);
		if (is_set_in_order(*head_a) == 1)
			break ;
		j++;
		h = h * 2;
	}
}

void	main_2(int argc, char **argv, t_list **head_a, int *error)
{
	int		h;
	int		i;
	char	**a_split;

	h = 1;
	while (h < argc && (*error) < 2)
	{
		i = 0;
		a_split = ft_split(argv[h], ' ', error);
		if (a_split == NULL || a_split[0] == NULL)
			(*error) = 2;
		while (a_split != NULL && a_split[i] != NULL && (*error) != 2)
		{
			create_nodes(a_split, head_a, error);
			free(a_split[0]);
			i++;
		}
		if (a_split != NULL)
			free(a_split);
		h++;
	}
}

void	nodes_free(t_list **head_a)
{
	t_list	*aux1;
	int		i;

	i = 0;
	if (head_a == NULL || (*head_a) == NULL)
		return ;
	while (*head_a != 0)
	{
		aux1 = (*head_a)->nxt;
		free(*head_a);
		(*head_a) = aux1;
	}
}

void	select_algorithm(t_list **head_a, t_list *head_b, int nbr_nodes)
{
	int	aux;

	aux = 0;
	if (nbr_nodes == 2)
		order_two_nodes(head_a);
	else if (nbr_nodes == 3)
		order_three_nodes(head_a, aux);
	else if (nbr_nodes == 4)
		order_four_nodes(head_a, &head_b);
	else if (nbr_nodes == 5)
		order_five_nodes(head_a, &head_b);
	else if (nbr_nodes > 5)
		ordering(head_a, &head_b, nbr_nodes);
}

int	main(int argc, char **argv)
{
	t_list	*head_a;
	t_list	*head_b;
	int		nbr_nodes;
	int		error;

	head_a = 0;
	head_b = 0;
	error = 0;
	if (argc < 2)
		return (0);
	main_2(argc, argv, &head_a, &error);
	nbr_nodes = count_nodes(head_a);
	if (error != 2)
		error = verify_errors(head_a);
	if (error == 2 || error == 1)
		return (manage_errors(head_a, error));
	in_to_nbr(head_a);
	select_algorithm(&head_a, head_b, nbr_nodes);
	nodes_free(&head_a);
	return (0);
}
