# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jekim <arabi1549@naver.com>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/29 16:43:27 by jekim             #+#    #+#              #
#    Updated: 2021/09/18 00:18:16 by jekim            ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME		=	philo_bonus

CC			=	gcc
CCFLAG		=	-Wall -Wextra -Werror
PTHRDFLAG	=	-lpthread
SNTZ		=	-fsanitize=address -g3
INCLUDE		=	-I.

OBJ_DIR		=	./obj/

P_FILE		=	philo.c \
				utils.c

P_OBJ_FILE	=	$(P_FILE:.c=.o)
P_OBJ		=	$(addprefix $(OBJ_DIR), $(P_OBJ_FILE))

all			:	$(NAME)

$(OBJ_DIR)%.o : ./%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CCFLAG) $(INCLUDE) $< -c -o $@

$(NAME)		:	$(P_OBJ)
	@$(CC) $(CCFLAG) $(P_OBJ) $(PTHRDFLAG) $(SNTZ) $(INCLUDE) -o $@
	@echo "\033[0;92m* $(NAME) program file was created *\033[0m"

clean		:
	@rm -rf $(OBJ_DIR)
	@echo "\033[0;91m* $(NAME)'s object files were removed* \033[0m"


fclean		:	clean
	@rm -f $(NAME)
	@echo "\033[0;91m* $(NAME) were removed* \033[0m"


re			:	fclean all

.PHONY: all, clean, fclean, re