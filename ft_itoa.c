/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdriay <mdriay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 20:02:40 by mdriay            #+#    #+#             */
/*   Updated: 2015/03/11 13:33:00 by mdriay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		ft_nb_count(long int n, int i)
{
	while (n > 9 || n < 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char			*ft_itoa(long int n)
{
	char		*nbstr;
	char		*nbcut;
	int			nblen;
	long int	nb;
	int			i;

	nblen = (n < 0) ? 2 : 1;
	nb = n;
	i = ft_nb_count(n, nblen);
	nbcut = ft_strnew(i + 1);
	while (i > 0)
	{
		if (n >= 0)
			nbcut[i - 1] = ((char)((nb % 10) + 48));
		if (n < 0 && i >= 2)
			nbcut[i - 2] = ((char)(48 - (nb % 10)));
		i--;
		nb /= 10;
	}
	if (n < 0)
		nbcut[i] = '-';
	nbstr = ft_strnew(ft_nb_count(n, nblen) + 1);
	ft_strcpy(nbstr, nbcut);
	free(nbcut);
	return (nbstr);
}
