/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicovic <imicovic@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 12:47:04 by imicovic          #+#    #+#             */
/*   Updated: 2025/02/23 19:48:45 by igormic          ###   ########.fr       */
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
