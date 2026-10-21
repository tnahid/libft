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

static int	count_words(const char *str, char c)
{
	int		wrd;
	int		count;
	size_t	i;

	count = 0;
	i = 0;
	wrd = 1;
	while (str[i])
	{
		if (str[i] == c)
			wrd = 1;
		else
		{
			if (wrd == 1)
				count++;
			wrd = 0;
		}
		i++;
	}
	return (count);
}

static char	*word_alloc(const char *str, char c)
{
	char	*arr;
	size_t	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	arr = (char *)malloc(i + 1);
	if (arr == NULL)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != c)
	{
		arr[i] = str[i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}

char	**ft_split(const char *str, char c)
{
	int		wrd;
	size_t	p;
	size_t	i;
	char	**arr;

	p = 0;
	i = 0;
	wrd = 1;
	arr = (char **)malloc(sizeof(char *) * (count_words(str, c) + 1));
	if (arr == NULL)
		return (NULL);
	while (str[i])
	{
		if (str[i] == c)
			wrd = 1;
		else
		{
			if (wrd == 1)
				arr[p++] = word_alloc(&str[i], c);
			wrd = 0;
		}
		i++;
	}
	arr[p] = NULL;
	return (arr);
}
