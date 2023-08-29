/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 09:49:06 by qdenizar          #+#    #+#             */
/*   Updated: 2022/07/27 12:05:56 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>

int	ft_is_prime(int nb);

int main()
{
	printf("%d", ft_is_prime(-2147483647));
}

int	ft_is_prime(int nb)
{
	int i;

	i = 2;
	if ( nb <= 1)
		return (0);
	while ( i < 47000 && i < nb ) // racine carre ( 47000 = racine carre max
	{
		if ( nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

