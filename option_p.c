/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdriay <mdriay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 14:04:18 by mdriay            #+#    #+#             */
/*   Updated: 2015/03/11 14:15:11 by mdriay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		option_p(va_list ap, t_flag *f)
{
	char			*str;
	unsigned long	nb;
	int				rt;

	nb = va_arg(ap, unsigned long);
	str = ft_hexa_itoa(nb);
	if (f->cpt && !f->neg)
		rt = ft_putspace(f, (ft_strlen(str) + 2));
	ft_putstr("0x");
	ft_putstr(str);
	if (f->cpt && f->neg)
		rt = ft_putspace(f, (ft_strlen(str) + 2));
	if (f->cpt)
		return (ft_strlen(str) + 2 + rt);
	return (ft_strlen(str) + 2);
}
