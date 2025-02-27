/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicovic <imicovic@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:37:32 by imicovic          #+#    #+#             */
/*   Updated: 2025/02/25 10:38:30 by imicovic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	print_data(t_data *data)
{
	printf("data->tc:\t\t%jd\n", data->tc);
	printf("data->tc:\t\t%jd\n", data->ttd);
	printf("data->tc:\t\t%jd\n", data->tte);
	printf("data->tc:\t\t%jd\n", data->tts);
	printf("data->tc:\t\t%jd\n", data->mnum);
}
