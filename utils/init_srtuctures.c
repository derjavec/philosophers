/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:23:59 by derjavec          #+#    #+#             */
/*   Updated: 2024/04/22 12:24:01 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

static void    init_philo(t_rules *rules, int *data)
{
     int  i;

     i = 0;
     while (i < num_philosophers)
     {
          rules->phi[i].id = i;
          rules->phi[i].x_ate = 0;
          rules->phi[i].left_fork_id = i;
          rules->phi[i].right_fork_id = (i + 1) % num_philosophers;
          rules->phi[i].t_last_meal = 0;
          rules->phi[i].rules = rules;
          pthread_create(&(rules->phi[i].thread_id), NULL, philosopher_rutine, &(rules->phi[i]));
          i++;
     }
      i = 0;
      while (i < num_philosophers)
     {
          pthread_mutex_init(&(rules->forks[i]), NULL);
          i++;
     }
}

void init_structures(t_rules *rules, int *data)
{   
     rules->nb_philo = data[0];
     rules->time_death = data[1];
     rules->time_eat = data[2];
     rules->time_sleep = data[3];
     rules->nb_eat = data[4];
     rules->dead = 0;
     rules->all_ate = 0;
     rules->first_timestamp = 0;
     pthread_mutex_init(&(rules->meal_check), NULL);
     pthread_mutex_init(&(rules->writing), NULL);
     init_philo(rules, data);
}


