/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 02:19:07 by jekim             #+#    #+#             */
/*   Updated: 2021/09/25 16:42:10 by jekim            ###   ########.fr       */
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
	DFORK,
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
	struct timeval	time_checker_tv;
	unsigned long	time_to_die;
	unsigned long	time_to_eat;
	unsigned long	time_to_sleep;
	int				isAnyoneDead;
	pthread_mutex_t	isAnyoneDead_mtx;
	int				number_of_time_must_eat;
	int				number_of_done_to_eat;
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

void			*routine(void *phl);
int				do_sleep_think(t_philo *philo, t_data *data);
int				do_eat(t_philo *philo, t_data *data);
int				do_think(t_philo *philo);
int				take_forks(t_philo *philo);
int				leave_forks(t_philo *philo);

int				validate_argv(int argc, char **argv);
int				assign_data(t_setting *set, int argc, char **argv);
int				assign_philo(t_setting *set);
int				assign_fork(t_setting *set);
int				validate_assigned_data(t_setting *set);
int				free_data(t_setting *set);

int				print_messsage_stdout(t_philo *philo);
unsigned long	time_from_start(t_data *data);
int				check_philo_health(t_philo *philo, int eat_flag);
int				get_sleep(unsigned long target_time, t_data *data,
					t_philo *philo);

int				ft_strlen(char *s);
int				ft_strerr(char *err);
int				ft_isspace(char ch);
int				ft_isable_strtonbr(char *nbr);
int				ft_atoi(const char *nptr);

#endif
