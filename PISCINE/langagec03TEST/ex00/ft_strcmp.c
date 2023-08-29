/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 14:13:05 by qdenizar          #+#    #+#             */
/*   Updated: 2022/07/24 19:58:39 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> 
#include <string.h>

int	ft_strcmp(char *s1, char *s2);


int main()
{
	char	s1[] = "awfewfewfw";
	char	s2[] = "ffwef:w";
	printf("%d\n", ft_strcmp(s1, s2));
	printf("%d", strcmp(s1, s2));
	return (0);
}


int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}
