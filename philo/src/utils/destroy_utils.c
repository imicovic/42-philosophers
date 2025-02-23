/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicovic <imicovic@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 12:47:04 by imicovic          #+#    #+#             */
/*   Updated: 2025/02/23 16:03:37 by imicovic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	fork_destroy(t_data *data)
{
	t_mtx	*locks;
	int64_t	i;

	locks = data->forks;
	i = -1;
	while (++i < data->tc)
		pthread_mutex_destroy(locks + i);
	free(locks);
}

void	inc_dec(t_mtx *mutex, int64_t *addr, t_op op)
{
	pthread_mutex_lock(mutex);
	if (op == INC)
		(*addr) += 1;
	else if (op == DEC)
		(*addr) -= 1;
	pthread_mutex_unlock(mutex);
}
