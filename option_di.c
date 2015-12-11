/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_di.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdriay <mdriay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 13:41:06 by mdriay            #+#    #+#             */
/*   Updated: 2015/03/11 15:40:37 by mdriay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		ft_putsign(int neg)
{
	int rt;

	rt = 0;
	if (neg == 0)
		ft_putchar('-');
	if (neg == 1)
	{
		ft_putchar('+');
		rt += 1;
	}
	return (rt);
}

static	t_flag	*ft_checksign(int e, long long int d, t_flag *f)
{
	if (e != 0)
		if (e < 0)
			f->nopos = 1;
	if (d != 0)
		if (d < 0)
			f->nopos = 1;
	return (f);
}

static	void	option_d_intmin(int e, long long int d, t_flag *f)
{
	if (e < 0 && d == 0)
	{
		if (e == -2147483648)
			ft_putstr("2147483648");
		else
		{
			e = -e;
			if (!f->neg)
				ft_putnbr(e);
		}
	}
	else	if (d < 0 && e == 0)
	{
		if (d < 9223372036854775807)
			ft_putstr("9223372036854775808");
		else
		{
			d = -d;
			if (!f->neg)
				ft_putnbrlong(d);
		}
	}
	else	if (!f->neg)
		e == 0 ? ft_putnbrlong(d) : ft_putnbr(e);
}

static	int		option_d_helper(t_flag *f, int tmp, int e, long long int d)
{
	int	rt;

	rt = 0;
	if (f->neg)
		d == 0 ? ft_putnbr(e) : ft_putnbrlong(d);
	if (f->space && !f->nopos && !f->plus)
		rt += ft_putsinglespace(rt);
	if (f->num)
		rt += ft_putspace(f, tmp);
	if (!f->neg && !f->zero)
		if (f->plus || e < 0 || d < 0)
			rt += (f->nopos == 1 ? ft_putsign(0) : ft_putsign(1));
	if (f->prec && tmp < f->nb_prec)
		rt += ft_putprecision(f, tmp);
	option_d_intmin(e, d, f);
	return (rt);
}

int				option_d_i(va_list ap, t_flag *f)
{
	int				e;
	long long int	d;
	int				rt;
	int				tmp;

	rt = 0;
	e = 0;
	d = 0;
	if (f->ell || f->ellell || f->ji || f->zed)
		d = va_arg(ap, long long int);
	else
		e = va_arg(ap, int);
	f = ft_checksign(e, d, f);
	tmp = (e == 0 ? ft_nbrlonglen(d) : ft_nbrlen(e));
	rt = option_d_helper(f, tmp, e, d);
	return (tmp + rt);
}
