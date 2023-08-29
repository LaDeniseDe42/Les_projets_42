/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 21:27:16 by qdenizar          #+#    #+#             */
/*   Updated: 2022/07/20 21:43:31 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_str_is_printable(char *str)
{
	int	i;
	int	answer;

	i = 0;
	answer = 1;
	while (str[i] && answer > 0)
	{
		if (str[i] < ' ' || str[i] > '~')
			answer = 0;
		i++;
	}
	return (answer);
}
