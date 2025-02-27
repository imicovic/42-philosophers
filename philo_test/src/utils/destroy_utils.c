/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicovic <imicovic@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 12:47:04 by imicovic          #+#    #+#             */
/*   Updated: 2025/02/25 15:31:35 by imicovic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	fork_destroy(t_data *data)
{
	t_mtx	*locks;
	int64_t	i;

	locks = data->forks;
	i = -1;
	while (++i < data->tc)
		pthread_mutex_destroy(locks + i);
	free(locks);
}

void	cleanup(t_data *data)
{
	int64_t	i;

	fork_destroy(data);
	pthread_mutex_destroy(&data->m_all);
	pthread_mutex_destroy(&data->m_finished);
	pthread_mutex_destroy(&data->m_run);
	pthread_mutex_destroy(&data->m_write);
	i = 0;
	while (i < data->tc)
	{
		pthread_mutex_destroy(&(data->philos + i)->m_lmt);
		pthread_mutex_destroy(&(data->philos + i)->m_meals);
		i++;
	}
	free(data->philos);
	free(data);
}
