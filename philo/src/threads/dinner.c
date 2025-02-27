/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicovic <imicovic@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:32:46 by imicovic          #+#    #+#             */
/*   Updated: 2025/02/27 13:47:14 by imicovic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static void	unlock(t_mtx *m1, t_mtx *m2)
{
	if (m1)
		pthread_mutex_unlock(m1);
	if (m2)
		pthread_mutex_unlock(m2);
}

static void	eat(t_philo *philo)
{
	if (is_finished(philo->data))
		return ;
	pthread_mutex_lock(philo->first);
	if (is_finished(philo->data))
		return (unlock(philo->first, NULL));
	status_put(philo, FORK);
	pthread_mutex_lock(philo->second);
	if (is_finished(philo->data))
		return (unlock(philo->first, philo->second));
	status_put(philo, FORK);
	if (is_finished(philo->data))
		return (unlock(philo->first, philo->second));
	status_put(philo, EAT);
	inc_dec(&philo->m_meals, &philo->meals, INC);
	set_num(&philo->m_lmt, &philo->lmt, get_time(MILISEC));
	real_sleep(philo->data->tte * 1000);
	pthread_mutex_unlock(philo->first);
	pthread_mutex_unlock(philo->second);
}

static void	think(t_philo *philo)
{
	status_put(philo, THINK);
	if (!philo->data->ttt)
		return ;
	real_sleep(philo->data->ttt);
}

void	dinner(t_philo *philo)
{
	if (is_finished(philo->data))
		return ;
	eat(philo);
	if (is_finished(philo->data))
		return ;
	status_put(philo, SLEEP);
	if (is_finished(philo->data))
		return ;
	real_sleep(philo->data->tts * 1000);
	if (is_finished(philo->data))
		return ;
	think(philo);
}
