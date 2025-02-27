/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicovic <imicovic@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 15:12:43 by imicovic          #+#    #+#             */
/*   Updated: 2025/02/25 15:31:20 by imicovic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	init_vars(t_data *data)
{
	data->run = 0;
	data->start = get_time(MILISEC);
	data->all = false;
	data->finished = false;
	pthread_mutex_init(&data->m_all, NULL);
	pthread_mutex_init(&data->m_finished, NULL);
	pthread_mutex_init(&data->m_run, NULL);
	pthread_mutex_init(&data->m_write, NULL);
}
