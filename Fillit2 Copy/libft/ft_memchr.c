/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosgill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 15:04:03 by rosgill           #+#    #+#             */
/*   Updated: 2019/04/30 15:04:05 by rosgill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*a;

	i = 0;
	a = (unsigned char*)s;
	while (n > 0)
	{
		if (a[i] == (unsigned char)c)
		{
			return ((void *)&s[i]);
		}
		n--;
		i++;
	}
	return (NULL);
}
