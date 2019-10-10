/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosgill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 15:11:35 by rosgill           #+#    #+#             */
/*   Updated: 2019/04/30 15:11:38 by rosgill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*out;

	i = 0;
	if (!s || !f)
		return (NULL);
	out = (char *)malloc(sizeof(*out) * (ft_strlen(s) + 1));
	if (!out)
		return (NULL);
	while (s[i])
	{
		out[i] = (*f)(s[i]);
		i++;
	}
	out[i] = '\0';
	return (out);
}
