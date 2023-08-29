/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 11:36:05 by qdenizar          #+#    #+#             */
/*   Updated: 2022/08/01 13:00:55 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


int	*ft_range(int min, int max)
{
	int i;
	int	*tab;

	i = 0;
	if (min > max)
		return (NULL);
	tab = malloc((max - min) * sizeof(*tab));
	if (tableau_int == 0)
		return (NULL);
	while (min < max)
		tab[i++] = min++;
	tab[i] = '\0';
		
	return (tab);		

}

int main()
{
	int	min =5;
	int	max = 10;
	printf("%d\n", ft_range(min, max));

	return (0);
}
