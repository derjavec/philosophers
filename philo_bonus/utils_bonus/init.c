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
#include "philo_bonus.h"

static void	init_semaphores(t_rules *rules)
{
	sem_unlink("/sem_forks");
	sem_unlink("/sem_writing");
	sem_unlink("/sem_mealcheck");
	rules->forks = sem_open("/sem_forks", O_CREAT, 0777, rules->philo_quantity);
	rules->writing = sem_open("/sem_writing", O_CREAT, 0777, 1);
	rules->meal_check = sem_open("/sem_mealcheck", O_CREAT, 0777, 1);
	if (rules->forks <= SEM_FAILED || rules->writing <= SEM_FAILED || rules->meal_check <= SEM_FAILED)
		ft_error("Inicializing semaphores", rules);
}

void	init(t_rules *rules, int *data)
{
	rules->philo_quantity = data[0];
	rules->time_until_death = data[1];
	rules->time_to_eat = data[2];
	rules->time_to_sleep = data[3];
	rules->full_philo_quantity = data[4];
	rules->first_timestamp = timestamp();
	init_semaphores(rules);
}
