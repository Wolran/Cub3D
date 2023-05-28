/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuller <vmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 19:58:02 by vmuller           #+#    #+#             */
/*   Updated: 2023/05/28 19:59:08 by vmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minilibft.h"

static size_t	wordcount(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] != 0)
	{
		if (s[i] != c && s[i + 1] == c)
			count++;
		else if (s[i] != c && s[i + 1] == 0)
			count++;
		i++;
	}
	return (count);
}

static char	*init_word(char const *s, size_t idx, size_t len)
{
	char	*word;

	word = (char *)ft_calloc(sizeof(char), len + 1);
	if (word == 0)
		return (0);
	ft_strlcpy(word, s + idx, len + 1);
	return (word);
}

static int	check_null(char **arr, char *str)
{
	if (str == 0)
	{
		while (*arr != 0)
			free(*arr++);
		free(arr);
		arr = 0;
		return (1);
	}
	else
		return (0);
}

static void	start_split(char **arr, char const *s, char c, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	while (i < size)
	{
		if (s[j] != c)
		{
			k = 0;
			while (s[j + k] != c && s[j + k] != '\0')
				k++;
			arr[i] = init_word(s, j, k);
			if (check_null(arr, arr[i]) == 1)
				return ;
			j += k;
			i++;
		}
		else
			j++;
	}
	arr[i] = 0;
}

char	**ft_split(char const *s, char c)
{
	size_t	size;
	char	**arr;

	size = wordcount(s, c);
	arr = (char **)ft_calloc(sizeof(char *), (size + 1));
	if (arr == 0)
		return (0);
	start_split(arr, s, c, size);
	return (arr);
}
