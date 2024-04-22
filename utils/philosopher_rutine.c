/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_rutine.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:52:54 by derjavec          #+#    #+#             */
/*   Updated: 2024/04/22 13:52:55 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void		action_print(t_rules *rules, int id, char *string)
{
	pthread_mutex_lock(&(rules->writing));
	if (!(rules->dead))
	{
		printf("%lli ", timestamp() - rules->first_timestamp);
		printf("%i ", id + 1);
		printf("%s\n", string);
	}
	pthread_mutex_unlock(&(rules->writing));
	return ;
}

void	philo_eats(t_philosopher *phi)
{
	t_rules *rules;

	rules = philo->rules;
	pthread_mutex_lock(&(rules->forks[philo->left_fork_id]));
	action_print(rules, philo->id, "has taken a fork");
	pthread_mutex_lock(&(rules->forks[philo->right_fork_id]));
	action_print(rules, philo->id, "has taken a fork");
	pthread_mutex_lock(&(rules->meal_check));
	action_print(rules, philo->id, "is eating");
	philo->t_last_meal = timestamp();
	pthread_mutex_unlock(&(rules->meal_check));
	smart_sleep(rules->time_eat, rules);
	(philo->x_ate)++;
	pthread_mutex_unlock(&(rules->forks[philo->left_fork_id]));
	pthread_mutex_unlock(&(rules->forks[philo->right_fork_id]));
}

void	*philosopher_rutine(void *void_phi)
{
	int				i;
	t_philosopher	*phi;
	t_rules			*rules;

	i = 0;
	phi = (t_philosopher *)void_phi;
	rules = philo->rules;
	if (phi->id % 2)
		usleep(15000);                     //porque 15000?
	while (rules->dead == 0)
	{
		philo_eats(philo);
		if (rules->all_ate == 1)
			break ;
		action_print(rules, philo->id, "is sleeping");
		smart_sleep(rules->time_sleep, rules);
		action_print(rules, philo->id, "is thinking");
		i++;
	}
	return (NULL);
}