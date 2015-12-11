/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_up_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdriay <mdriay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 13:54:45 by mdriay            #+#    #+#             */
/*   Updated: 2015/03/11 14:14:32 by mdriay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		option_up_d(va_list ap)
{
	long int	d;
	char		*str;

	d = va_arg(ap, long int);
	str = ft_itoa(d);
	ft_putstr(str);
	return (ft_strlen(str));
}
