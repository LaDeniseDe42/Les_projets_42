/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 12:05:23 by qdenizar          #+#    #+#             */
/*   Updated: 2022/07/26 12:26:39 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_recursive_factorial(int nb);

int main()
{
printf("%d", ft_recursive_factorial(10));
}


int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	if ( nb == 0)
		return (1);
	else 
		return (nb * ft_recursive_factorial(nb-1));
	}
