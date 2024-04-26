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

void	wait(long long time, t_rules *rules)
{
	long long	start_time;
	long long	current_time;

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
	t_rules	*rules;

	rules = phi->rules;
	sem_wait(rules->sem_forks);
	print_action(rules, phi->id, "has taken a fork");
	while ((timestamp() - rules->first_timestamp) - phi->t_last_meal <= rules->time_until_death)
	{
		if (sem_trywait(rules->sem_forks)== 0)
		{
			print_action(rules, phi->id, "has taken right fork");
			sem_wait(rules->sem_mealcheck);
			phi->t_last_meal = timestamp() - rules->first_timestamp;
			print_action(rules, phi->id, "is eating");
			sem_post(rules->sem_mealcheck);
			wait(rules->time_to_eat, rules);
			(phi->x_ate)++;
			sem_post(rules->sem_forks);
			return ;
		}
	}
	print_action(rules, phi->id, "died");
	rules->dead = 1;
	sem_post(rules->sem_forks);
}

void	*philosopher_rutine(void *void_phi)
{
	int				i;
	t_philosopher	*phi;
	t_rules			*rules;

	phi = (t_philosopher *)void_phi;
	rules = phi->rules;
	i = 0;
	if (phi->id % 2 == 0 || phi->id == rules->philo_quantity)
		wait(rules->time_to_eat, rules);	
	while (rules->dead == 0)
	{
		philo_eats(phi);
		if (rules->full_philo_quantity != 0 && phi->x_ate == rules->full_philo_quantity)
			break ;
		print_action(rules, phi->id, "is sleeping");
		wait(rules->time_to_sleep, rules);
		print_action(rules, phi->id, "is thinking");
		check_if_philo_died(rules, phi);
		i++;
	}
	return (NULL);
}
