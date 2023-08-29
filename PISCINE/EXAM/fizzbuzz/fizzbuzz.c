/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 09:36:20 by qdenizar          #+#    #+#             */
/*   Updated: 2022/08/04 11:57:52 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
							
void	ft_putchars(char c)
{
	write (1, &c, 1);
}		
	
void	ft_put_nbr(int nbr)
{
	if (nbr < 10)
		ft_putchars(nbr + '0');
	else
	{
		ft_put_nbr(nbr / 10);
		ft_put_nbr(nbr % 10);
	}
}	

void	ft_fizz_buzz(void)
{
	int 	i;
	
	i = 1;
	while (i <= 100)
	{
		if ((i % 3 ==0) && (i % 5 == 0))
			write(1, "fizz", 4);
		else if (i % 3 == 0)
			write(1, "buzz", 4);
		else if (i % 5 == 0)
			write(1, "fizzbuzz", 8);			
		else
			ft_put_nbr(i);
		write(1, "\n", 1);
	i++;
	}
}

int	main()
{
	ft_fizz_buzz();
	return (0);
}
