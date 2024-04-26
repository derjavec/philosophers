/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_semaphores.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:28:35 by derjavec          #+#    #+#             */
/*   Updated: 2024/04/25 15:23:31 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

static void	wait_semaphores_to_finish(t_rules *rules, t_philosopher *phi)
{
	sem_close(rules->sem_forks);
	sem_close(rules->sem_writing);
	sem_close(rules->sem_meal_check);
	sem_unlink("/sem_forks");
	sem_unlink("/sem_write");
	sem_unlink("/sem_mealcheck");
}

static void	close_semaphores(t_rules *rules)
{
	int	i;
	int	status;

	i = 1;
	while (i <= rules->philo_quantity)
	{
		waitpid(-1, &status, 0);
		if (status != 0)
		{
			i = 1;
			while (i <= rules->philo_quantity)
			{
				kill(rules->phi[i].process.id, 15);
				i++;
			}
			break ;
		}
		i++;
	}
}

void	clean_semaphores(t_rules *rules, t_philosopher *phi)
{
	wait_semaphores_to_finish(rules, phi);
	close_semaphores(rules);
}
