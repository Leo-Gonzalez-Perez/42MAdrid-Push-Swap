/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motions_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgonzal2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 10:47:49 by lgonzal2          #+#    #+#             */
/*   Updated: 2023/03/30 10:47:52 by lgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	count_nodes(t_list *head_a)
{
	t_list	*aux1;
	int		nbr_nodes;

	aux1 = head_a;
	nbr_nodes = 0;
	while (aux1 != NULL)
	{
		nbr_nodes++;
		aux1 = aux1->nxt;
	}
	return (nbr_nodes);
}

void	in_to_nbr(t_list *head_a)
{
	t_list	*ptr_aux1;
	t_list	*ptr_aux2;
	int		count;

	ptr_aux1 = head_a;
	ptr_aux2 = head_a;
	while (ptr_aux1 != NULL)
	{
		count = 1;
		while (ptr_aux2 != NULL)
		{
			if (ptr_aux1->in > ptr_aux2->in)
				count++;
			ptr_aux2 = ptr_aux2->nxt;
		}
		ptr_aux1->nbr = count;
		ptr_aux1 = ptr_aux1->nxt;
		ptr_aux2 = head_a;
	}
}

t_list	*create_nodes(char **a_split, t_list **head_a, int *error)
{
	t_list	*aux;
	t_list	*new_node;

	aux = (*head_a);
	new_node = (t_list *)malloc(sizeof(t_list));
	if (new_node == NULL)
		return (0);
	new_node->in = ft_atoi(*a_split, error);
	new_node->nxt = NULL;
	if ((*head_a) == NULL)
		(*head_a) = new_node;
	else
	{
		while (aux->nxt != NULL)
			aux = aux->nxt;
		aux->nxt = new_node;
	}
	return (*head_a);
}
