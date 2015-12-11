/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdriay <mdriay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 22:09:15 by mdriay            #+#    #+#             */
/*   Updated: 2015/03/11 16:27:27 by mdriay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//#include <locale.h>

int	main()
{
//	int i;
//	char *s = setlocale(LC_ALL, "en_US.UTF-8");
//	wchat_t x[] = L"ææäåç";
//	if (s == NULL)
//		printf("Locale not set\n");
//	else
//		printf("Locale set to %s\n", s);
	printf(" -- count %d\n", i = ft_printf("{%d}", 42));
	printf(" -- count %d\n", i = printf("{%d}", 42));
	return (0);
}
