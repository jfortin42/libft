# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfortin <jfortin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/24 10:29:00 by jfortin           #+#    #+#              #
#    Updated: 2018/06/25 15:26:14 by jfortin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror -MMD

ifeq ($(DEBUG),yes)
	CFLAGS += -g #-fsanitize=address
endif

NAME = libft.a

SRC = ft_atoi.c \
		ft_bzero.c \
		ft_error.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_lstadd.c \
		ft_lstdel.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_lstnew.c \
		ft_memalloc.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memdel.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar.c \
		ft_putchar_fd.c \
		ft_putendl.c \
		ft_putendl_fd.c \
		ft_putnbr.c \
		ft_putnbr_fd.c \
		ft_putstr.c \
		ft_putstr_fd.c \
		ft_strcat.c \
		ft_strchr.c \
		ft_strclr.c \
		ft_strcmp.c \
		ft_strcpy.c \
		ft_strdel.c \
		ft_strdup.c \
		ft_strequ.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlen.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strncat.c \
		ft_strncmp.c \
		ft_strncpy.c \
		ft_strnequ.c \
		ft_strnew.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strsplit.c \
		ft_strstr.c \
		ft_strsub.c \
		ft_strtrim.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_strnjoin.c \
		ft_strjoinfree.c \
		ft_readfile.c \
		ft_loadfile.c \
		get_next_line.c \
		ft_atof.c \
		ft_open.c \
		ft_read.c \
		ft_prot_malloc.c \
		ft_ret_error.c \
		ft_isblank.c

OBJ = $(SRC:.c=.o)
DPD = $(SRC:.c=.d)

opti:
		@$(MAKE) all -j

debug:
		@$(MAKE) DEBUG=yes

all: $(NAME)

$(NAME): $(OBJ)
		@echo "\033[2K \033[A"
		@ar rc $(NAME) $(OBJ)
		@echo "$(NAME) created"
		@ranlib $(NAME)
		@echo "$(NAME) indexed"

%.o: %.c
		@echo "\033[2K Compilation of $< \033[A"
		@gcc $(CFLAGS) -I includes -c $< -o $@

clean:
		@rm -f $(OBJ)
		@rm -f $(DPD)
		@echo "OBJ deleted"

fclean: clean
		@rm -f $(NAME)
		@echo "$(NAME) deleted"

re : fclean
		@$(MAKE) opti

.PHONY: clean

-include $(DPD)
