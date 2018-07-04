# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acoudray <acoudray@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/25 12:44:37 by agrosset          #+#    #+#              #
#    Updated: 2018/02/14 14:32:54 by acoudray         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=ft_ls
SRCFOLDER= srcs/

SRCFILES= \
			fd_sort.c \
			fd_utility.c \
			ft_print_multi.c \
			main.c \
			multi.c \
			permissions.c \
			print_l.c \
			printlong.c \
			printlong_2.c \
			printsort.c \
			print_process.c \
			single.c \
			sort.c \
			utility.c \
			utility_2.c

INCFOLDER=./includes
INCFILES=/ftls.h
INC=$(addprefix $(INCFOLDER),$(INCFILES))

OBJFOLDER=obj/
OBJ=$(addprefix $(OBJFOLDER),$(subst .c,.o,$(SRCFILES)))
SRC=$(addprefix $(SRCFOLDER),$(SRCFILES))

LIBFTFOLDER=./libft
LIBFT=$(LIBFTFOLDER)/libft.a

EFLAGS=-Wall -Werror -Wextra -g
IFLAGS=-I$(LIBFTFOLDER) -I$(INCFOLDER)

GREEN		=	\033[32m
RED			=	\033[31m
DEFAULT		=	\033[37m

.PHONY: all clean fclean re

$(NAME): $(LIBFT) $(OBJ)
	@gcc -o $(NAME) $(OBJ) $(LIBFT)
	@echo "$(GREEN)$(NAME)$(DEFAULT) created."
	@$(EDITLIB)

all: $(NAME)

$(OBJFOLDER)%.o: $(SRCFOLDER)%.c
	@if ! [ -d "$(OBJFOLDER)" ]; then mkdir $(OBJFOLDER); fi
	@gcc -c $< $(EFLAGS) $(IFLAGS) -o $@
	@echo "$(GREEN). $(DEFAULT)\c"

$(LIBFT):
	@make -C $(LIBFTFOLDER) all

clean:
	@rm -rf $(OBJFOLDER)
	@make -C $(LIBFTFOLDER) fclean
	@echo "$(RED).o $(DEFAULT) are now deleted for $(NAME)."

fclean:
	@rm -rf $(OBJFOLDER)
	@make -C $(LIBFTFOLDER) fclean
	@rm -f $(NAME)
	@echo "$(RED)$(NAME)$(DEFAULT) is now deleted for $(NAME)."

re: fclean all
