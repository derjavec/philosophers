/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 08:38:36 by derjavec          #+#    #+#             */
/*   Updated: 2024/04/26 08:38:37 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <semaphore.h>

typedef	struct			s_philosopher
{
	int					id;
	int					x_ate;
	long long				t_last_meal;
	struct s_rules			*rules;
	pthread_t				thread_id;
	pid_t				process_id;
}						t_philosopher;

typedef struct			s_rules
{
	int			philo_quantity;
	int			time_until_death;
	int			time_to_eat;
	int			time_to_sleep;
	int			full_philo_quantity;
	int			dead;
	long long		first_timestamp;
	sem_t		meal_check;
	sem_t		forks[200];
	sem_t		writing;
	t_philosopher	phi[200];
}					t_rules;

size_t	ft_strlen( const char *c);

int       ft_atoi(const char *str, t_rules *rules);

void      ft_error(char *msg, t_rules *rules);
void      init(t_rules *rules, int *data);
void		philo_process(t_rules *rules);
void		check_if_philo_died(t_rules *rules, t_philosopher *phi);
void		*philosopher_rutine(void *void_phi);
void		print_action(t_rules *rules, int id, char *str);
void 	clean_semaphores(t_rules *rules, t_philosopher *phi);

long long	timestamp(void);                          
#endif

