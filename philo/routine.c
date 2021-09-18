/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 02:57:30 by jekim             #+#    #+#             */
/*   Updated: 2021/09/19 02:58:44 by jekim            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *ix)
{
	int	i;

	i = *((int *)ix);
	printf("%dth thread was created\n", i);
	printf("%dth thread runs at %lu\n", i, fn_gettimenow());
	return (NULL);
}
