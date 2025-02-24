/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicovic <imicovic@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 14:02:00 by imicovic          #+#    #+#             */
/*   Updated: 2025/02/24 18:04:26 by igormic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

bool	get_bool(t_mtx mutex, bool *addr)
{
	bool	ret;

	pthread_mutex_lock(&mutex);
	ret = *addr;
	pthread_mutex_unlock(&mutex);
	return (ret);
}

void	set_bool(t_mtx mutex, bool *addr, bool val)
{
	pthread_mutex_lock(&mutex);
	*addr = val;
	pthread_mutex_unlock(&mutex);
}

int64_t	get_num(t_mtx mutex, uint64_t *addr)
{
	int64_t	ret;

	pthread_mutex_lock(&mutex);
	ret = *addr;
	pthread_mutex_unlock(&mutex);
	return (ret);
}

void	set_num(t_mtx mutex, uint64_t *addr, uint64_t val)
{
	pthread_mutex_lock(&mutex);
	*addr = val;
	pthread_mutex_unlock(&mutex);
}
