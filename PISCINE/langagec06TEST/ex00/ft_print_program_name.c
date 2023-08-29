/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 14:01:08 by qdenizar          #+#    #+#             */
/*   Updated: 2022/07/27 16:07:49 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>
#include <string.h>

void	ft_putstr(char *str);
void	ft_putchar(char c);

int main(int argc, char **argv)
{
	(void) argc;
	ft_putstr(argv[0]); // va aficcher le premier tableau de argv qui contient le nom du fichier 
	ft_putchar('\n');
	return (0);
}


void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write (1, &str[i], 1);
		i++;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}


