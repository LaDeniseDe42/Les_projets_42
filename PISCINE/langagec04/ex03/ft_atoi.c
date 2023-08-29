/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 08:30:10 by qdenizar          #+#    #+#             */
/*   Updated: 2022/07/25 19:35:33 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int	ft_atoi(char *str)
{
	int	i;
	int	j;
	int	sign;

	i = 0;
	j = 0;
	sign = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r' )
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign++;
		i++;
	}	
	while (str[i] >= '0' && str[i] <= '9')
	{
		j = str[i] - '0' + j * 10;
		i++;
	}
	if (sign % 2 == 1)
		return (-j);
	return (j);
}
