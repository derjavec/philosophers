/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 08:47:09 by derjavec          #+#    #+#             */
/*   Updated: 2024/04/03 08:47:11 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philoh"

size_t	ft_strlen( const char *c)
{
	int	i;

	i = 0;
	while (c[i])
		i++;
	return (i);
}
