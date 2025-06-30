/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <yanflous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:16:03 by ytabia            #+#    #+#             */
/*   Updated: 2025/06/30 11:15:07 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3D.h"


static int	count_words(const char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] != '\0')
			count++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (count);
}

static char	**memerror(char **result)
{
	int	i;

	i = 0;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free(result);
	return (NULL);
}

static size_t	get_word_len(char const *s, char c, size_t *start)
{
	size_t	word_len;

	word_len = 0;
	while (s[*start] == c)
		(*start)++;
	while (s[*start + word_len] && s[*start + word_len] != c)
		word_len++;
	return (word_len);
}

char	**ft_split(char const *s, char c)
{
	size_t	j;
	size_t	start;
	size_t	num_words;
	size_t	word_len;
	char	**result;

	if (!s)
		return (NULL);
	start = 0;
	j = 0;
	num_words = count_words(s, c);
	result = malloc(sizeof(char *) * (num_words + 1));
	if (!result)
		return (NULL);
	while (j < num_words)
	{
		word_len = get_word_len(s, c, &start);
		result[j] = ft_substr(s, start, word_len);
		if (!result[j])
			return (memerror(result));
		j++;
		start += word_len;
	}
	result[j] = NULL;
	return (result);
}
