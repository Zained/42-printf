/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdriay <mdriay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 22:02:56 by mdriay            #+#    #+#             */
/*   Updated: 2015/03/11 16:19:13 by mdriay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	char	*ft_str_init(const char *format)
{
	char	*str;

	str = (char *)malloc(sizeof(char *) * (ft_strlen(format)) + 1);
	ft_strcpy(str, format);
	return (str);
}

static	int		ft_printf_flag(t_flag *f, int i)
{
	f->flag = f->ash + f->ashash + f->ji + f->zed + f->ell + \
	f->ellell + f->diese + f->neg + f->plus + f->zero + f->space + f->cpt;
	if (f->cpt2)
		f->flag += 1 + f->cpt2;
	if (f->flag)
		i += f->flag;
	return (i);
}

static	int		ft_printf_search(char *str, va_list ap)
{
	int		i;
	int		cpt;
	t_flag	*f;

	i = 0;
	cpt = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			f = ft_init(str, i);
			if (str[i] != '%')
				i = ft_printf_flag(f, i);
			cpt += check_opt(str, i, ap, f);
		}
		else
			cpt += 1 + ft_putchar(str[i]);
		i++;
	}
	return (cpt);
}

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	int			cpt;
	char		*str;

	cpt = 0;
	va_start(ap, format);
	str = ft_str_init(format);
	cpt = ft_printf_search(str, ap);
	va_end(ap);
	free(str);
	return (cpt);
}
