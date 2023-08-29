/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 15:15:54 by qdenizar          #+#    #+#             */
/*   Updated: 2022/08/03 16:26:31 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_swap(char *a, char *b);

char *ft_rev_print (char *str)
{
	int i;
	int j;
	
	i = 0;
	j = 0;
	while (str[i])
	{
		i++;
	}
	i--;
	while (i > j)
	{
		ft_swap(&str[j], &str[i]);
		j++;
		i--;
	}	
	return (str);
}

void	ft_swap(char *a, char *b)
{
	char c;
	c = *a;
	*a = *b;
	*b = c;
}


int main()
{
	char belette[100] = "La belette n'est pas une belette";
	printf("%s", ft_rev_print(belette));

	return (0);
}
