/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicovic <imicovic@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 11:24:43 by imicovic          #+#    #+#             */
/*   Updated: 2025/02/23 18:15:20 by igormic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	print_data(t_data *data)
{
	printf("Philo count:\t%lld\n", data->tc);
	printf("Data all val:\t%b\n", data->all);
	printf("Time to die:\t%lld\n", data->ttd);
	printf("Time to sleep:\t%lld\n", data->tts);
	printf("Time to eat:\t%lld\n", data->tte);
	printf("Meals to eat:\t%lld\n", data->mnum);
}

void	print_philo(t_philo *philo)
{
	printf("Philo id:\t\t\t%lld\n", philo->id);
	printf("Has first fork:\t\t%p\n", philo->first);
	printf("Has second fork:\t%p\n", philo->second);
}
