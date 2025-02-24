/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicovic <imicovic@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 14:17:22 by imicovic          #+#    #+#             */
/*   Updated: 2025/02/24 14:43:56 by imicovic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	*routine(void *v_philo)
{
	t_philo	*philo;

	philo = (t_philo *) v_philo;
	wait_all(philo->data);
	inc_dec(&philo->data->m_run, &philo->data->run, INC);
	while (!get_bool(philo->data->m_finished, &philo->data->finished))
	{
		// Check if philosopher is full
		dinner(philo);
		real_sleep(100);
	}
	return (NULL);
}

void	spawn(t_data *data)
{
	int64_t	i;

	i = -1;
	while (++i < data->tc)
		pthread_create(&(data->philos + i)->thread, NULL,
				routine, (void *)(data->philos + i));
}

void	join(t_data *data)
{
	int64_t	i;

	i = -1;
	while (++i < data->tc)
		pthread_join((data->philos + i)->thread, NULL);
}

void	simulation(t_data *data)
{
	if (data->tc == 1)
		return ;
	else if (data->mnum == 0)
		return ;
	pthread_create(&data->monitor, NULL, monitor, (void *) data);
	spawn(data);
	set_bool(data->m_all, &data->all, true);
	join(data);
	pthread_join(data->monitor, NULL);
}
