/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 13:36:53 by qdenizar          #+#    #+#             */
/*   Updated: 2022/08/03 14:11:20 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
void	ft_putstr(char *a);

void	ft_print_numbers(void)
{
	char put;

	put = '0';
		while (put != 'z')
	{
		write (1, &put, 1);
		write(1, "\n", 1);
		put++;
	}
}
int	main()
{

	ft_print_numbers();
	return (0);
}

