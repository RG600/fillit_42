/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosgill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 15:13:37 by rosgill           #+#    #+#             */
/*   Updated: 2019/04/30 15:13:40 by rosgill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*result;
	size_t	i;

	i = 0;
	result = (char*)malloc(sizeof(*result) * size + 1);
	if (!result)
		return (NULL);
	else
	{
		while (i <= size)
		{
			result[i] = '\0';
			i++;
		}
		return (result);
	}
}
