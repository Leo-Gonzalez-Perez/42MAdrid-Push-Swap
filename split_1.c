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

char	*ft_substr(char *str, int start, size_t len)
{
	size_t	count;
	size_t	size;
	char	*rtn;

	if (str == NULL)
		return (NULL);
	if (ft_strlen2(str) < start)
		return (ft_strdup2(""));
	size = ft_strlen2(str + start);
	if (size < len)
		len = size;
	rtn = (char *)malloc((len + 1) * sizeof(char));
	if (rtn == NULL)
		return (NULL);
	count = 0;
	while (count < len)
	{
		rtn[count] = str[start + count];
		count++;
	}
	rtn[count] = '\0';
	return (rtn);
}

void	ft_free(char **str)
{
	int	i;

	i = -1;
	while (str != NULL && str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

size_t	count_words(char *s, char c)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	while (s[i] != '\0')
	{
		if ((s[i + 1] == c || s[i + 1] == '\0') && s[i] != c)
			words++;
		i++;
	}
	return (words);
}

char	**write_result(char *str, char c, char	**res)
{
	size_t	start;
	size_t	i;
	size_t	word;

	start = 0;
	i = 0;
	word = 0;
	while (str[i] != 0)
	{
		if ((str[i + 1] == c || str[i + 1] == '\0') && str[i] != c)
		{
			res[word] = ft_substr(str, start, i - start + 1);
			if (!res[word])
			{
				ft_free(res);
				return (0);
			}
			word++;
		}
		if (str[i] == c && (str[i + 1] != c || str[i + 1] != '\0'))
			start = i + 1;
		i++;
	}
	res[word] = 0;
	return (res);
}

char	**ft_split(char *str, char c, int *error)
{
	size_t	i;
	char	**res;

	i = 0;
	res = (char **)malloc(sizeof(char *) * (count_words(str, c) + 1));
	if (res == 0)
		*error = 2;
	else
		res = write_result(str, c, res);
	return (res);
}
