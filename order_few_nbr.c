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

void	order_two_nodes(t_list **head_a)
{
	if ((*head_a)->nbr > (*head_a)->nxt->nbr)
		sa(head_a);
}

void	order_three_nodes(t_list **head_a, int aux)
{
	if ((*head_a)->nbr == (1 + aux))
	{
		rra(head_a);
		sa(head_a);
	}
	else if ((*head_a)->nbr == (2 + aux) && (*head_a)->nxt->nbr == (1 + aux))
		sa(head_a);
	else if ((*head_a)->nbr == (2 + aux) && (*head_a)->nxt->nbr == (3 + aux))
		rra(head_a);
	else if ((*head_a)->nbr == (3 + aux) && (*head_a)->nxt->nbr == (1 + aux))
		ra(head_a);
	else
	{
		ra(head_a);
		sa(head_a);
	}
}

void	order_four_nodes(t_list **head_a, t_list **head_b)
{
	int	aux;
	int	count;

	aux = 1;
	count = 0;
	while (count < 1)
	{
		if ((*head_a)->nbr == 1)
		{
			pb(head_a, head_b);
			count++;
		}
		else
			ra(head_a);
	}
	if ((*head_a)->nbr != 2 || (*head_a)->nxt->nbr != 3)
		order_three_nodes(head_a, aux);
	pa(head_a, head_b);
}

void	order_five_nodes(t_list **head_a, t_list **head_b)
{
	int	count;
	int	aux;

	count = 0;
	aux = 2;
	while (count < 2)
	{
		if ((*head_a)->nbr == 1 || (*head_a)->nbr == 2)
		{
			pb(head_a, head_b);
			count++;
		}
		else
			ra(head_a);
	}
	if ((*head_a)->nbr != 3 || (*head_a)->nxt->nbr != 4)
		order_three_nodes(head_a, aux);
	if ((*head_b)->nbr == 1)
		sb(head_b);
	pa(head_a, head_b);
	pa(head_a, head_b);
}
