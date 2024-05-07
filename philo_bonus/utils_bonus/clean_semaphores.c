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

void	clean_semaphores(t_rules *rules)
{
	if (sem_close(rules->meal_check) == -1)
		ft_error("Closing writing semaphore", rules);
	if (sem_close(rules->writing) == -1)
		ft_error("Closing writing semaphore", rules);
	if (sem_close(rules->forks) == -1)
		ft_error("Closing forks semaphore", rules);
}
