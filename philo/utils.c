/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 02:20:43 by jekim             #+#    #+#             */
/*   Updated: 2021/09/18 23:10:19 by jekim            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

int ft_strlen(char *s)
{
	int i;

	i = 0;
	while (*(s + i++))
		;
	return (i);
}

int ft_strerr(char *err)
{
	int errlen;
	
	errlen = ft_strlen(err);
	write(2, err, errlen);
	exit(EXIT_FAILURE);
}


