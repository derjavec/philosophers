/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 08:47:21 by derjavec          #+#    #+#             */
/*   Updated: 2024/04/03 08:47:22 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

void	ft_error(char *msg, t_rules *rules)
{
	size_t	i;

	write(2, "Error:", 6);
	i = 0;
	while (i < ft_strlen(msg))
		write(2, &msg[i++], 1);
	write(2, "\n", 1);
	if (rules)
		free(rules);
	exit(EXIT_FAILURE);
}
