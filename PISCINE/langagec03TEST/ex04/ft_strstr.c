/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 08:29:05 by qdenizar          #+#    #+#             */
/*   Updated: 2022/07/25 11:09:38 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <unistd.h>

char	*ft_strstr(char *str, char *to_find);

int main()
{
	char	str[100] = "4";
	char	to_find[100] = "1";

	printf("1: %s\n", ft_strstr(str, to_find));
	printf("2: %s", strstr(str, to_find));

}



char	*ft_strstr(char *str, char *to_find)
{
	int i;
	int j;	
	
	i = 0;
	j = 0;
		if (to_find[j] == '\0')
			return (str);
		if (str[i] == '\0')
			return (0);
	
	while (str[i])
	{
		while (to_find[j] == str[i + j] && to_find[j])
		{
			j++;
		}
		if (to_find[j] == '\0')
			return (str + i);
		i++;
	j = 0 ;
	}
	return (0);
}
