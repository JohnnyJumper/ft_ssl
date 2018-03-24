# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/03 17:27:11 by jtahirov          #+#    #+#              #
#    Updated: 2018/03/23 03:02:42 by jtahirov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I $(IDIR) -g
NAME = ft_ssl
IDIR = ./include

_DEPS = ft_ssl.h base64.h des.h ft_md5.h ft_sha224.h ft_sha256.h ft_rsa.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

SRC = ft_ssl.c utillity.c

BASE64_DIR = ./base64
BASE64_SRC = ft_base64.c ft_parse64.c ft_base64table.c ft_base64_decode.c ft_base64_encode.c
BASE64 = $(patsubst %, $(BASE64_DIR)/%, $(BASE64_SRC))

DES_DIR = ./des
DES_SRC = ft_des.c ft_des_utillity.c ft_des_parse.c ft_des_key.c ft_des_global.c ft_des_encode.c \
		  ft_des_subkey_routine.c ft_des_parseflags2.c ft_des_main.c
DES = $(patsubst %, $(DES_DIR)/%, $(DES_SRC))

MD5_DIR = ./md5
MD5_SRC = ft_md5.c ft_md5message.c ft_md5parse.c ft_md5global.c ft_md5algo.c ft_md5algofunc.c \
		  ft_md5_output.c ft_md5parse_helper.c
MD5 = $(patsubst %, $(MD5_DIR)/%, $(MD5_SRC))

SHA256_DIR = ./sha256
SHA256_SRC = ft_sha256.c ft_sha256message.c ft_sha256parse.c ft_sha256algo.c ft_sha256globals.c \
			 ft_sha256algo_helper.c ft_sha256_utillity.c ft_sha256output.c
SHA256 = $(patsubst %, $(SHA256_DIR)/%, $(SHA256_SRC))

SHA224_DIR = ./sha224
SHA224_SRC = ft_sha224.c ft_sha224message.c ft_sha224parse.c ft_sha224algo.c ft_sha224globals.c \
			 ft_sha224algo_helper.c ft_sha224_utillity.c ft_sha224output.c
SHA224 = $(patsubst %, $(SHA224_DIR)/%, $(SHA224_SRC))

RSA_DIR = ./rsa
RSA_SRC =  main.c random.c ft_primeq.c primeGeneration.c uttility.c
RSA = $(patsubst %, $(RSA_DIR)/%, $(RSA_SRC))

SRC_OBJ =$(SRC:.c=.o)
BASE64_OBJ = $(BASE64:.c=.o)
DES_OBJ = $(DES:.c=.o)
MD5_OBJ = $(MD5:.c=.o)
SHA256_OBJ = $(SHA256:.c=.o)
SHA224_OBJ = $(SHA224:.c=.o)
RSA_OBJ = $(RSA:.c=.o) utillity.o

OBJ = $(SRC_OBJ) $(BASE64_OBJ) $(DES_OBJ) $(MD5_OBJ) $(SHA256_OBJ) $(SHA224_OBJ) $(RSA_OBJ)
LIBS = ./libft/libft.a

all: $(NAME)

$(LIBS):
	@+$(MAKE) -C ./libft


%.o: %.c $(DEPS)
	@echo "\033[0;32m\c"
	$(CC) -c -o $@ $< $(CFLAGS)
	@echo "\033[0m\c"

$(NAME): $(OBJ) $(LIBS)
	@echo "\033[0;35m\c"
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)
	@echo "\033[0m\c"

rsa: $(BASE64_OBJ) $(RSA_OBJ) $(LIBS)
	@echo "\033[0;34m\c"
	$(CC) -o ft_ssl_$@ $^ $(CFLAGS) $(LIBS)
	@echo "\033[0m\c"

base64: $(BASE64_OBJ) $(LIBS)
	@echo "\033[0;34m\c"
	$(CC) -o ft_ssl_$@ $^ $(CFLAGS) $(LIBS)
	@echo "\033[0m\c"

des: $(DES_OBJ) $(LIBS)
	@echo "\033[0;34m\c"
	$(CC) -o ft_ssl_$@ $^ $(CFLAGS) $(LIBS)
	@echo "\033[0m\c"

md5: $(MD5_OBJ) $(LIBS)
	@echo "\033[0;34m\c"
	$(CC) -o ft_ssl_$@ $^ $(CFLAGS) $(LIBS)
	@echo "\033[0m\c"

clean:
	@/bin/rm -f $(OBJ)
	@+$(MAKE) clean -C ./libft

fclean: clean
	@/bin/rm -f $(NAME)
	@+$(MAKE) fclean -C ./libft


re: fclean all

.PHONY: clean fclean re
