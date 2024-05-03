/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 08:38:55 by derjavec          #+#    #+#             */
/*   Updated: 2024/04/26 08:38:57 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo_bonus.h"

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
	return ;
}

int	main(int argc, char *argv[])
{
	int		data[argc - 1];
	t_rules	*rules;

	rules = malloc(sizeof(t_rules));
	if (rules == NULL)
		ft_error("Malloc error in main function", rules);
	fill_data_array(argc, argv, data, rules);
	init(rules, data);
	philo_process(rules);
	clean_semaphores(rules);
	free(rules);
	return (0);
}
