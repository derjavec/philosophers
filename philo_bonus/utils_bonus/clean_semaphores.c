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
#include "philo_bonus.h"

static void	wait_semaphores_to_finish(t_rules *rules)
{
	if (sem_close(rules->meal_check) == -1)
		ft_error("Closing writing semaphore", rules);
	if (sem_close(rules->writing) == -1)
		ft_error("Closing writing semaphore", rules);
	if (sem_close(rules->forks) == -1)
		ft_error("Closing forks semaphore", rules);
	if (sem_unlink("/sem_mealcheck") == -1)
		ft_error("Unlinking meal_check semaphore", rules);
	if (sem_unlink("/sem_writing") == -1)
		ft_error("Unlinking writing semaphore", rules);
	if (sem_unlink("/sem_forks") == -1)
		ft_error("Unlinking forks semaphore", rules);
}

static void	close_semaphores(t_rules *rules)
{
	int	i;
	int	status;

	i = 1;
	while (i <= rules->philo_quantity)
	{
		waitpid(rules->phi[i].process_id, &status, 0);
		if (status!= 0)
		{
			while (i <= rules->philo_quantity)
			{
				kill(rules->phi[i].process_id, 15);
				i++;
			}
			break ;
		}		
		i++;
	}
}

void	clean_semaphores(t_rules *rules)
{
	wait_semaphores_to_finish(rules);
	close_semaphores(rules);
}
