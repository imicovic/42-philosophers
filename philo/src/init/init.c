/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicovic <imicovic@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 11:56:02 by imicovic          #+#    #+#             */
/*   Updated: 2025/02/23 19:43:05 by igormic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static t_data	*data_init(int32_t argc, char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->tc = ft_atoi(argv[1]);
	data->ttd = ft_atoi(argv[2]);
	data->tts = ft_atoi(argv[3]);
	data->tte = ft_atoi(argv[4]);
	if (argc == 6)
		data->mnum = ft_atoi(argv[5]);
	else
		data->mnum = -1;
	return (data);
}

static void	ass_forks(t_philo *philo, t_mtx *locks)
{
	int64_t	count;

	count = philo->data->tc;
	if ((philo->id - 1) % 2)
	{
		philo->first = locks + (philo->id - 1);
		philo->second = locks + (philo->id % count);
	}
	else
	{
		philo->first = locks + (philo->id % count);
		philo->second = locks + philo->id - 1;
	}
}

static t_philo	*philo_init(t_data *data)
{
	t_philo	*philos;
	int64_t	count;
	int64_t	i;

	count = data->tc;
	philos = malloc(count * sizeof(t_philo));
	if (!philos)
		return (NULL);
	i = -1;
	while (++i < count)
	{
		philos[i].lmt = 0;
		philos[i].data = data;
		philos[i].id = i + 1;
		ass_forks(philos + i, data->forks);
	}
	return (philos);
}

static t_mtx	*fork_init(t_data *data)
{
	t_mtx	*forks;
	int64_t	i;

	forks = malloc(data->tc * sizeof(t_mtx));
	if (!forks)
		return (NULL);
	i = -1;
	while (++i < data->tc)
		pthread_mutex_init(&forks[i], NULL);
	return (forks);
}

t_data	*init(int32_t argc, char **argv)
{
	t_data	*data;

	data = data_init(argc, argv);
	if (!data)
		return (NULL);
	data->forks = fork_init(data);
	if (!data->forks)
	{
		free(data);
		return (NULL);
	}
	data->philos = philo_init(data);
	if (!data->philos)
	{
		fork_destroy(data);
		free(data);
		return (NULL);
	}
	init_vars(data);
	return (data);
}
