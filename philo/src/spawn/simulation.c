/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicovic <imicovic@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 14:17:22 by imicovic          #+#    #+#             */
/*   Updated: 2025/02/23 16:10:07 by imicovic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	*routine(void *v_philo)
{
	t_philo	*philo;

	philo = (t_philo *) v_philo;
	inc_dec(&philo->data->m_all, &philo->data->all, DEC);
	while (get_num(philo->data->m_all, &philo->data->all))
		real_sleep(100);
	printf("Hello, World %ld\n", philo->id);
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
		return ; // TO DO
	else if (data->mnum == 0)
		return ; // TO DO
	spawn(data);
	join(data);
}
