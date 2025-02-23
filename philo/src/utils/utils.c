/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igormic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 19:48:50 by igormic           #+#    #+#             */
/*   Updated: 2025/02/23 19:56:14 by igormic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	inc_dec(t_mtx *mutex, int64_t *addr, t_op op)
{
	pthread_mutex_lock(mutex);
	if (op == INC)
		(*addr) += 1;
	else if (op == DEC)
		(*addr) -= 1;
	pthread_mutex_unlock(mutex);
}

void	status_put(t_philo *philo, t_status status)
{
	pthread_mutex_lock(&philo->data->m_write);
	if (status == FORK)
		printf("%lld %lld has taken a fork\n", get_timestamp(philo->data), philo->id);
	else if (status == EAT)
		printf("%lld %lld is eating\n", get_timestamp(philo->data), philo->id);
	else if (status == SLEEP)
		printf("%lld %lld is sleeping\n", get_timestamp(philo->data), philo->id);
	else if (status == THINK)
		printf("%lld %lld is thinking\n", get_timestamp(philo->data), philo->id);
	else if (status == FULL)
		printf("%lld philos are full\n", get_timestamp(philo->data));
	else
		printf("%lld %lld philo died\n", get_timestamp(philo->data), philo->id);
	pthread_mutex_unlock(&philo->data->m_write);
}
