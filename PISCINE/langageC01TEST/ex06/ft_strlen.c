/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:52:07 by qdenizar          #+#    #+#             */
/*   Updated: 2022/07/18 17:00:21 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_strlen(char *str);


int main()
{
	char *str;
	int len_str;
	str = "Est ce aue ca marche ?";
	len_str = ft_strlen(str);
	printf("%d\n", len_str);
	return (0);
}

int	ft_strlen(char *str)
{
	int  i;
	i = 0;

	while(str[i])
	{
		i++;
	}
	
	return (i);
}
