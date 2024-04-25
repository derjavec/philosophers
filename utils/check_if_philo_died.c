/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_philo_died.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 09:56:06 by derjavec          #+#    #+#             */
/*   Updated: 2024/04/25 15:19:43 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	check_if_philo_died(t_rules *rules, t_philosopher *phi)
{
	pthread_mutex_lock(&(rules->meal_check));
	if (timestamp() - phi->t_last_meal > rules->time_until_death)
	{
		print_action(rules, phi->id, "died");
		rules->dead = 1;
	}
	pthread_mutex_unlock(&(rules->meal_check));
}
