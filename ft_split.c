/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseltenr <kseltenr@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 00:37:03 by kseltenr          #+#    #+#             */
/*   Updated: 2026/09/29 11:23:21 by kseltenr        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_alloc_split(char const *s, char c)
{
	size_t	i;
	char	**split;
	size_t	total;
	int		in_word;

	i = 0;
	total = 0;
	in_word = 0;
	while (s[i])
	{
		if (s[i] != c && !in_word)
		{
			in_word = 1;
			total++;
		}
		else if (s[i] == c)
			in_word = 0;
		i++;
	}
	split = (char **)malloc(sizeof(char *) * (total + 1));
	if (!split)
		return (NULL);
	return (split);
}

void	*ft_free_all_split_alloc(char **split, size_t elts)
{
	size_t	i;

	i = 0;
	while (i < elts)
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (NULL);
}

static void	*f(char **split, char const *s, t_split_next *st, t_split_next *lt)
{
	split[lt->length] = ft_substr(s, st->start, st->length);
	if (!split[lt->length])
		return (ft_free_all_split_alloc(split, lt->length));
	lt->length++;
	return (split);
}

static void	*ft_split_by_char(char **split, char const *s, char c)
{
	size_t			i;
	t_split_next	st;
	t_split_next	lt;

	i = 0;
	lt.length = 0;
	lt.start = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			st.start = lt.start;
			st.length = (i - lt.start);
			if (i > lt.start && !f(split, s, &st, &lt))
				return (NULL);
			lt.start = i + 1;
		}
		i++;
	}
	st.start = lt.start;
	st.length = (i - lt.start);
	if (i > lt.start && !f(split, s, &st, &lt))
		return (NULL);
	split[lt.length] = 0;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;

	split = ft_alloc_split(s, c);
	if (!split)
		return (NULL);
	if (!ft_split_by_char(split, s, c))
		return (NULL);
	return (split);
}
