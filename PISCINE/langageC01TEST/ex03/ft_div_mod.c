/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 14:31:13 by qdenizar          #+#    #+#             */
/*   Updated: 2022/07/17 15:21:28 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod);


int main()
{
	int a;
	int b;
	int c;
	int d;
	c = 0;
	d = 0;
	int *div;
	int *mod;
	div = &c;
	mod = &d;
	a = 20;
	b = 6;

	ft_div_mod(a, b, div, mod);
	printf("%d  ...... %d", *div, *mod);
	return (0);
}

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b ;
	*mod = a % b ;
}

