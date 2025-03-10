/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicovic <imicovic@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 15:26:19 by imicovic          #+#    #+#             */
/*   Updated: 2025/02/25 15:50:39 by imicovic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

uint64_t	get_time(t_format time_format)
{
	struct timeval	current;

	gettimeofday(&current, NULL);
	if (time_format == MILISEC)
		return (current.tv_sec * 1e3 + current.tv_usec / 1e3);
	else if (time_format == MICROSEC)
		return (current.tv_sec * 1e6 + current.tv_usec);
	return (1337);
}

void	real_sleep(uint64_t usec)
{
	uint64_t	start;
	uint64_t	elapsed;
	uint64_t	rem;

	start = get_time(MICROSEC);
	while (get_time(MICROSEC) - start < usec)
	{
		elapsed = get_time(MICROSEC) - start;
		rem = usec - elapsed;
		if (rem > 1e3)
			usleep(rem / 2);
		else
		{
			while (get_time(MICROSEC) - start < usec)
				;
		}
	}
}

uint64_t	get_timestamp(t_data *data)
{
	uint64_t	current;

	current = get_time(MILISEC);
	return (current - data->start);
}

void	wait_all(t_data *data)
{
	while (!get_bool(&data->m_all, &data->all))
		;
}
