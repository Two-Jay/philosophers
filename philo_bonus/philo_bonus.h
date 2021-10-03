/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 07:07:11 by jekim             #+#    #+#             */
/*   Updated: 2021/10/04 05:11:10 by jekim            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <sys/time.h>
# include <sys/types.h>
# include <stdlib.h>
# include <unistd.h>

# define ERROR_OCCURED 1

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
	int		id;
	int		grabbedby;
}	t_fork;

typedef struct s_data
{
	int				number_of_philo;
	unsigned long	time_to_die;
	unsigned long	time_to_eat;
	unsigned long	time_to_sleep;
	unsigned long	start_time;
	int				number_of_time_must_eat;
}	t_data;

typedef struct s_philo
{
	t_data			*data;
	t_fork			*fork;
	pid_t			pid;
	int				id;
	int				l_fork;
	int				r_fork;
	unsigned long	last_eat_time;
	int				is_over;
	int				state;
}	t_philo;

typedef struct s_monitor
{
	pid_t		pid;
	t_philo		*target_philo;
	int			id;
}	t_monitor;

typedef struct s_setting
{
	t_data		*data;
	t_philo		*philo;
	t_fork		*fork;
	t_monitor	*monitor;
}	t_setting;

int	assign_data(t_setting *set, int argc, char **argv);
int	assign_philo(t_setting *set);
int	validate_argv(int argc, char **argv);
int	validate_assigned_data(t_setting *set);

int	ft_strlen(char *s);
int	ft_strerr(char *err);
int	ft_isspace(char ch);
int	ft_isable_strtonbr(char *nbr);
int	ft_atoi(const char *nptr);

#endif