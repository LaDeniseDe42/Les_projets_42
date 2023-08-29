/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 10:15:40 by qdenizar          #+#    #+#             */
/*   Updated: 2022/07/21 10:21:31 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strlowcase(char *str);

int main()
{
	char test[] ="SalutzzZZA Je suiS Un Peu cheeeeloooouuu muhahah$#@!!!!";

	ft_strlowcase(test);
	printf("%s", ft_strlowcase(test));

}

char	*ft_strlowcase(char *str)
{
	int i;
	
	i = 0;
	while(str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		i++;
	}
		return (str);
			
			
}
