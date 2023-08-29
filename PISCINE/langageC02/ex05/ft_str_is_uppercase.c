/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 20:34:19 by qdenizar          #+#    #+#             */
/*   Updated: 2022/07/20 20:42:29 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_uppercase(char *str)
{
	int	i;
	int	answer;

	i = 0;
	answer = 1;
	while (str[i] && answer > 0)
	{
		if (str[i] < 'A' || str[i] > 'Z')
			answer = 0;
		i++;
	}
	return (answer);
}
