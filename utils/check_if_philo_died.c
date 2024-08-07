/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_philo_died.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <derjavec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 09:56:06 by derjavec          #+#    #+#             */
/*   Updated: 2024/08/07 17:24:02 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	kill_philo(t_rules *rules, int i)
{
	print_action(rules, rules->phi[i].id, "died");
	pthread_mutex_lock(&(rules->dead_check));
	rules->dead = 1;
	pthread_mutex_unlock(&(rules->dead_check));
	pthread_mutex_unlock(&(rules->meal_check));
}

void	check_if_philo_died(t_rules *rules)
{
	int	i;

	i = 1;
	while (rules->philo_ate_all < rules->philo_quantity)
	{
		while (i <= rules->philo_quantity && rules->dead == 0)
		{
			pthread_mutex_lock(&(rules->meal_check));
			if ((timestamp() - rules->first_timestamp) \
				- rules->phi[i].t_last_meal > rules->time_until_death)
			{
				kill_philo(rules, i);
				break ;
			}
			pthread_mutex_unlock(&(rules->meal_check));
			i++;
		}
		if (rules->dead != 0)
			break ;
		i = 1;
		if (rules->full_philo_quantity != 0 \
			&& rules->phi[i].x_ate >= rules->full_philo_quantity)
			rules->philo_ate_all++;
	}
}
