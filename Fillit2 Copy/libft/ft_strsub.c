/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosgill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 15:14:58 by rosgill           #+#    #+#             */
/*   Updated: 2019/04/30 15:15:01 by rosgill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*out;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	out = ft_strnew(len);
	if (!out)
		return (NULL);
	while (i < len)
	{
		out[i] = s[start];
		start++;
		i++;
	}
	return (out);
}
