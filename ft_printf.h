/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdriay <mdriay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 19:26:20 by mdriay            #+#    #+#             */
/*   Updated: 2015/03/11 13:38:20 by mdriay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <wchar.h>
# define OPT1 "sSpdDioOuUxXcC"
# define NUM "1234567890"

typedef	struct	s_flag
{
	int			flag;
	int			diese;
	int			zero;
	int			neg;
	int			space;
	int			plus;
	int			ell;
	int			ellell;
	int			ash;
	int			ashash;
	int			ji;
	int			zed;
	int			num;
	int			cpt;
	int			prec;
	int			cpt2;
	int			nb_prec;
	int			nopos;
}				t_flag;

int				ft_printf(const char *format, ...);
int				check_opt(char *str, int i, va_list ap, t_flag *f);
t_flag			*ft_init(char *str, int i);
t_flag			*check_flag1(char *str, int i, t_flag *f);
t_flag			*check_flag2(char *str, int i, t_flag *f);
t_flag			*check_enum(char *str, int i, t_flag *f);
t_flag			*check_prec(char *str, int i, t_flag *f);
int				ft_putchar(char c);
void			ft_putchar_w(void *mem, int size);
int				ft_print_special(wint_t c);
void			ft_putchar_fd(char c, int fd);
char			*ft_strcpy(char *dst, const char *src);
int				ft_putspace(t_flag *f, int nb);
int				ft_putsinglespace(int rt);
int				ft_putprecision(t_flag *f, int nb);
size_t			ft_strlen(const char *s);
size_t			ft_strlen_w(wchar_t *str);
void			ft_putnbrlong(long long nb);
void			ft_putnbr(int nb);
char			*ft_strchr(const char *s, int c);
char			*ft_strnew(size_t size);
void			ft_putlongnbr(long int nb);
void			ft_putstr(char const *s);
void			ft_putstr_w(wchar_t *str);
void			ft_putstr_fd(char const *s, int fd);
int				ft_nbrlen(int nb);
int				ft_nbrlonglen(long long nb);
int				ft_toupper(int c);
char			*ft_itoa(long int n);
char			*ft_unsigned_itoa(unsigned long int n);
char			*ft_octal_itoa(unsigned long long n);
char			*ft_hexa_itoa(unsigned long long n);
int				ft_atoi(const char *str);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
int				option_d_i(va_list ap, t_flag *f);
int				option_up_d(va_list ap);
int				option_c(va_list ap, t_flag *f);
int				option_up_c(va_list ap, t_flag *f);
int				option_s(va_list ap, t_flag *f);
int				option_up_s(va_list ap);
int				option_u(va_list ap, t_flag *f);
int				option_o(va_list ap, t_flag *f);
int				option_x(va_list ap, t_flag *f);
int				option_up_x(va_list ap, t_flag *f);
int				option_p(va_list ap, t_flag *f);

#endif
