/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_uox.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdriay <mdriay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 13:59:35 by mdriay            #+#    #+#             */
/*   Updated: 2015/03/11 14:17:16 by mdriay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			option_u(va_list ap, t_flag *f)
{
	char				*str;
	unsigned long int	nb;
	int					tmp;
	int					rt;

	rt = 0;
	nb = va_arg(ap, unsigned long int);
	str = ft_unsigned_itoa(nb);
	tmp = ft_strlen(str);
	if (f->num)
		rt += ft_putspace(f, tmp);
	if (f->prec && tmp < f->nb_prec)
		rt += ft_putprecision(f, tmp);
	ft_putstr(str);
	return (rt + tmp);
}

int			option_o(va_list ap, t_flag *f)
{
	char			*str;
	long long int	nb;
	int				tmp;
	int				rt;

	rt = 0;
	nb = va_arg(ap, long long int);
	str = ft_octal_itoa(nb);
	if (f->diese == 1 && nb != 0)
		ft_putchar('0');
	tmp = ft_strlen(str);
	if (f->num)
		rt += ft_putspace(f, tmp);
	if (f->prec && tmp < f->nb_prec)
		rt += ft_putprecision(f, tmp);
	ft_putstr(str);
	if (f->diese == 1 && nb != 0)
		return (ft_strlen(str) + 1);
	return (rt + tmp);
}

int			option_x(va_list ap, t_flag *f)
{
	char				*str;
	unsigned long long	nb;
	int					rt;
	int					tmp;

	rt = 0;
	nb = va_arg(ap, unsigned long long);
	str = ft_hexa_itoa(nb);
	tmp = ft_strlen(str);
	if (f->diese == 1 && nb != 0)
		ft_putstr("0x");
	if (f->num)
		rt += ft_putspace(f, tmp);
	if (f->prec && tmp < f->nb_prec)
		rt += ft_putprecision(f, tmp);
	ft_putstr(str);
	if (f->diese == 1 && nb == 0)
		return (1);
	if (f->diese && nb)
		return (tmp + rt + 2);
	return (tmp + rt);
}

static	int	x_helper(t_flag *f, unsigned long long nb, int tmp, int rt)
{
	if (f->diese & nb)
		return (tmp + rt + 2);
	if (f->diese && !nb)
		return (1);
	return (tmp + rt);
}

int			option_up_x(va_list ap, t_flag *f)
{
	char				*str;
	unsigned long long	nb;
	int					rt;
	int					tmp;

	tmp = 0;
	rt = 0;
	nb = va_arg(ap, unsigned long long);
	str = ft_hexa_itoa(nb);
	while (str[tmp])
	{
		str[tmp] = ft_toupper(str[tmp]);
		tmp++;
	}
	tmp = ft_strlen(str);
	if (f->diese == 1 && nb != 0)
		ft_putstr("0X");
	if (f->num)
		rt += ft_putspace(f, tmp);
	if (f->prec && tmp < f->nb_prec)
		rt += ft_putprecision(f, tmp);
	ft_putstr(str);
	return (x_helper(f, nb, tmp, rt));
}
