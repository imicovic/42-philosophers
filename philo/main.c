/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicovic <imicovic@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 11:17:33 by imicovic          #+#    #+#             */
/*   Updated: 2025/02/23 16:08:21 by imicovic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

int	main(int32_t argc, char **argv)
{
	t_data	*data;

	if (argc < 5 || argc > 6 || check_input(argc, argv))
	{
		printf("Wrong usage.\n");
		return (-1);
	}
	data = init(argc, argv);
	if (!data)
		return (-2);
	simulation(data);
}
