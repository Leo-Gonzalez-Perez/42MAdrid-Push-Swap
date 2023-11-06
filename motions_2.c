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

void	rra(t_list **head_a)
{
	t_list	*bfr_back;
	t_list	*back;
	t_list	*aux1;

	back = NULL;
	aux1 = *head_a;
	while (aux1 != NULL)
	{
		bfr_back = back;
		back = aux1;
		aux1 = aux1->nxt;
	}
	bfr_back->nxt = NULL;
	back->nxt = *head_a;
	*head_a = back;
	write(1, "rra\n", 4);
}

void	go_to_b(t_list **head_a, t_list **head_b, int *count)
{
	pb(head_a, head_b);
	(*count)++;
}

void	return_to_a(t_list **head_a, t_list **head_b, int *count)
{
	pa(head_a, head_b);
	(*count)--;
}
