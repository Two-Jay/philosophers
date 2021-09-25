/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 23:07:15 by jekim             #+#    #+#             */
/*   Updated: 2021/09/19 02:30:38 by jekim            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isspace(char ch)
{
	return (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\v'
		|| ch == '\f' || ch == '\r');
}

int	ft_isable_strtonbr(char *nbr)
{
	int	ret;

	ret = 1;
	while (*nbr && ft_isspace(*nbr))
		nbr++;
	if (*nbr == '-' || *nbr == '+')
		nbr++;
	while (*nbr)
	{
		if (!(*nbr >= '0' && *nbr <= '9') && !ft_isspace(*nbr))
			return (--ret);
		nbr++;
	}
	return (ret);
}

int	ft_atoi(const char *nptr)
{
	int	nbr;
	int	sign;
	int	ix;

	nbr = 0;
	ix = 0;
	sign = 1;
	while (nptr[ix] && ft_isspace(nptr[ix]))
		ix++;
	if (nptr[ix] == '-')
		sign = -1;
	if (nptr[ix] == '-' || nptr[ix] == '+')
		ix++;
	while (nptr[ix] && ('0' <= nptr[ix] && nptr[ix] <= '9'))
	{
		nbr = (nbr * 10) + (nptr[ix] - '0');
		ix++;
	}
	return (sign * nbr);
}