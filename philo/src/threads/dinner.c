/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igormic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 19:46:56 by igormic           #+#    #+#             */
/*   Updated: 2025/02/25 10:14:03 by imicovic         ###   ########.fr       */
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
	set_num(philo->m_lmt, &philo->lmt, get_time(MILISEC));
	real_sleep(philo->data->tte * 1000);
	pthread_mutex_unlock(philo->first);
	pthread_mutex_unlock(philo->second);
}

void	dinner(t_philo * philo)
{
	eat(philo);
	status_put(philo, SLEEP);
	real_sleep(philo->data->tts * 1000);
	status_put(philo, THINK);
}
