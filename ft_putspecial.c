/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putspecial.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdriay <mdriay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 19:31:01 by mdriay            #+#    #+#             */
/*   Updated: 2015/03/10 19:39:31 by mdriay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_define_i(t_flag *f, int nb)
{
	int i;

	i = 0;
	if (f->prec && nb > f->nb_prec)
		i = nb;
	else	if (f->prec && (f->num <= f->nb_prec))
		i = f->num;
	else	if (f->prec && (f->num > f->nb_prec))
		i = f->nb_prec;
	else	if (!f->prec)
		i = nb;
	if (f->prec && f->nopos && nb < f->nb_prec)
		i++;
	if (f->space)
		i++;
	return (i);
}

int			ft_putspace(t_flag *f, int nb)
{
	int i;
	int rt;

	i = ft_define_i(f, nb);
	rt = 0;
	if (f->zero && f->nopos)
		ft_putchar('-');
	if (f->zero && f->plus)
	{
		ft_putchar('+');
		i++;
		rt++;
	}
	while (i < f->num)
	{
		if (f->zero && !f->prec)
			ft_putchar('0');
		else
			ft_putchar(' ');
		i++;
		rt++;
	}
	return (rt);
}

int			ft_putprecision(t_flag *f, int nb)
{
	int i;
	int rt;

	i = nb;
	rt = 0;
	if (f->nopos)
		i--;
	while (i < f->nb_prec)
	{
		ft_putchar('0');
		i++;
		rt++;
	}
	return (rt);
}

int			ft_putsinglespace(int rt)
{
	ft_putchar(' ');
	rt++;
	return (rt);
}
