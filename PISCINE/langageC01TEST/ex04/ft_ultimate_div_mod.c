/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 17:12:15 by qdenizar          #+#    #+#             */
/*   Updated: 2022/07/17 20:14:35 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b);

int main()
{
	int c;
	int d;

	c = 20;
	d = 6;
	ft_ultimate_div_mod(&c, &d);
	printf("%d ..... %d",c, d);
	return(0);
}


void	ft_ultimate_div_mod(int *a, int *b)
{
	int resultA;
	int resultB;
	
	
	resultA = *a / *b;
	resultB = *a % *b;
	*a = resultA;
	*b = resultB;
	}


