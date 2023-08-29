/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_a.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 11:01:03 by qdenizar          #+#    #+#             */
/*   Updated: 2022/08/03 11:55:19 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_trouvemona(char *a);

int main(int argc, char **argv)
{
	(void) argc;
	ft_trouvemona(argv[1]);
	return (0);
}


void	ft_putchar(char *a)
{
	write(1, &a, 1);
}


void	ft_putstr(char *a)
{
	int i;

	i = 0;
	while (a[i])
	{
		write(1, &a, 1);
		i++;
	}
}

int	ft_strlen(char *a)
{
	int i;

	i = 0;
	while (a[i])
		i++;
	return (i);
}

int	ft_trouvemona(char *a)
{
	int i ; 

	i = 0;
	while (a[i])
	{
		if (a[i] == 'a')
		{
			write (1, "a", 1);
			write (1, "\n", 1);
			return (0);
		}
		i++;
	}
	write (1, "\n", 1);
	return (0);
}
