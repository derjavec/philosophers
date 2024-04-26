/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 11:00:44 by derjavec          #+#    #+#             */
/*   Updated: 2024/04/25 15:02:34 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

static void	fill_data_array(int argc, char *argv[], int *data, t_rules *rules)
{
	int	i;

	if (argc < 5 || argc > 6)
		ft_error("Wrong number of arguments", rules);
	i = 0;
	while (i < argc - 1)
	{
		data[i] = ft_atoi(argv[i + 1], rules);
		if (data[i] < 0 || (data == 0 && i < 5))
			ft_error("One or more zero or negative arguments found", rules);
		if (data[0] > 200)
			ft_error("Please not more than 200 philosophers", rules);
		i++;
	}
	if (i == 4)
		data[4] = 0;
	return ;
}

int	main(int argc, char *argv[])
{
	int		data[5];
	t_rules	*rules;
	int	i;

	rules = malloc(sizeof(t_rules));
	if (rules == NULL)
		ft_error("Malloc error in main function", rules);
	fill_data_array(argc, argv, data, rules);
	init(rules, data);
	philo_threads(rules);
	i = 1;
	while (1)
	{
		if ((rules->full_philo_quantity != 0 && rules->phi[i].x_ate == rules->full_philo_quantity) || rules->dead == 1)
			break ;
		if (i > rules->philo_quantity)
			i = 1;
		if (rules->phi[i].x_ate < rules->full_philo_quantity && (timestamp() - rules->first_timestamp) - rules->phi[i].t_last_meal > rules->time_until_death)
		{
			print_action(rules, rules->phi[i].id, "died");
			rules->dead = 1;
			break ;
		}
		i++;
	}	
	clean_threads(rules, rules->phi);
	free(rules);
	return (0);
}
