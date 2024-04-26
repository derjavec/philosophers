/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:23:59 by derjavec          #+#    #+#             */
/*   Updated: 2024/04/25 15:24:58 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

static void	init_mutex(t_rules *rules)
{
	int	i;

	pthread_mutex_init(&(rules->meal_check), NULL);
	pthread_mutex_init(&(rules->writing), NULL);
	i = 1;
	while (i <= rules->philo_quantity)
	{
		pthread_mutex_init(&(rules->forks[i]), NULL);
		i++;
	}
}

void	init(t_rules *rules, int *data)
{
	rules->philo_quantity = data[0];
	rules->time_until_death = data[1];
	rules->time_to_eat = data[2];
	rules->time_to_sleep = data[3];
	rules->full_philo_quantity = data[4];
	rules->dead = 0;
	rules->first_timestamp = timestamp();
	init_mutex(rules);
}
