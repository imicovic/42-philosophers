/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicovic <imicovic@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 14:17:22 by imicovic          #+#    #+#             */
/*   Updated: 2025/02/27 13:46:23 by imicovic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static void	*routine(void *v_philo)
{
	t_philo	*philo;

	philo = (t_philo *) v_philo;
	wait_all(philo->data);
	inc_dec(&philo->data->m_run, &philo->data->run, INC);
	set_num(&philo->m_lmt, &philo->lmt, get_time(MILISEC));
	while (!is_finished(philo->data))
	{
		if (is_full(philo))
			break ;
		dinner(philo);
	}
	return (NULL);
}

static void	spawn(t_data *data)
{
	int64_t	i;

	i = -1;
	while (++i < data->tc)
		pthread_create(&(data->philos + i)->thread, NULL,
			routine, (void *)(data->philos + i));
}

static void	join(t_data *data)
{
	int64_t	i;

	i = -1;
	while (++i < data->tc)
		pthread_join((data->philos + i)->thread, NULL);
}

void	simulation(t_data *data)
{
	if (data->tc == 1)
	{
		single(data);
		return ;
	}
	else if (data->mnum == 0)
		return ;
	set_num(&data->m_write, &data->start, get_time(MILISEC));
	spawn(data);
	set_bool(&data->m_all, &data->all, true);
	pthread_create(&data->monitor, NULL, monitor, (void *) data);
	join(data);
	if (data->mnum != -1 && !get_bool(&data->m_finished, &data->finished))
	{
		status_put(data->philos, FULL);
		set_bool(&data->m_finished, &data->finished, true);
	}
	pthread_join(data->monitor, NULL);
}
