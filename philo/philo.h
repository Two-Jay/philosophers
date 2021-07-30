/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 05:04:37 by jekim             #+#    #+#             */
/*   Updated: 2021/07/30 19:58:45 by jekim            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include "../libft/libft.h"

typedef struct s_philo
{
	int	state;
	int	L_fork;
	int	R_fork;
}				t_philo;

typedef struct s_fork
{
	int	Ownedby;
}				t_fork;

typedef struct s_data
{
	struct s_philo	*philo_arr;
	struct s_fork	*fork_arr;
	int				number_philo;
	int				number_must_eat;
	int				T_eat;
	int				T_sleep;
	int				T_die;
}				t_data;

t_data	*fn_datanew(void);

#endif
