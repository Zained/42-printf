/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_itoa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdriay <mdriay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 19:59:11 by mdriay            #+#    #+#             */
/*   Updated: 2015/03/11 13:39:52 by mdriay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_unsigned_itoa(unsigned long int n)
{
	char				*str;
	int					size;
	unsigned long int	x;

	x = n;
	size = 0;
	while (x >= 10)
	{
		x /= 10;
		size++;
	}
	str = (char *)malloc(sizeof(str) * (size + 1));
	if (str)
	{
		str[size + 1] = '\0';
		while (size >= 0)
		{
			x = n % 10;
			str[size] = 48 + x;
			n = n / 10;
			size--;
		}
	}
	return (str);
}
