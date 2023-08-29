/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 09:01:45 by qdenizar          #+#    #+#             */
/*   Updated: 2022/07/31 15:23:05 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char y)
{
	write(1, &y, 1);
}

void	sauve_moi(void)
{
	write(1, &", ", 2);
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	while (a <= 98)
	{
		b = a + 1;
		while (b <= 99)
		{
			ft_putchar(a / 10 + '0' );
			ft_putchar(a % 10 + '0');
			ft_putchar(' ' );
			ft_putchar(b / 10 + '0');
			ft_putchar(b % 10 + '0');
			if (!(a == 98))
			{	
				sauve_moi();
			}
				b++;
		}
		a++;
	}
}
