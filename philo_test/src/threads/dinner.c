/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicovic <imicovic@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:32:46 by imicovic          #+#    #+#             */
/*   Updated: 2025/02/25 16:31:03 by imicovic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static void	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->first);
	status_put(philo, FORK);
	pthread_mutex_lock(philo->second);
	status_put(philo, FORK);
	status_put(philo, EAT);
	inc_dec(&philo->m_meals, &philo->meals, INC);
	set_num(&philo->m_lmt, &philo->lmt, get_time(MILISEC));
	real_sleep(philo->data->tte * 1000);
	pthread_mutex_unlock(philo->first);
	pthread_mutex_unlock(philo->second);
}

void	dinner(t_philo * philo)
{
	while (!is_finished(philo->data))
	{
		eat(philo);
		status_put(philo, SLEEP);
		real_sleep(philo->data->tts * 1000);
		status_put(philo, THINK);
		real_sleep(100);
	}
}
