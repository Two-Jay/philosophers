/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 02:19:07 by jekim             #+#    #+#             */
/*   Updated: 2021/09/19 01:58:17 by jekim            ###   ########seoul.kr  */
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

typedef struct s_philo
{
	pthread_t		*tid;
	int				id;
	int				l_fork;
	int				r_fork;
	unsigned long 	last_eat_time;
	int				state;
}	t_philo;

typedef struct s_data
{
	t_philo			*philo;
	int				number_of_philo;
	unsigned long	time_to_die;
	unsigned long	time_to_eat;
	unsigned long	time_to_sleep;
	int				isAnyoneDead;
	int				number_of_time_must_eat;
}	t_data;

//dc.c
int				free_data(t_data *data);

// validator.c
int				init_data(t_data *data);
int				check_argc(int argc);
int				validate_arg(int argc, char **argv);
int				assign_data(t_data *data, int argc, char **argv);
int				assign_philo(t_data *data);

//utils.c
int				ft_strlen(char *s);
int				ft_strerr(char *err);
int				ft_isspace(char ch);
int				ft_isable_strtonbr(char *nbr);
int				ft_atoi(const char *nptr);
int				ft_isoverflow(long long nbr);
unsigned long	fn_gettimenow(void);

#endif