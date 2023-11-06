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

int	is_set_in_order(t_list *head_a)
{
	t_list	*aux1;
	t_list	*aux2;

	aux1 = head_a;
	aux2 = head_a->nxt;
	if (aux2 == NULL)
		return (0);
	while (aux2 != NULL)
	{
		if (aux1->in < aux2->in)
		{
			aux1 = aux1->nxt;
			aux2 = aux2->nxt;
		}
		else
			return (0);
	}
	return (1);
}

int	repeating_nbr(t_list *head_a)
{
	t_list	*aux1;
	t_list	*aux2;

	aux1 = head_a;
	aux2 = head_a->nxt;
	if (aux2 == NULL)
		return (0);
	while (aux2 != NULL)
	{
		while (aux2 != NULL)
		{
			if (aux1->in == aux2->in)
				return (2);
			aux2 = aux2->nxt;
		}
		aux1 = aux1->nxt;
		aux2 = aux1->nxt;
	}
	return (0);
}

int	verify_errors(t_list *head_a)
{
	int	error;

	error = 0;
	error = is_set_in_order(head_a);
	if (error == 1)
		return (1);
	error = repeating_nbr(head_a);
	if (error == 2)
		return (2);
	return (0);
}

int	manage_errors(t_list *head_a, int error)
{
	if (error == 2)
	{
		nodes_free(&head_a);
		write(2, "Error\n", 6);
		return (0);
	}
	else
		nodes_free(&head_a);
	return (0);
}
