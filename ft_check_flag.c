/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdriay <mdriay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 18:57:51 by mdriay            #+#    #+#             */
/*   Updated: 2015/03/10 21:56:55 by mdriay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flag		*ft_init(char *str, int i)
{
	t_flag *f;

	if (!(f = (t_flag *)malloc(sizeof(t_flag))))
		return (0);
	f->flag = 0;
	f->diese = 0;
	f->zero = 0;
	f->neg = 0;
	f->space = 0;
	f->plus = 0;
	f->ell = 0;
	f->ellell = 0;
	f->ash = 0;
	f->ashash = 0;
	f->ji = 0;
	f->zed = 0;
	f->num = 0;
	f->cpt = 0;
	f->prec = 0;
	f->cpt2 = 0;
	f->nb_prec = 0;
	f->nopos = 0;
	f = check_flag1(str, i, f);
	return (f);
}

t_flag		*check_flag1(char *str, int i, t_flag *f)
{
	int tmp;

	tmp = i;
	while (!ft_strchr(OPT1, str[i]))
	{
		if (str[i] == '#')
			f->diese = 1;
		if (str[i] == '-')
			f->neg = 1;
		if (str[i] == '+')
			f->plus = 1;
		if (str[i] == ' ')
			f->space = 1;
		if (str[i] == '0' && !(ft_strchr(NUM, str[i - 1])))
			f->zero = 1;
		i++;
	}
	f = check_enum(str, tmp, f);
	return (f);
}

t_flag		*check_enum(char *str, int i, t_flag *f)
{
	int tmp;
	int rt;

	rt = i;
	tmp = 0;
	while (!(ft_strchr(OPT1, str[i])) && str[i] != '.')
	{
		if (ft_strchr(NUM, str[i]))
		{
			tmp = i;
			break ;
		}
		i++;
	}
	if (f->zero == 1)
		f->cpt = -1;
	while (ft_strchr(NUM, str[i++]))
		f->cpt++;
	if (f->cpt)
		f->num = ft_atoi(ft_strsub(str, tmp, i));
	f = check_flag2(str, rt, f);
	return (f);
}

t_flag		*check_flag2(char *str, int i, t_flag *f)
{
	int tmp;

	tmp = i;
	while (!(ft_strchr(OPT1, str[i])))
	{
		if (str[i] == 'l' && str[i + 1] != 'l')
			f->ell = 1;
		if (str[i] == 'l' && str[i + 1] == 'l')
			f->ellell = 1;
		if (str[i] == 'h' && str[i + 1] != 'h')
			f->ash = 1;
		if (str[i] == 'h' && str[i + 1] == 'h')
			f->ashash = 1;
		if (str[i] == 'j')
			f->ji = 1;
		if (str[i] == 'z')
			f->zed = 1;
		i++;
	}
	f = check_prec(str, tmp, f);
	return (f);
}

t_flag		*check_prec(char *str, int i, t_flag *f)
{
	int tmp;

	tmp = 0;
	while (!(ft_strchr(OPT1, str[i])))
	{
		if (str[i - 1] == '.')
		{
			tmp = i;
			f->prec = 1;
			break ;
		}
		i++;
	}
	while (ft_strchr(NUM, str[i]))
	{
		i++;
		f->cpt2++;
	}
	if (f->cpt2)
		f->nb_prec = ft_atoi(ft_strsub(str, tmp, (i)));
	return (f);
}
