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
#include "philo_bonus.h"

static void	ft_wait(long long time, t_rules *rules)
{
	long long	start_time;
	long long	current_time;

	start_time = timestamp();
	while (rules->phi->dead == 0)
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
	if (sem_wait(rules->forks) == 0)
		print_action(rules, phi->id, "has taken a fork");
	while ((timestamp() - rules->first_timestamp) - phi->t_last_meal <= rules->time_until_death)
	{
		if (sem_trywait(rules->forks) == 0)
		{
			print_action(rules, phi->id, "has taken another fork");
			sem_wait(rules->meal_check);
			phi->t_last_meal = timestamp() - rules->first_timestamp;
			print_action(rules, phi->id, "is eating");
			sem_post(rules->meal_check);
			ft_wait(rules->time_to_eat, rules);
			(phi->x_ate)++;
			sem_post(rules->forks);
			sem_post(rules->forks);
			return ;
		}
	}
	print_action(rules, phi->id, "died");
	phi->dead = 1;
	sem_post(rules->forks);
	sem_post(rules->forks);
}

void	*philosopher_rutine(void *void_phi)
{
	int				i;
	t_philosopher	*phi;
	t_rules			*rules;

	phi = (t_philosopher *)void_phi;
	rules = phi->rules;
	if (phi->id % 2 == 0 || phi->id == rules->philo_quantity)
		ft_wait(rules->time_to_eat, rules);	
	i = 0;	
	while (phi->dead == 0)
	{
		philo_eats(phi);
		if (phi->dead == 1)
			break ;
		if (rules->full_philo_quantity != 0 && phi->x_ate == rules->full_philo_quantity)
			break ;
		print_action(rules, phi->id, "is sleeping");
		ft_wait(rules->time_to_sleep, rules);
		print_action(rules, phi->id, "is thinking");
		check_if_philo_died(rules, phi);
		i++;
	}
	return (NULL);
}
