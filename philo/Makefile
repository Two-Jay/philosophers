# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jekim <arabi1549@naver.com>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/29 16:43:27 by jekim             #+#    #+#              #
#    Updated: 2021/07/30 19:51:24 by jekim            ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME		=	philo

CC			=	gcc
CCFLAG		=	-Wall -Wextra -Werror
SNTZ		=	-fsanitize=address -g
INCLUDE		=	-I. -I$(LIBFT_DIR)
LIB			=	-L$(LIBFT_DIR) -lft

LIBFT_DIR	=	../libft/
OBJ_DIR		=	./obj/
LIBFT		=	$(LIBFT_DIR)libft.a

P_FILE		=	philo.c validate.c

P_OBJ_FILE	=	$(P_FILE:.c=.o)
P_OBJ		=	$(addprefix $(OBJ_DIR), $(P_OBJ_FILE))

all			:	$(NAME)

$(OBJ_DIR)%.o : ./%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CCFLAG) $(INCLUDE) $< -c -o $@

$(NAME)		:	$(P_OBJ)
	@$(MAKE) -C $(LIBFT_DIR)
	@$(CC) $(CCFLAG) $(P_OBJ) $(LIB) $(INCLUDE) -o $@
	@echo "\033[0;92m* $(NAME) program file was created *\033[0m"

clean		:
	@make -C $(LIBFT_DIR) clean
	@rm -rf $(P_OBJ)
	@echo "\033[0;91m* $(NAME)'s object files were removed* \033[0m"


fclean		:	clean
	@make -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)
	@echo "\033[0;91m* $(NAME) were removed* \033[0m"


re			:	fclean all

.PHONY: all, clean, fclean, re