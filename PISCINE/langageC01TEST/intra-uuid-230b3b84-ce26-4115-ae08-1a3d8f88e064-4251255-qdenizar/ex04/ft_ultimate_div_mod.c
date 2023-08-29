/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 17:12:15 by qdenizar          #+#    #+#             */
/*   Updated: 2022/07/19 13:58:31 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	result_a;
	int	result_b;

	result_a = *a / *b;
	result_b = *a % *b;
	*a = result_a;
	*b = result_b;
}
