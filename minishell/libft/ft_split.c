/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 12:17:02 by nporras-          #+#    #+#             */
/*   Updated: 2024/12/13 12:17:05 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int	total;
	int	word_found;

	total = 0;
	word_found = 0;
	while (*s)
	{
		if (*s != c && !word_found)
		{
			total++;
			word_found = 1;
		}
		else if (*s == c)
			word_found = 0;
		s++;
	}
	return (total);
}

static char	**ft_free(char **str, int index)
{
	while (index >= 0)
		free(str[index--]);
	free(str);
	return (NULL);
}

static char	*ft_write_word(size_t start, size_t end, const char *s)
{
	char	*str;
	size_t	i;

	str = malloc(sizeof(char) * (end - start) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (start < end)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

static char	**ft_fill_array(char const *s, char c, char **str)
{
	size_t	i;
	size_t	start;
	int		j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			start = i;
			while (s[i] && s[i] != c)
				i++;
			str[j] = ft_write_word(start, i, s);
			if (!str[j])
				return (ft_free(str, j - 1));
			j++;
		}
	}
	str[j] = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		total;

	if (!s)
		return (NULL);
	total = ft_count_words(s, c);
	str = malloc(sizeof(char *) * (total + 1));
	if (!str)
		return (NULL);
	return (ft_fill_array(s, c, str));
}
