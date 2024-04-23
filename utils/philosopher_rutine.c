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

static void	wait(long long time, t_rules *rules)
{
	long long start_time;
	long long current_time;

	start_time = timestamp();
	while (rules->dead == 0)
	{
		current_time = timestamp();
		if (current_time - start_time >= time)
			break ;
		usleep(50);
	}
}

static void	philo_eats(t_philosopher *phi)
{
	t_rules *rules;

	rules = phi->rules;
	pthread_mutex_lock(&(rules->forks[phi->left_fork_id]));
	print_action(rules, phi->id, "has taken left fork");
	pthread_mutex_lock(&(rules->forks[phi->right_fork_id]));
	print_action(rules, phi->id, "has taken right fork");
	pthread_mutex_lock(&(rules->meal_check));
	print_action(rules, phi->id, "is eating");
	phi->t_last_meal = timestamp();
	pthread_mutex_unlock(&(rules->meal_check));
	wait(rules->time_to_eat, rules);
	(phi->x_ate)++;
	pthread_mutex_unlock(&(rules->forks[phi->left_fork_id]));
	pthread_mutex_unlock(&(rules->forks[phi->right_fork_id]));
}

void	*philosopher_rutine(void *void_phi)
{
	int				i;
	t_philosopher	*phi;
	t_rules			*rules;

	i = 0;
	phi = (t_philosopher *)void_phi;
	rules = phi->rules;
	if (phi->id % 2 == 1)
		usleep(rules->time_to_eat * 100);
	while (rules->dead == 0 && rules->all_ate == 0)
	{
		philo_eats(phi);
		print_action(rules, phi->id, "is sleeping");
		wait(rules->time_to_sleep, rules);
		print_action(rules, phi->id, "is thinking");
		check_saved_or_dead(rules, phi);
		i++;
	}
	return (NULL);
}