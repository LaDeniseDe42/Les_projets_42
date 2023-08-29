/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 19:05:24 by qdenizar          #+#    #+#             */
/*   Updated: 2022/07/20 19:14:06 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_numeric(char *str);

int main()
{
	char test[] ="-45444";

	ft_str_is_numeric(test);
	printf("%d", ft_str_is_numeric(test));

}


int	ft_str_is_numeric(char *str)
{
	int i;
	int answer;

	i = 0;
	answer = 1;
	while(str[i] && answer > 0)
	{
				if (str[i] < '0' || str[i] > '9')
			answer = 0;
		i++;
	}
		return (answer);
			
			
}
