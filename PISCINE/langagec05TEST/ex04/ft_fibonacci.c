/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 18:16:43 by qdenizar          #+#    #+#             */
/*   Updated: 2022/07/27 11:58:49 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_fibonacci(int index);


int main()
{
	printf("%d", ft_fibonacci(7));

}


int 	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	if (index ==  1 )
		return (1);
	if (index == 0)
		return (0); 
	return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
}
