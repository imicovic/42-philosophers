/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicovic <imicovic@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 11:32:24 by imicovic          #+#    #+#             */
/*   Updated: 2025/02/23 11:53:19 by imicovic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static int8_t	is_numeric(const char *s)
{
	int16_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int8_t	check_input(int32_t argc, char **argv)
{
	int32_t	i;

	i = 1;
	while (i < argc)
	{
		if (is_numeric(argv[i]))
			return (1);
		i++;
	}
	return (0);
}

int64_t	ft_atoi(const char *s)
{
	int16_t	i;
	int64_t	n;

	i = -1;
	n = 0;
	while (s[++i])
	{
		n *= 10;
		if (n + (s[i] - '0') >= INT_MAX)
			return (INT_MAX);
		n += (s[i] - '0');
	}
	return (n);
}
