/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosgill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 12:02:25 by rosgill           #+#    #+#             */
/*   Updated: 2019/08/05 12:04:16 by rosgill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
int     main(int argc, char **argv)
{
    if (argc != 2)
    {
        ft_putstr("Input 1 text file");
        return (1);
    }
    if (parse(argv[1]) == -1)
    {
        ft_putstr("error");
        return (0);
    }
    return (0);
}