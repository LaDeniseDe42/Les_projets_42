/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 22:01:34 by qdenizar          #+#    #+#             */
/*   Updated: 2022/07/21 10:10:52 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strupcase(char *str);

int main()
{
	char test[] ="Salut Je suiS Un Peu cheeeeloooouuu muhahah$#@!!!!";

	ft_strupcase(test);
	printf("%s", ft_strupcase(test));

}

char	*ft_strupcase(char *str)
{
	int i;
	
	i = 0;
	while(str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 32;
		i++;
	}
		return (str);
			
			
}
