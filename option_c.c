/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdriay <mdriay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 13:56:09 by mdriay            #+#    #+#             */
/*   Updated: 2015/03/24 14:19:39 by mdriay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		option_c(va_list ap, t_flag *f)
{
	int		i;
	char	c;

	i = 1;
	c = va_arg(ap, int);
	if (f->nopos)
		return (i);
	ft_putchar(c);
	return (i);
}

int		option_up_c(va_list ap, t_flag *f)
{
	wchar_t	c;
	int		rt;

	rt = 0;
	c = (wchar_t)va_arg(ap, wint_t);
	rt += ft_print_special(c);
	if (f->plus && c == '\0')
		return (rt);
	return (rt);
}
