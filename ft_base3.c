/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdriay <mdriay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 20:22:02 by mdriay            #+#    #+#             */
/*   Updated: 2015/03/11 13:31:55 by mdriay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_nbrlen(int nb)
{
	int i;

	i = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nb = -nb;
		i++;
	}
	while (nb)
	{
		i++;
		nb /= 10;
	}
	return (i);
}

int		ft_nbrlonglen(long long nb)
{
	int i;

	i = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nb = -nb;
		i++;
	}
	while (nb)
	{
		i++;
		nb /= 10;
	}
	return (i);
}

char	*ft_strnew(size_t size)
{
	char	*new;
	size_t	i;

	if ((new = (char *)malloc(sizeof(char) * size + 1)))
	{
		i = 0;
		while (i < size + 1)
		{
			new[i] = '\0';
			i++;
		}
		return (new);
	}
	return (NULL);
}
