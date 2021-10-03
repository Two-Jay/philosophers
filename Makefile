# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jekim <arabi1549@naver.com>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/29 16:43:27 by jekim             #+#    #+#              #
#    Updated: 2021/10/03 07:06:48 by jekim            ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

PHILO_DIR		= ./philo/
PHILO_BONUS_DIR = ./philo/philo_bonus

all			:
		@$(MAKE) -C $(PHILO_DIR)

bonus		:
		@$(MAKE) -C $(PHILO_BONUS_DIR)

clean		:
		@$(MAKE) -C $(PHILO_DIR) clean
		@$(MAKE) -C $(PHILO_BONUS_DIR) clean

fclean		:
		@$(MAKE) -C $(PHILO_DIR) fclean
		@$(MAKE) -C $(PHILO_BONUS_DIR) fclean

re			:	fclean all

rebonus		:	fclean bonus

.PHONY: all, clean, fclean, re