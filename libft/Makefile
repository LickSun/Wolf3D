# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmidori <lmidori@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/12 13:12:44 by lmidori           #+#    #+#              #
#    Updated: 2020/07/05 15:30:03 by lmidori          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC_MAN = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memccpy.c ft_memchr.c \
ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c \
ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_strjoin.c \
ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c

BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
ft_lstclear.c ft_lstiter.c ft_lstmap.c

HEADER = libft.h

MAN_OBJ = $(SRC_MAN:.c=.o)
BONUS_OBJ = $(BONUS:.c=.o)

FLAGS = -Wall -Wextra -Werror
BUILD = @ar rc $(NAME)
INDEX = @ranlib $(NAME)

all: $(NAME)

$(NAME):$(MAN_OBJ)
	$(BUILD) $(MAN_OBJ) $(HEADER)
	$(INDEX)

%.o: %.c
	@gcc $(FLAGS) -c $< -o $@

clean:
	@rm -f *.o

fclean: clean
	@rm -f libft.a

re:fclean all

bonus:$(NAME) $(BONUS_OBJ)
	$(BUILD) $(BONUS_OBJ) $(HEADER)
	$(INDEX)