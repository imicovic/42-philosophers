/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicovic <imicovic@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:58:17 by imicovic          #+#    #+#             */
/*   Updated: 2025/02/14 16:22:04 by imicovic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

t_philo	*philo_init(uint32_t count)
{
	t_philo		*philos;

	philos = malloc(sizeof(t_philo) * count);
	return (philos);
}

uint8_t	init(t_philo *philos, int32_t argc, char **argv)
{
	uint32_t	i;
	uint32_t	count;

	if (argc > 100)
		return (1);
	if (!philos)
		return (1);
	count = ft_atoi(argv[1]);
	i = 0;
	while (i < count)
	{
		philos[i].tc = count;
		philos[i].ttd = ft_atoi(argv[2]);
		philos[i].index = i + 1;
		i++;
	}
	return (0);
}
