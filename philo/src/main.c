/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicovic <imicovic@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 03:26:32 by imicovic          #+#    #+#             */
/*   Updated: 2025/02/14 16:25:59 by imicovic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	main(int argc, char **argv)
{
	t_philo	*philos;

	if (argc < 5 || argc > 6 || !input_check(argv, argc))
	{
		write(2, "Wrong usage or input values.\n", 29);
		return (-1);
	}
	philos = philo_init(ft_atoi(argv[1]));
	init(philos, argc, argv);
	return (0);
}
