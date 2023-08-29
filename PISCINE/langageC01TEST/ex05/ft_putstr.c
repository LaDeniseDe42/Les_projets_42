/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 08:23:40 by qdenizar          #+#    #+#             */
/*   Updated: 2022/07/18 13:55:18 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putstr(char *str);


int main()
{
	char *str;
	str = "Est ce aue ca marche ?";
	ft_putstr(str);
	return;
}

void	ft_putstr(char *str)
{
	char  i;
	i = 0;
	char chaine[i];

	while(str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}
