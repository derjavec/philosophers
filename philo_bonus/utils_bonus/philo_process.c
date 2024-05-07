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
#include "philo_bonus.h"

void	philo_process(t_rules *rules)
{
	int	i;
//	int	status;

	i = 1;
	while (i <= rules->philo_quantity)
	{
		rules->phi[i].id = i;
		rules->phi[i].x_ate = 0;
		rules->phi[i].dead = 0;
		rules->phi[i].t_last_meal = 0;
		rules->phi[i].rules = rules;
		rules->phi[i].process_id = fork();
		if (rules->phi[i].process_id < 0)
			ft_error("Forking", rules);
		if (rules->phi[i].process_id == 0)
			philosopher_rutine(&rules->phi[i]);
		i++;
	}
}
