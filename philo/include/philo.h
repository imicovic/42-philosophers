/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicovic <imicovic@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 11:18:12 by imicovic          #+#    #+#             */
/*   Updated: 2025/02/24 14:41:17 by imicovic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
# include <stddef.h>
# include <limits.h>
# include <unistd.h>
# include <pthread.h>
# include <stdbool.h>
# include <sys/time.h>

typedef enum e_op
{
	INC = 1,
	DEC
}	t_op;

typedef enum e_format
{
	MILISEC = 1,
	MICROSEC
}	t_format;

typedef enum e_status
{
	FORK = 1,
	EAT,
	SLEEP,
	THINK,
	FULL,
	DEAD
}	t_status;

typedef pthread_mutex_t	t_mtx;

typedef struct s_data	t_data;

typedef struct s_philo
{
	pthread_t	thread;
	int64_t		id;
	uint64_t	lmt;
	t_mtx		m_lmt;
	t_mtx		*first;
	t_mtx		*second;
	t_data		*data;
}	t_philo;

typedef struct s_data
{
	t_philo		*philos;
	t_mtx		*forks;
	t_mtx		m_all;
	t_mtx		m_finished;
	t_mtx		m_run;
	t_mtx		m_write;
	bool		all;
	bool		finished;
	pthread_t	monitor;
	uint64_t	start;
	int64_t		run;
	int64_t		tc;
	int64_t		ttd;
	int64_t		tts;
	int64_t		tte;
	int64_t		mnum;
}	t_data;

/* inupt/input.c */

int8_t		check_input(int32_t argc, char **argv);
int64_t		ft_atoi(const char *s);

/* init/init.c */

t_data		*init(int32_t argc, char **argv);

/* init/init_utils.c */

void		init_vars(t_data *data);

/* utils/destroy_utils.c */

void		fork_destroy(t_data *data);

/* utils/utils.c */

void		status_put(t_philo *philo, t_status status);
void		inc_dec(t_mtx *mutex, int64_t *addr, t_op op);

/* utils/debug_utils.c */

void		print_data(t_data *data);
void		print_philo(t_philo *philo);

/* utils/get_set.c */

void		set_bool(t_mtx mutex, bool *addr, bool val);
void		set_num(t_mtx mutex, uint64_t *addr, uint64_t val);
bool		get_bool(t_mtx mutex, bool *addr);
int64_t		get_num(t_mtx mutex, int64_t *addr);

/* utils/time_utils.c */

void		real_sleep(uint64_t usec);
void		wait_all(t_data *data);
uint64_t	get_timestamp(t_data *data);
uint64_t	get_time(t_format time_format);

/* threads/simulation.c */

void		simulation(t_data *data);

/* threads/montitor.c */

void		*monitor(void *v_data);

/* threads/dinner.c */

void	dinner(t_philo * philo);

#endif
