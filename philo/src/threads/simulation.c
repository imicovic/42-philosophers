/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicovic <imicovic@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 14:17:22 by imicovic          #+#    #+#             */
/*   Updated: 2025/02/24 21:10:22 by igormic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	*routine(void *v_philo)
{
	t_philo	*philo;

	philo = (t_philo *) v_philo;
	wait_all(philo->data);
	set_num(philo->m_lmt, &philo->lmt, get_time(MILISEC));
	inc_dec(&philo->data->m_run, &philo->data->run, INC);
	while (!get_bool(philo->data->m_finished, &philo->data->finished))
	{
		if (is_full(philo))
			break ;
		dinner(philo);
		usleep(100);
		//real_sleep(10);
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
	spawn(data);
	pthread_create(&data->monitor, NULL, monitor, (void *) data);
	set_bool(data->m_all, &data->all, true);
	pthread_join(data->monitor, NULL);
	join(data);
}
