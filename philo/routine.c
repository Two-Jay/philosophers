/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 02:57:30 by jekim             #+#    #+#             */
/*   Updated: 2021/09/19 03:52:26 by jekim            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *phl)
{
	t_philo *philo;

	philo = (t_philo *)phl;
	philo->last_eat_time = fn_gettimenow();
	printf("%dth thread was created\n", philo->id);
	printf("%dth thread runs on %lu\n", philo->id, philo->last_eat_time);
	return (NULL);
}
