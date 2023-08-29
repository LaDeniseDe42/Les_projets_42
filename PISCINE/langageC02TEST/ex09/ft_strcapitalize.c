/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 10:37:07 by qdenizar          #+#    #+#             */
/*   Updated: 2022/07/31 12:39:21 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcapitalize(char *str);

int main()
{
	char test[] ="SalutzzZZAJe su8iS+Un Peu  n  ch554EeeeIlo --ooo+Uuu muhAh1RGFDah$E#@!!!! UN 0";

	ft_strcapitalize(test);
	printf("%s", ft_strcapitalize(test));

}

char	*ft_strcapitalize(char *str)
{
	int i;
	
	i = 0;
	while(str[i])
	{
		if ((str[i-1] >= 'A' && str[i] <= 'Z') && (str[i] >= 'A' && str[i] <= 'Z'))
			str[i] = str[i] + 32; 
		if ((str[i-1] >= ' ' && str[i-1] <= '/') && (str[i] >= 'a' && str[i] <= 'z'))
			str[i] = str[i] - 32;
		if ((str[i-1] >= ':' && str[i-1] <= '@') && (str[i] >= 'a' && str[i] <= 'z'))
			str[i] = str[i] -32;
		if ((str[i-1] >= '[' && str[i-1] <= '`') && (str[i] >= 'a' && str[i] <= 'z'))
			str[i] = str[i] -32;
		if ((str[i-1] >= '{' && str[i-1] <= '~') && (str[i] >= 'a' && str[i] <= 'z'))
				str[i] = str[i] - 32;
		if ((str[i-1] >= '0' && str[i-1] <= '9') && (str[i] >= 'A' && str[i] <= 'Z'))
			str[i] = str[i] +32;
		i++;
	}
		return (str);	
 }
