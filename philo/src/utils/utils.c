/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igormic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 19:48:50 by igormic           #+#    #+#             */
/*   Updated: 2025/02/25 10:27:25 by imicovic         ###   ########.fr       */
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
		printf("%ju %ju has taken a fork\n", get_timestamp(philo->data), philo->id);
	else if (status == EAT)
		printf("%ju %ju is eating\n", get_timestamp(philo->data), philo->id);
	else if (status == SLEEP)
		printf("%ju %ju is sleeping\n", get_timestamp(philo->data), philo->id);
	else if (status == THINK)
		printf("%ju %ju is thinking\n", get_timestamp(philo->data), philo->id);
	else if (status == FULL)
		printf("%ju philos are full\n", get_timestamp(philo->data));
	else
		printf("\t%ju %ju philo died\n", get_timestamp(philo->data), philo->id);
	pthread_mutex_unlock(&philo->data->m_write);
}

bool	is_full(t_philo *philo)
{
	uint64_t	count;

	count = get_num(philo->m_meals, &philo->meals);
	return ((int64_t) count == philo->data->mnum);
}
