/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:11:59 by derjavec          #+#    #+#             */
/*   Updated: 2024/04/23 11:12:00 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	print_action(t_rules *rules, int id, char *str)
{
	pthread_mutex_lock(&(rules->writing));
	if (rules->dead == 0)
	{
		printf("%lli ", timestamp() - rules->first_timestamp);
		printf("%i ", id);
		printf("%s\n", str);
	}
	pthread_mutex_unlock(&(rules->writing));
	return ;
}
