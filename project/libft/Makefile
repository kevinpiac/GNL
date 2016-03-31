#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/02 15:06:24 by kpiacent          #+#    #+#              #
#    Updated: 2016/03/07 13:49:28 by kpiacent         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = gcc
FLAGS = -Wall -Wextra -Werror
NAME = libft.a
FILES = ft_putchar.c ft_putchar_fd.c ft_putstr.c ft_putstr_fd.c ft_putendl.c ft_putendl_fd.c \
		ft_putnbr.c ft_putnbr_fd.c \
\
		ft_strlen.c ft_strlcat.c ft_strcmp.c ft_strncmp.c ft_strdup.c ft_strstr.c ft_strnstr.c ft_strcpy.c ft_strncpy.c ft_striter.c ft_striteri.c ft_strchr.c ft_strrchr.c ft_strjoin.c ft_strtrim.c ft_strsub.c ft_strmap.c ft_strmapi.c ft_strsplit.c \
\
		ft_islower.c ft_isupper.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isprint.c ft_isascii.c ft_strequ.c ft_strnequ.c ft_istoskip.c \
\
		ft_toupper.c ft_tolower.c ft_atoi.c ft_itoa.c ft_strcat.c ft_strncat.c \
\
		ft_memalloc.c ft_memset.c ft_memdel.c ft_memcpy.c ft_memccpy.c ft_strnew.c ft_strdel.c ft_strclr.c ft_bzero.c ft_memchr.c ft_memcmp.c ft_memmove.c \
\
		ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_lstput.c ft_lstputendl.c ft_lstaddback.c \
\
		ft_bitprint.c ft_bitgetfour.c ft_bitsetfour.c ft_bitgetoctal.c ft_bitsetoctal.c

OBJ = $(FILES:.c=.o)
TMP = Makefile~ libft.h~ $(NAME)~ $(FILES:.c=.c~)

all : $(NAME)

$OBJ : $(FILES)
		$(CC) $(FLAGS) -c $(FILES)

$(NAME) : $(OBJ)
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)
clean :
	rm -f $(OBJ) $(TMP)

fclean : clean
	rm -f $(NAME)

re : fclean all

test :
	gcc -o a.out main.c -L ./ -lft && ./a.out

testclean :
	rm -f a.out

testre : testclean test

.PHONY : clean fclean re