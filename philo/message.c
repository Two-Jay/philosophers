/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 14:35:41 by jekim             #+#    #+#             */
/*   Updated: 2021/09/25 17:12:12 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_messsage_stdout(t_philo *philo)
{
	char *msg;

	if (philo->state == FORK)
		msg = "has taken a fork.\n";
	if (philo->state == DFORK)
		msg = "has dropped a fork.\n";
	if (philo->state == EAT)
		msg = "is eating.\n";
	if (philo->state == SLEEP)
		msg = "is sleeping.\n";
	if (philo->state == THINK)
		msg = "is thinking.\n";
	if (philo->state == END)
		msg = "was eaten as the philo must eat.\n";
	if (philo->state == DIE)
		msg = "died.\n";
	pthread_mutex_lock(&(philo->data->isAnyoneDead_mtx));
	printf("%lu ms %dth philo %s",
		time_from_start(philo->data),
		philo->id,
		msg);
	if (philo->data->isAnyoneDead == 0)
		pthread_mutex_unlock(&(philo->data->isAnyoneDead_mtx));
	return (0);
}
