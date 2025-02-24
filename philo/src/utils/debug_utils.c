/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicovic <imicovic@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 11:24:43 by imicovic          #+#    #+#             */
/*   Updated: 2025/02/24 11:05:03 by imicovic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	print_data(t_data *data)
{
	printf("Philo count:\t%ld\n", data->tc);
	printf("Data all val:\t%d\n", data->all);
	printf("Time to die:\t%ld\n", data->ttd);
	printf("Time to sleep:\t%ld\n", data->tts);
	printf("Time to eat:\t%ld\n", data->tte);
	printf("Meals to eat:\t%ld\n", data->mnum);
}

void	print_philo(t_philo *philo)
{
	printf("Philo id:\t\t\t%ld\n", philo->id);
	printf("Has first fork:\t\t%p\n", philo->first);
	printf("Has second fork:\t%p\n", philo->second);
}
