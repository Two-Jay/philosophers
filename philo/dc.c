/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dc.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 12:13:44 by jekim             #+#    #+#             */
/*   Updated: 2021/09/24 21:45:53 by jekim            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int free_data(t_setting *set)
{
	int ix;
	int limit;

	ix = 0;
	limit = set->data->number_of_philo;
	while (ix < limit)
		pthread_mutex_destroy(&set->fork[ix++].fork_m);
	free(set->fork);
	ix = 0;
	while (ix < limit)
	{
		pthread_join(*set->philo[ix].tid, NULL);
		free(set->philo[ix].tid);
		ix++;
	}
	free(set->philo);
	pthread_mutex_destroy(&set->data->isAnyoneDead_mtx);
	free(set->data);
	return (0);
}