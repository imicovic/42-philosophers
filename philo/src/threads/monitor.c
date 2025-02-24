/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igormic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 18:43:36 by igormic           #+#    #+#             */
/*   Updated: 2025/02/24 15:05:25 by imicovic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static int8_t	status_check(t_data *data)
{
	int64_t	i;

	i = -1;
	pthread_mutex_lock(&data->m_all);
	while (++i < data->tc)
	{
		if (get_time(MILISEC) - (data->philos + i)->lmt >= (uint64_t) data->ttd)
			return (1);
	}
	pthread_mutex_unlock(&data->m_all);
	return (0);
}

void	*monitor(void *v_data)
{
	t_data	*data;

	data = (t_data *) v_data;
	while (get_num(data->m_run, &data->run) < data->tc)
		real_sleep(2);
	while (1)
	{
		if (status_check(data))
		{
			set_bool(data->m_finished, &data->finished, true);
			break ;
		}
		//real_sleep(10);
	}
	return (NULL);
}
