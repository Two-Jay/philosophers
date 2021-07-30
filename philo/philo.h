/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 05:04:37 by jekim             #+#    #+#             */
/*   Updated: 2021/07/31 08:58:49 by jekim            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <time.h>
# include "../libft/libft.h"

typedef struct s_philo
{
	int	id;
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
	int				*params_arr;
	int				number_philo;
	int				number_must_eat;
	int				T_eat;
	int				T_sleep;
	int				T_die;
}				t_data;

// validate.c
t_data	*fn_datanew(int argc);
int		fn_set_params(int argc, char **argv, t_data *data);

// utils.c
int		fn_print_err(char *err, t_data *data);
int		fn_clear_data(t_data *data, int ret);
long	fn_gettime_milisec(void);

#endif
