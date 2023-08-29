/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 09:03:02 by qdenizar          #+#    #+#             */
/*   Updated: 2022/07/27 18:28:58 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>

int	ft_sqrt(int nb);


int main()
{
	printf("%d", ft_sqrt(2147483645));
}


int	ft_sqrt(int nb)
{
	int i;

	i = 0;
	while ( i < nb && i <= 46341)
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	return (0);

}

