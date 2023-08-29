/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 16:44:08 by qdenizar          #+#    #+#             */
/*   Updated: 2022/08/01 09:06:13 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h> 
#include <string.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n);


int main()
{
	char	s1[] = "ddaaa";
	char	s2[] = "ddaak  llk";
	unsigned int yo = 5;
	
	printf("%d\n", ft_strncmp(s1, s2, yo));
	printf("%d\n", strncmp(s1, s2, yo));
}


int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int i;
	
	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	printf("%d\n", i);
	return (0);
}
