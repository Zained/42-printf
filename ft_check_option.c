/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_option.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdriay <mdriay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 18:52:09 by mdriay            #+#    #+#             */
/*   Updated: 2015/03/10 22:08:13 by mdriay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		check_opt_helper(char *str, int i, va_list ap, t_flag *f)
{
	if (str[i] == 'o' || str[i] == 'O')
		return (option_o(ap, f));
	else	if (str[i] == 'x')
		return (option_x(ap, f));
	else	if (str[i] == 'X')
		return (option_up_x(ap, f));
	else	if (str[i] == 'p')
		return (option_p(ap, f));
	else	if (str[i] == '%')
	{
		ft_putchar(str[i]);
		return (1);
	}
	else	if (str[i])
	{
		ft_putchar(str[i]);
		return (1);
	}
	return (0);
}

int				check_opt(char *str, int i, va_list ap, t_flag *f)
{
	if (str[i] == 'd' || str[i] == 'i')
		return (option_d_i(ap, f));
	else	if (str[i] == 'D')
		return (option_up_d(ap));
	else	if (str[i] == 'c' && !f->ell)
		return (option_c(ap, f));
	else	if (str[i] == 'C' || (str[i] == 'c' && f->ell))
		return (option_up_c(ap, f));
	else	if (str[i] == 's')
		return (option_s(ap, f));
	else	if (str[i] == 'S')
		return (option_up_s(ap));
	else	if (str[i] == 'u' || str[i] == 'U')
		return (option_u(ap, f));
	else
		return (check_opt_helper(str, i, ap, f));
	return (0);
}
