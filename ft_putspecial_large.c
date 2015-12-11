/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putspecial_large.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdriay <mdriay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 19:40:09 by mdriay            #+#    #+#             */
/*   Updated: 2015/03/11 13:53:53 by mdriay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_print_special_3(char str[4], wint_t c)
{
	str[0] = (((c & 0x1c0000) >> 18) + 0xF0);
	str[1] = (((c & 0x03F000) >> 12) + 0x80);
	str[2] = (((c & 0x0Fc0) >> 6) + 0x80);
	str[3] = ((c & 0x003F) + 0x80);
	ft_putchar_w(str, 4);
	return (4);
}

static	int	ft_print_special_2(char str[4], wint_t c)
{
	str[0] = (((c & 0xF000) >> 12) + 0xE0);
	str[1] = (((c & 0x0Fc0) >> 6) + 0x80);
	str[2] = ((c & 0x003F) + 0x80);
	ft_putchar_w(str, 3);
	return (3);
}

static	int	ft_print_special_1(char str[4], wint_t c)
{
	str[0] = (((c & 0x07c0) >> 6) + 0xc0);
	str[1] = ((c & 0x003F) + 0x80);
	ft_putchar_w(str, 2);
	return (2);
}

int			ft_print_special(wint_t c)
{
	char	str[4];
	int		rt;

	rt = 1;
	if (c <= 0x7F)
		ft_putchar_w(&c, 1);
	else	if (c <= 0x7FF)
		rt = ft_print_special_1(str, c);
	else	if (c <= 0xFFFF)
		rt = ft_print_special_2(str, c);
	else	if (c <= 0x10FFFF)
		rt = ft_print_special_3(str, c);
	return (rt);
}

void		ft_putchar_w(void *mem, int size)
{
	char	*str;
	int		i;

	str = mem;
	i = 0;
	while (i < size)
	{
		write(1, str + i, 1);
		i++;
	}
}
