# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnbou <rnbou@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/05 13:08:42 by ielmoudn          #+#    #+#              #
#    Updated: 2021/03/17 17:39:07 by rnbou            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = ft_printf.a
FILENAMES = ft_printf.c\
	ft_printf2.c\
	ft_printf_base.c\
	ft_printf_d.c\
	ft_printf_f1.c\
	ft_printf_f_int.c\
	ft_printf_f_multiply.c\
	ft_printf_p.c\
	ft_printf_s.c\
	ft_printf_ts.c\
	ft_printf1.c\
	ft_printf3.c\
	ft_printf_c.c\
	ft_printf_f.c\
	ft_printf_f2.c\
	ft_printf_f_int1.c\
	ft_printf_f_multiply1.c\
	ft_printf_pr.c\
	ft_printf_td.c\
	ft_printf_u.c\
	helpers.c\
	ft_atoi.c\
	ft_atoi_base.c\
	ft_bzero.c\
	ft_dup.c\
	ft_isalnum.c \
	ft_isalpha.c\
	ft_isascii.c\
	ft_isdigit.c\
	ft_islower.c\
	ft_isprint.c\
	ft_isupper.c\
	ft_itoa.c\
	ft_itoa_base.c\
	ft_lstadd.c\
	ft_lstaddend.c \
	ft_lstdel.c\
	ft_lstdelone.c\
	ft_lstiter.c\
	ft_lstmap.c\
	ft_lstnew.c \
	ft_memalloc.c\
	ft_memccpy.c\
	ft_memchr.c\
	ft_memcmp.c\
	ft_memcpy.c \
	ft_memdel.c\
	ft_memmove.c\
	ft_memset.c\
	ft_putchar.c\
	ft_putchar_fd.c \
	ft_putendl.c\
	ft_putendl_fd.c\
	ft_putnbr.c\
	ft_putnbr_fd.c\
	ft_putstr.c \
	ft_putstr_fd.c\
	ft_strcat.c\
	ft_strchr.c\
	ft_strclr.c\
	ft_strcmp.c \
	ft_strcntfirstchar.c\
	ft_strcntlastchar.c\
	ft_strcpy.c\
	ft_strdel.c\
	ft_strdup.c\
	ft_strequ.c\
	ft_striter.c\
	ft_striteri.c\
	ft_strjoin.c \
	ft_strlcat.c\
	ft_strlen.c\
	ft_strmap.c\
	ft_strmapi.c\
	ft_strncat.c \
	ft_strncmp.c\
	ft_strncpy.c\
	ft_strnequ.c\
	ft_strnew.c\
	ft_strnstr.c \
	ft_strrchr.c\
	ft_strrev.c\
	ft_strsplit.c\
	ft_strsplitchrset.c\
	ft_strstr.c\
	ft_strsub.c\
	ft_strtrim.c\
	ft_tolower.c\
	ft_toupper.c
	



OBJ =$(FILENAMES:.c=.o)

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(SRCS)
	@gcc $(FLAGS) -c $(FILENAMES)
	@ar rc $(NAME) $(OBJ) 

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all



