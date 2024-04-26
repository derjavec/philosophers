/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 14:02:43 by derjavec          #+#    #+#             */
/*   Updated: 2024/04/25 15:22:07 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	philo_process(t_rules *rules)
{
	int	i;

	i = 1;
	while (i <= rules->philo_quantity)
	{
		rules->phi[i].id = i;
		rules->phi[i].x_ate = 0;
		rules->phi[i].left_fork_id = i;
		rules->phi[i].right_fork_id = (i + 1) % rules->philo_quantity;
		if (rules->phi[i].right_fork_id == 0)
			rules->phi[i].right_fork_id = rules->philo_quantity;
		rules->phi[i].t_last_meal = 0;
		rules->phi[i].rules = rules;
		rules->phi[i].thread_id = 0;
		phi[i].process.id = fork();
		if (phi[i].process.id < 0)
			ft_error("Forking", rules);
		if (phi[i].process.id == 0)
			philosopher_rutine(phi[i]);		
		i++;
	}
}
