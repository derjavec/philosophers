/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:28:35 by derjavec          #+#    #+#             */
/*   Updated: 2024/04/23 11:28:37 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

static void    wait_threads_to_finish(t_rules *rules, t_philosopher *phi)
{
     int  i;

     i = 0;
     while (i < rules->philo_quantity)
     {
          pthread_join(phi[i].thread_id, NULL);
          i++;
     }
}

static void    destroy_mutex(t_rules *rules)
{
     int  i;

     i = 0;
     while (i < rules->philo_quantity)
     {
          pthread_mutex_destroy(&(rules->forks[i]));
          i++;
     }
     pthread_mutex_destroy(&(rules->writing));
     pthread_mutex_destroy(&(rules->meal_check));
}

void clean_threads(t_rules *rules, t_philosopher *phi)
{
     printf("lala\n");
     wait_threads_to_finish(rules, phi);
     destroy_mutex(rules);
}
