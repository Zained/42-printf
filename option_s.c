/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdriay <mdriay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 13:57:26 by mdriay            #+#    #+#             */
/*   Updated: 2015/03/11 14:13:10 by mdriay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		option_s(va_list ap, t_flag *f)
{
	char	*str;
	int		rt;

	rt = 0;
	str = va_arg(ap, char *);
	if (str == NULL || !str)
	{
		ft_putstr("(null)");
		return (ft_strlen("(null)"));
	}
	if (f->num && f->neg == 0)
		rt += ft_putspace(f, ft_strlen(str));
	ft_putstr(str);
	if (f->space == 1)
		return (ft_strlen(str));
	if (f->num)
		return (ft_strlen(str) + rt);
	return (ft_strlen(str));
}

int		option_up_s(va_list ap)
{
	wchar_t	*str;
	int		rt;
	size_t	i;

	i = 0;
	rt = 0;
	str = va_arg(ap, wchar_t *);
	if (!str || str == NULL)
	{
		ft_putstr("(null)");
		return (ft_strlen("(null)"));
	}
	while (i < ft_strlen_w(str))
	{
		rt += ft_print_special(str[i]);
		i++;
	}
	return (rt);
}
