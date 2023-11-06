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

void	sa(t_list **head_a)
{
	t_list	*aux1;

	aux1 = (*head_a)->nxt->nxt;
	(*head_a)->nxt->nxt = *head_a;
	*head_a = (*head_a)->nxt;
	(*head_a)->nxt->nxt = aux1;
	write(1, "sa\n", 3);
}

void	sb(t_list **head_b)
{
	t_list	*aux1;

	aux1 = (*head_b)->nxt->nxt;
	(*head_b)->nxt->nxt = *head_b;
	*head_b = (*head_b)->nxt;
	(*head_b)->nxt->nxt = aux1;
	write(1, "sb\n", 3);
}

void	pa(t_list **head_a, t_list **head_b)
{
	t_list	*aux1;

	aux1 = *head_b;
	*head_b = (*head_b)->nxt;
	aux1->nxt = *head_a;
	*head_a = aux1;
	write(1, "pa\n", 3);
}

void	pb(t_list **head_a, t_list **head_b)
{
	t_list	*aux1;

	aux1 = *head_a;
	*head_a = (*head_a)->nxt;
	aux1->nxt = *head_b;
	*head_b = aux1;
	write(1, "pb\n", 3);
}

void	ra(t_list **head_a)
{
	t_list	*aux1;
	t_list	*aux2;
	t_list	*back;

	aux1 = (*head_a);
	while (aux1 != NULL)
	{
		back = aux1;
		aux1 = aux1->nxt;
	}
	aux1 = *head_a;
	aux2 = (*head_a)->nxt;
	(*head_a)->nxt = NULL;
	*head_a = aux2;
	back->nxt = aux1;
	write(1, "ra\n", 3);
}
