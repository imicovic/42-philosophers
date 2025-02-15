/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicovic <imicovic@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:52:07 by imicovic          #+#    #+#             */
/*   Updated: 2025/02/14 16:16:12 by imicovic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>

typedef struct s_philo
{
	pthread_t		threads;
	uint16_t		ttd; // time to die
	uint16_t		tc; //thread count
	uint16_t		index;
}	t_philo;

int		ft_atoi(const char *nptr);

short	input_check(char **argv, int argc);

t_philo	*philo_init(uint32_t count);
uint8_t	init(t_philo *philos, int32_t argc, char **argv);

#endif
