/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosgill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 15:13:00 by rosgill           #+#    #+#             */
/*   Updated: 2019/04/30 15:13:04 by rosgill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	int i;

	i = 0;
	while (src[i] != '\0' && len != 0)
	{
		dst[i] = src[i];
		i++;
		len--;
	}
	while (len != 0)
	{
		dst[i] = '\0';
		i++;
		len--;
	}
	return (dst);
}
