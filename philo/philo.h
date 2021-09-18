/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 02:19:07 by jekim             #+#    #+#             */
/*   Updated: 2021/09/18 23:52:24 by jekim            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>

typedef struct s_philo
{
	pthread_t	*thread;
	int			id;
	int			l_fork;
	int			r_fork;
	int			state;
	int			isDead;
}	t_philo;

typedef struct s_data
{
	t_philo	*philo;
	int		number_of_philo;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		number_of_time_must_eat;
}	t_data;

//dc.c
int	free_data(t_data *data);

// validator.c
int	set_data(t_data *data, int argc, char **argv);

//utils.c
int	ft_strlen(char *s);
int	ft_strerr(char *err);
int	ft_isspace(char ch);
int	ft_isable_strtonbr(char *nbr);
int	ft_atoi(const char *nptr);
int	ft_isoverflow(long long nbr);

#endif