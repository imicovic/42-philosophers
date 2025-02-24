/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igormic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 19:48:50 by igormic           #+#    #+#             */
/*   Updated: 2025/02/24 21:03:23 by igormic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	inc_dec(t_mtx *mutex, uint64_t *addr, t_op op)
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
		printf("%llu %llu has taken a fork\n", get_timestamp(philo->data), philo->id);
	else if (status == EAT)
		printf("%llu %llu is eating\n", get_timestamp(philo->data), philo->id);
	else if (status == SLEEP)
		printf("%llu %llu is sleeping\n", get_timestamp(philo->data), philo->id);
	else if (status == THINK)
		printf("%llu %llu is thinking\n", get_timestamp(philo->data), philo->id);
	else if (status == FULL)
		printf("%llu philos are full\n", get_timestamp(philo->data));
	else
		printf("\t%llu %llu philo died\n", get_timestamp(philo->data), philo->id);
	pthread_mutex_unlock(&philo->data->m_write);
}

bool	is_full(t_philo *philo)
{
	uint64_t	count;
	uint64_t	max;

	count = get_num(philo->m_meals, &philo->meals);
	max = philo->data->mnum;
	return (count == max);
}
