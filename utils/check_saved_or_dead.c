/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_saved_or_dead.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 09:56:06 by derjavec          #+#    #+#             */
/*   Updated: 2024/04/23 09:56:07 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

static void check_dead_philos(t_rules *rules, t_philosopher *phi)
{

     pthread_mutex_lock(&(rules->meal_check));
     if (timestamp() - phi->t_last_meal > rules->time_until_death)
     {
          printf("%lld\n", phi->t_last_meal);
          print_action(rules, phi->id, "died");
          rules->dead = 1;
     }
     pthread_mutex_unlock(&(rules->meal_check));   
}

static void check_all_ate(t_rules *rules, t_philosopher *phi)
{
     int  i;
     static int  check = 0;

     i = 0;
     while (i < rules->philo_quantity)
     {
          pthread_mutex_lock(&(rules->meal_check));
          if (phi[i].x_ate == rules->full_philo_quantity)
               check++;
          printf("%d\n", check);
          if (check == rules->philo_quantity)
               rules->all_ate = 1;
          i++;
          pthread_mutex_unlock(&(rules->meal_check));
     }   
}

void check_saved_or_dead(t_rules *rules, t_philosopher *phi)
{
     check_all_ate(rules, phi);
     check_dead_philos(rules, rules->phi);
}