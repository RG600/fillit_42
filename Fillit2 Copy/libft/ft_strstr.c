/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosgill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 15:14:41 by rosgill           #+#    #+#             */
/*   Updated: 2019/04/30 15:14:44 by rosgill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*result;
	int		numb[3];

	numb[0] = 0;
	numb[1] = 0;
	if (needle[numb[0]] == '\0')
		return ((char *)haystack);
	while (haystack[numb[1]] != '\0')
	{
		numb[2] = numb[1];
		while (needle[numb[0]] == haystack[numb[2]])
		{
			if (needle[numb[0] + 1] == '\0')
			{
				result = (char *)&haystack[numb[1]];
				return (result);
			}
			numb[0]++;
			numb[2]++;
		}
		numb[0] = 0;
		numb[1]++;
	}
	return (NULL);
}
