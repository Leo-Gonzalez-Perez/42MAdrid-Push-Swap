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

char	*ft_strdup2(char *s1)
{
	size_t	i;
	char	*rtn;

	i = 0;
	while (s1[i] != '\0')
		i++;
	rtn = malloc(sizeof(char) * i + 1);
	if (rtn == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		rtn[i] = s1[i];
		i++;
	}
	rtn[i] = '\0';
	return (rtn);
}

int	ft_strlen2(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_atoi(char *str, int *ctrl)
{
	long long int	num;
	int				sign;

	*ctrl = 2;
	num = 0;
	sign = 1;
	if (!(*str))
		return (0);
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str && (*str >= '0' && *str <= '9'))
	{
		num = (*str - 48) + (num * 10);
		str++;
		*ctrl = 1;
	}
	if ((num * sign) > INT_MAX || (num * sign) < INT_MIN || *str != 0)
		*ctrl = 2;
	return (num * sign);
}
