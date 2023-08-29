/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 13:14:04 by jthomas           #+#    #+#             */
/*   Updated: 2022/07/21 15:46:37 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	printx(int x)
{
	if (x-- > 0)
	{
		ft_putchar('o');
	}
	if (x == 0)
	{
		ft_putchar('\n');
		return ;
	}
	if (x > 1)
	{
		x -= 1;
		while (x-- > 0)
		{
			ft_putchar('-');
		}
	}
	if (x == 0)
		return ;
	ft_putchar('o');
	ft_putchar('\n');
}

void	printy(int x, int y)
{
	int	c;

	x = x - 2;
	c = x;
	y = y - 2;
	while (y-- > 0)
	{
		ft_putchar('|');
		while (x-- > 0)
		{	
			ft_putchar(' ');
		}
		x = c;
		ft_putchar('|');
		ft_putchar('\n');
	}
}

void	rush(int x, int y)
{
	printx(x);
	printy(x, y);
	printx(x);
}
