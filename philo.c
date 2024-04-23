/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 11:00:44 by derjavec          #+#    #+#             */
/*   Updated: 2024/04/22 11:00:45 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

static int *fill_data_array(int argc, char *argv[])
{
     int  i;
     int  *data;

     if (argc < 5 || argc > 6)
          ft_error("Wrong number of arguments");
     data = malloc((argc - 1) * sizeof(int));
     if (data == NULL)
          ft_error("Malloc error in fill_data_array function");
     i = 0;  
     while (i < argc -1)
     {
          data[i] = ft_atoi(argv[i + 1], data);
          if (data[i] < 0 || (data == 0 && i < 5))
          {
               free (data);
               ft_error("One or more zero or negative arguments found");
          }
          if (data[0] > 200)
          {
               free (data);
               ft_error("Please not more than 200 philosophers");
          }
          i++;
     }
     return (data);
}

int  main(int argc, char *argv[])
{
     int  *data;
     t_rules   *rules;

     data = fill_data_array(argc, argv);
     rules = malloc(sizeof(t_rules));
     if (rules == NULL)
       ft_error("Malloc error in main function");   
     init(rules, data);
     philo_threads(rules);
     clean_threads(rules, rules->phi);
}

