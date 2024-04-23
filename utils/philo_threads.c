/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 14:02:43 by derjavec          #+#    #+#             */
/*   Updated: 2024/04/23 14:02:45 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void    philo_threads(t_rules *rules)
{
     int  i;

     i = 0;
     while (i < rules->philo_quantity)
     {
          rules->phi[i].id = i;
          rules->phi[i].x_ate = 0;
          rules->phi[i].left_fork_id = i;
          rules->phi[i].right_fork_id = (i + 1) % rules->philo_quantity;
          rules->phi[i].t_last_meal = 0;
          rules->phi[i].rules = rules;
          pthread_create(&(rules->phi[i].thread_id), NULL, philosopher_rutine, &(rules->phi[i]));
          i++;
     }
}
