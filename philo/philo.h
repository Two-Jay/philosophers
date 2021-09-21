/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 02:19:07 by jekim             #+#    #+#             */
/*   Updated: 2021/09/21 04:50:47 by jekim            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <sys/time.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>

# define TRUE 1
# define ERROR_OCCURED 1
# define FALSE 0

typedef enum s_state
{
	EAT = 0,
	SLEEP,
	FORK,
	THINK,
	DIE,
	END,
}	t_state;

typedef struct s_fork
{
	int				id;
	int				grabbedby;
	pthread_mutex_t	fork_m;
}	t_fork;

typedef struct s_data
{
	int				number_of_philo;
	struct timeval	time_to_start_tv;
	unsigned long	time_to_die;
	unsigned long	time_to_eat;
	unsigned long	time_to_sleep;
	int				isAnyoneDead;
	pthread_mutex_t	isAnyoneDead_mtx;
	int				number_of_time_must_eat;
}	t_data;

typedef struct s_philo
{
	t_data			*data;
	t_fork			*fork;
	pthread_t		*tid;
	int				id;
	int				l_fork;
	int				r_fork;
	unsigned long	last_eat_time;
	int				state;
}	t_philo;

typedef struct s_setting
{
	t_data	*data;
	t_philo	*philo;
	t_fork	*fork;
}	t_setting;

// dc.c
int				free_data(t_setting *set);

// routine.c
void			*routine(void *data);

// validator.c
int				init_data(t_setting *setting);
int				check_argc(int argc);
int				validate_argv(int argc, char **argv);

// assignment.c
int				assign_data(t_setting *set, int argc, char **argv);
int				assign_philo(t_setting *set);
int				assign_fork(t_setting *set);
int				validate_assigned_data(t_setting *set);

// message.c
int				print_messsage_stdout(t_philo *philo);

// utils.c
int				ft_strlen(char *s);
int				ft_strerr(char *err);
int				ft_isspace(char ch);
int				ft_isable_strtonbr(char *nbr);
int				ft_atoi(const char *nptr);
unsigned long	fn_gettimenow(t_data *data);

#endif