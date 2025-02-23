/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igormic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 18:43:36 by igormic           #+#    #+#             */
/*   Updated: 2025/02/23 19:45:34 by igormic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static int8_t	status_check(t_data *data)
{
	int64_t	i;

	i = -1;
	while (++i < data->tc)
	{
		if (get_time(MILISEC) - (data->philos + i)->lmt >= (uint64_t) data->ttd)
			return (1);
	}
	return (0);
}

void	*monitor(void *v_data)
{
	t_data	*data;

	data = (t_data *) v_data;
	while (!get_bool(data->m_run, &data->run))
		;
	while (1)
	{
		if (status_check(data))
			break ;
		real_sleep(5);
	}
	set_bool(data->m_finished, &data->finished, true);
	return (NULL);
}
