#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdriay <mdriay@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/23 18:51:39 by mdriay            #+#    #+#              #
#    Updated: 2015/03/11 14:15:39 by mdriay           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a
MKEX = gcc -o
COMP = gcc -c
AR = ar -rc
SRC =	ft_printf.c \
		ft_check_option.c \
		ft_check_flag.c \
		ft_putspecial.c \
		ft_putspecial_large.c \
		option_di.c \
		option_up_d.c \
		option_c.c \
		option_s.c \
		option_uox.c \
		option_p.c \
		ft_base.c	\
		ft_base2.c \
		ft_base3.c \
		ft_toupper.c \
		ft_strsub.c \
		ft_atoi.c \
		ft_itoa.c \
		ft_unsigned_itoa.c \
		ft_octal_itoa.c \
		ft_hexa_itoa.c \


FLAGS = -Wall -Wextra -Werror
OBJECT = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJECT)
	@$(AR) $(NAME) $(OBJECT)
	@ranlib $(NAME)
	@echo "\033[32m$(NAME) OK ! \033[0m"

$(OBJECT) :
	@$(COMP) $(SRC) $(FLAGS)
	@echo "\033[33mCompilation OK\033[0m"

clean :
	@/bin/rm -f $(OBJECT)
	@echo "\033[33mObject deleted\033[0m"


fclean : clean
	@/bin/rm -f $(NAME)
	@echo "\033[33mExec deleted\033[0m"

re : fclean all