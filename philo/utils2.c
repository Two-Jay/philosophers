/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <arabi1549@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 23:07:15 by jekim             #+#    #+#             */
/*   Updated: 2021/09/18 23:52:00 by jekim            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isspace(char ch)
{
	return (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\v'
		|| ch == '\f' || ch == '\r');
}

/*
** if the str is able to convert nbr type (int, long, long long us int...)
** this function will returns 1, if not, 0.
*/
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

/*
** return int nbr when the value of nbr is between INTMAX and INTMIN
** if an overflow occur, returns 1 and adds a value on ovf_flag pointer
*/
int	ft_atoi_covf(const char *nptr, int *ovf_flag)
{
	long long	nbr;
	int			sign;
	int			ix;

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
		nbr = (nbr * 10) + (nptr[ix++] - '0');
	if (ft_isoverflow(nbr * sign) == 1 || ft_isoverflow(nbr * sign) == -1)
		return (++(*ovf_flag));
	else
		return ((int)(nbr * sign));
}

int	ft_isoverflow(long long nbr)
{
	long long	max;
	long long	min;

	max = 2147483647;
	min = -2147483648;
	if (nbr > max)
		return (1);
	if (nbr < min)
		return (-1);
	else
		return (0);
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