/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnahid <tnahid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 12:15:29 by tnahid            #+#    #+#             */
/*   Updated: 2026/10/16 12:22:53 by tnahid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *str, char c)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i])
			count++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (count);
}

static char	*word_alloc(char const *str, char c)
{
	size_t	i;
	char	*arr;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	arr = (char *)malloc(i + 1);
	if (!arr)
		return (NULL);
	ft_strlcpy(arr, str, i + 1);
	return (arr);
}

static char	**free_arr(char **arr, size_t p)
{
	size_t	i;

	i = 0;
	while (i < p)
	{
		if (!arr[i])
		{
			while (p > 0)
				free(arr[--p]);
			free(arr);
			return (NULL);
		}
		i++;
	}
	return (arr);
}

char	**ft_split(char const *str, char c)
{
	size_t	i;
	size_t	p;
	char	**arr;

	if (!str)
		return (NULL);
	arr = (char **)malloc(sizeof(char *) * (count_words(str, c) + 1));
	if (!arr)
		return (NULL);
	i = 0;
	p = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i])
			arr[p++] = word_alloc(&str[i], c);
		while (str[i] && str[i] != c)
			i++;
	}
	arr[p] = NULL;
	arr = free_arr(arr, p);
	return (arr);
}
