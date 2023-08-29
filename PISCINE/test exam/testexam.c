/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testexam.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 13:58:58 by qdenizar          #+#    #+#             */
/*   Updated: 2022/07/29 14:33:52 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h> 

void	ft_swap(int *a, int *b);

int main(int argv, char **argc)
{
	int *a;
	int *b;
	int c;
	int d;

	c = 50;
	d = 20;
	a = &c;
	b = &d;
	(void) argv;
	(void) argc;
	
	ft_swap(a, b);
	printf("%d\n", *a);
	printf("%d", *b);

	return (0);
}


void ft_swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}
