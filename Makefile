# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jekim <arabi1549@naver.com>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/29 16:43:27 by jekim             #+#    #+#              #
#    Updated: 2021/07/29 05:18:42 by jekim            ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

PHILO_DIR	= ./philo/

all			:
		@$(MAKE) -C $(PHILO_DIR)

clean		:
		@$(MAKE) -C $(PHILO_DIR) clean

fclean		:
		@$(MAKE) -C $(PHILO_DIR) fclean

re			:	fclean all

.PHONY: all, clean, fclean, re