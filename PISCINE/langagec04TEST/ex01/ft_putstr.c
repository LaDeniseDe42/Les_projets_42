/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 11:06:39 by qdenizar          #+#    #+#             */
/*   Updated: 2022/07/24 12:07:50 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>

void	ft_putstr(char *str);

int	main()
{
	char	str[100] = "Axel a mis un 0 a ali";
	ft_putstr(str);

}


void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		write (1, &str[i], 1);
		i++;
	}
}
