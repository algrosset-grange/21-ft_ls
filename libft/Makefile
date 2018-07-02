# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agrosset <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/29 10:23:41 by agrosset          #+#    #+#              #
#    Updated: 2016/08/16 16:26:43 by agrosset         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a
INPUT=	ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strlen.c \
		ft_strdup.c \
		ft_strcpy.c \
		ft_strncpy.c \
		ft_strcat.c \
		ft_strncat.c \
		ft_strlcat.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strstr.c \
		ft_strnstr.c \
		ft_strcmp.c \
		ft_strncmp.c \
		ft_atof.c \
		ft_atoi.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_isnumber.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_memalloc.c \
		ft_memdel.c \
		ft_strnew.c \
		ft_strdel.c \
		ft_strclr.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strequ.c \
		ft_strnequ.c \
		ft_strsub.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_strsplit.c \
		ft_itoa.c \
		ft_ftoa.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_putendl.c \
		ft_putnbr.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_isspace.c \
		ft_abs.c \
		ft_f_abs.c \
		ft_max.c \
		ft_min.c \
		ft_lstnew.c \
		ft_lstnewfrom.c \
		ft_lstdelone.c \
		ft_lstdel.c \
		ft_lstadd.c \
		ft_lstaddend.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_lstlen.c \
		ft_lstreverse.c \
		ft_lstswap.c \
		ft_putnbrendl.c \
		ft_putnbrendl_fd.c \
		ft_strtolower.c \
		ft_strtoupper.c \
		get_next_line.c \
		ft_fclamp.c \
		ft_swap.c \
		ft_swap_double.c \
		ft_numlen.c \
		ft_numullen.c \
		ft_numulen.c \
		ft_lltoa.c

OBJ=$(subst .c,.o,$(INPUT))
FLAGS=-Wall -Werror -Wextra

GREEN		=	\033[32m
RED			=	\033[31m
DEFAULT		=	\033[37m

.PHONY: all clean fclean re

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "$(GREEN)$(NAME)$(DEFAULT) created."

all: $(NAME)

%.o: %.c
	@gcc -c $(FLAGS) $< -o $@
	@echo "$(GREEN). $(DEFAULT)\c"

clean:
	@rm -f $(OBJ)
	@echo "$(RED).o $(DEFAULT) are now deleted for $(NAME)."

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)$(NAME)$(DEFAULT) is now deleted."

re: fclean all
