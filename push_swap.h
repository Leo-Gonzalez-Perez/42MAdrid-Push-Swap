/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgonzal2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 19:08:13 by lgonzal2          #+#    #+#             */
/*   Updated: 2023/03/08 19:17:11 by lgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

struct s_nodo
{
	int				in;
	int				nbr;
	struct s_nodo	*nxt;
};
typedef struct s_nodo	t_list;

void	sb(t_list **head_b);
void	sa(t_list **head_a);
void	rra(t_list **head_a);
void	order_two_nodes(t_list **head_a);
void	order_three_nodes(t_list **head_a, int aux);
void	order_four_nodes(t_list **head_a, t_list **head_b);
void	order_five_nodes(t_list **head_a, t_list **head_b);
void	ra(t_list **head_a);
void	pa(t_list **head_a, t_list **head_b);
void	pb(t_list **head_a, t_list **head_b);
void	go_to_b(t_list **head_a, t_list **head_b, int *count);
void	return_to_a(t_list **head_a, t_list **head_b, int *count);
void	ordering(t_list **head_a, t_list **head_b, int nbr_nodes);
void	in_to_nbr(t_list *head_a);
int		ft_atoi(char *str, int *ctrl);
char	*ft_strdup2(char *s1);
int		ft_strlen2(const char *s);
char	*ft_substr(char *str, int start, size_t len);
void	ft_free(char **str);
size_t	count_words(char *s, char c);
char	**write_result(char *str, char c, char	**res);
char	**ft_split(char *str, char c, int *error);
t_list	*create_nodes(char **a_split, t_list **head_a, int *error);
void	main_2(int argc, char **argv, t_list **head_a, int *error);
int		count_nodes(t_list *head_a);
int		is_set_in_order(t_list *head_a);
int		repeating_nbr(t_list *head_a);
int		verify_errors(t_list *head_a);
void	nodes_free(t_list **head_a);
void	select_algorithm(t_list **head_a, t_list *head_b, int nbr_nodes);
int		manage_errors(t_list *head_a, int error);

#endif