/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicovic <imicovic@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 03:01:42 by imicovic          #+#    #+#             */
/*   Updated: 2025/02/14 16:26:08 by imicovic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

static short	ft_isdigit(const char c)
{
	return (c >= '0' && c <= '9');
}

static short	is_valid(const char *s)
{
	short	i;

	i = 0;
	if (s[i] == '-' || !s[i])
		return (1);
	else if (s[i] == '+')
		i++;
	while (ft_isdigit(s[i]))
		i++;
	return (s[i]);
}

short	input_check(char **argv, int argc)
{
	short	i;

	i = 1;
	while (i < argc)
	{
		if (is_valid(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	num;
	int	flag;

	num = 0;
	i = 0;
	flag = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			flag = -1;
		i++;
	}
	if (!ft_isdigit(nptr[i]))
		return (0);
	while (ft_isdigit(nptr[i]))
	{
		num *= 10;
		num += (nptr[i] - '0');
		i++;
	}
	return (flag * num);
}
