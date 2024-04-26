/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 11:00:33 by derjavec          #+#    #+#             */
/*   Updated: 2024/04/22 11:00:34 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef	struct			s_philosopher
{
	int					id;
	int					x_ate;
	int					left_fork_id;
	int					right_fork_id;
	long long				t_last_meal;
	struct s_rules			*rules;
	pthread_t				thread_id;
}						t_philosopher;

typedef struct			s_rules
{
	int					philo_quantity;
	int					time_until_death;
	int					time_to_eat;
	int					time_to_sleep;
	int					full_philo_quantity;
	int					dead;
	long long				first_timestamp;
	pthread_mutex_t		meal_check;
	pthread_mutex_t		forks[200];
	pthread_mutex_t		writing;
	t_philosopher			phi[200];
}
						t_rules;
size_t	ft_strlen( const char *c);

int       ft_atoi(const char *str, t_rules *rules);

void      ft_error(char *msg, t_rules *rules);
void		wait(long long time, t_rules *rules);
void      init(t_rules *rules, int *data);
void		philo_threads(t_rules *rules);
void		check_if_philo_died(t_rules *rules, t_philosopher *phi);
void		*philosopher_rutine(void *void_phi);
void		print_action(t_rules *rules, int id, char *str);
void 	clean_threads(t_rules *rules, t_philosopher *phi);

long long	timestamp(void);
#endif