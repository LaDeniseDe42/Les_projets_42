/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 13:36:53 by qdenizar          #+#    #+#             */
/*   Updated: 2022/08/03 13:45:08 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_print_numbers(void)
{
	ft_putstr("123456789");
}


void	ft_putstr(char *a)
{
	int i;

	i = 0;
	while (a[i])
	{
		write (1, &a, 1);
		i++;
	}
}

int	main()
{

	ft_print_numbers();
	return (0);
}
