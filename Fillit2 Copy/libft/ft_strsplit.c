/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosgill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 15:14:27 by rosgill           #+#    #+#             */
/*   Updated: 2019/04/30 15:14:31 by rosgill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		wordcounter(char const *s, char c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (!s || !c)
		return (0);
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != '\0')
			j++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (j);
}

static	char	*splithelp(const char *str, size_t i, size_t *j)
{
	char *out;

	out = ft_strsub(str, i - *j, *j);
	out[*j] = '\0';
	*j = 0;
	return (out);
}

static	void	splithelp2(const char *s, char c, size_t *i, size_t *j)
{
	while (s[*i] == c && s[*i] != '\0')
		(*i)++;
	while (s[*i] != c && s[*i] != '\0')
	{
		(*j)++;
		(*i)++;
	}
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;
	int		words;
	char	**out;

	i = 0;
	j = 0;
	k = 0;
	if (!s)
		return (NULL);
	words = wordcounter(s, c);
	if (!(out = (char**)malloc(sizeof(*out) * (words + 1))))
		return (NULL);
	while (s[i] != '\0')
	{
		splithelp2(s, c, &i, &j);
		if (j)
			out[k++] = splithelp(s, i, &j);
	}
	out[k] = 0;
	return (out);
}
