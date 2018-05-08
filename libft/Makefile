# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtahirov <jtahirov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/11 13:01:35 by jtahirov          #+#    #+#              #
#    Updated: 2018/05/08 13:21:12 by jtahirov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re index

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

SRC = ft_isascii.c ft_memcmp.c ft_strchr.c ft_strlen.c ft_strrchr.c 		\
	  ft_atoi.c ft_isdigit.c ft_memcpy.c ft_strcmp.c ft_strncat.c 		\
	  ft_strstr.c ft_bzero.c ft_isprint.c ft_memmove.c ft_strcpy.c 		\
	  ft_strncmp.c ft_tolower.c ft_isalnum.c ft_memccpy.c ft_memset.c 	\
	  ft_strdup.c ft_strncpy.c ft_toupper.c ft_isalpha.c ft_memchr.c 		\
	  ft_strcat.c ft_strlcat.c ft_strnstr.c 								\
	  ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c 		\
	  ft_striter.c ft_striteri.c ft_strmap.c ft_putchar.c ft_putstr.c 	\
	  ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c 		\
	  ft_strtrim.c ft_putnbr.c ft_strsplit.c ft_itoa.c ft_putendl.c 		\
	  ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strnlen.c	\
	  ft_lstnew.c ft_lstdelone.c ft_lstadd.c ft_lstiter.c ft_lstmap.c 	\
	  ft_lstdel.c ft_bzero_bwd.c ft_memcpy_bwd.c ft_isspace.c ft_print2d.c 	\
	  ft_print_byte.c ft_bubblesort.c ft_print_array_int.c ft_lstpush.c \
	  ft_strnjoin.c ft_strrev.c ft_dectohex.c ft_dectooctal.c  ft_ltoa.c ft_strupper.c \
	  ft_isletter.c ft_iscapital.c ft_strmjoin.c ft_get_binary.c ft_wcharlen.c \
	  ft_get_next_line.c ft_print_object_bit.c ft_atoh.c ft_memjoin.c ft_getopt.c \
	  ft_hextodec.c ft_power.c ft_hextodata.c ft_modinv.c

DEPS = libft.h ./ft_printf/ft_printf.h
OBJECT = $(SRC:.c=.o)

PRINTF_DIR = ./ft_printf
FT_PRINTF =	ft_args.c ft_get_addr.c ft_get_char.c ft_printf_binary.c ft_get_hex.c \
			ft_get_number2.c ft_get_unumber2.c ft_get_wchar.c ft_get_wstr.c ft_printf.c \
			ft_dispatch.c ft_conversions.c ft_get_octal.c ft_get_str.c ft_wstr_helper.c ft_logic.c \
			ft_parse.c

FT_PRINTF_SRC = $(patsubst ft%,$(PRINTF_DIR)/ft%, $(FT_PRINTF))
PRINTF_OBJECT = $(FT_PRINTF_SRC:.c=.o)


all: $(NAME) index

%.o: %.c $(DEPS)
	@echo "\033[0;31m\c"
	$(CC) -c -o $@ $< $(CFLAGS)
	@echo "\033[0;m\c"

index: 
	@ranlib $(NAME)

$(NAME): $(OBJECT) $(PRINTF_OBJECT)
	@echo "\033[0;33m\c"
	ar rc $@ $^
	@echo "\033[0;m\c"

clean:
	@/bin/rm -f $(OBJECT) $(PRINTF_OBJECT) 

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

