/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igormic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 18:43:36 by igormic           #+#    #+#             */
/*   Updated: 2025/02/25 11:15:40 by imicovic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static bool	is_dead(t_philo *philo)
{
	uint64_t	elapsed;

	if (get_num(philo->m_meals, &philo->meals) == philo->data->mnum)
		return (false);
	elapsed = get_time(MILISEC) - get_num(philo->m_lmt, &philo->lmt);
	return (elapsed > (uint64_t) philo->data->ttd);
}

bool	is_finished(t_data *data)
{
	return (get_bool(data->m_finished, &data->finished));
}

void	*monitor(void *v_data)
{
	t_data	*data;
	int64_t	i;

	data = (t_data *) v_data;
	while (get_num(data->m_run, &data->run) != data->tc)
		real_sleep(1);
	while (!is_finished(data))
	{
		i = -1;
		while (++i < data->tc && !is_finished(data))
		{
			if (is_dead(data->philos + i))
			{
				set_bool(data->m_finished, &data->finished, true);
				status_put(data->philos + i, DEAD);
				return (NULL);
			}
		}
	}
	return (NULL);
}
