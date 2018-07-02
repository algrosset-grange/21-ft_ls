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
SRCFOLDER= ./


SRCFILES=	ft_abs.c \
			ft_atof.c \
			ft_atoi.c \
			ft_bzero.c \
			ft_fclamp.c \
			ft_ftoa.c \
			ft_f_abs.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isnumber.c \
			ft_isprint.c \
			ft_isspace.c \
			ft_itoa.c \
			ft_lltoa.c \
			ft_lstadd.c \
			ft_lstaddend.c \
			ft_lstdel.c \
			ft_lstdelcontent.c \
			ft_lstdelone.c \
			ft_lstiter.c \
			ft_lstlen.c \
			ft_lstmap.c \
			ft_lstnew.c \
			ft_lstnewfrom.c \
			ft_lstreverse.c \
			ft_lstswap.c \
			ft_max.c \
			ft_memalloc.c \
			ft_memccpy.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memdel.c \
			ft_memmove.c \
			ft_memset.c \
			ft_min.c \
			ft_numlen.c \
			ft_numulen.c \
			ft_numullen.c \
			ft_putchar.c \
			ft_putchar_fd.c \
			ft_putendl.c \
			ft_putendl_fd.c \
			ft_putnbr.c \
			ft_putnbrendl.c \
			ft_putnbrendl_fd.c \
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
			ft_strtolower.c \
			ft_strtoupper.c \
			ft_strtrim.c \
			ft_swap.c \
			ft_swap_double.c \
			ft_tolower.c \
			ft_toupper.c \
			get_next_line.c

INCFOLDER=.
INCFILES=/libft.h
INC=$(addprefix $(INCFOLDER),$(INCFILES))

OBJFOLDER= obj/
OBJ=$(addprefix $(OBJFOLDER),$(subst .c,.o,$(SRCFILES)))
SRC=$(addprefix $(SRCFOLDER),$(SRCFILES))

EFLAGS=-Wall -Werror -Wextra

GREEN		=	\033[32m
RED			=	\033[31m
DEFAULT		=	\033[37m

.PHONY: all clean fclean re

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "$(GREEN)$(NAME)$(DEFAULT) created."

all: $(NAME)

$(OBJFOLDER)%.o: $(SRCFOLDER)%.c
	@if ! [ -d "$(OBJFOLDER)" ]; then mkdir $(OBJFOLDER); fi
	@gcc -c $< $(EFLAGS) $(IFLAGS) -o $@
	@echo "$(GREEN). $(DEFAULT)\c"

clean:
	@rm -rf $(OBJFOLDER)
	@echo "$(RED).o $(DEFAULT) are now deleted for $(NAME)."

fclean: clean
	@rm -rf $(OBJFOLDER)
	@rm	-f $(NAME)
	@echo "$(RED)$(NAME)$(DEFAULT) is now deleted."

re: fclean all
