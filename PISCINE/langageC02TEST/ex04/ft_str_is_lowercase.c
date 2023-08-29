/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 19:26:02 by qdenizar          #+#    #+#             */
/*   Updated: 2022/07/20 20:26:23 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_lowercase(char *str);

int main()
{
	char test[] ="agahdjRjfk";

	ft_str_is_lowercase(test);
	printf("%d", ft_str_is_lowercase(test));

}


int	ft_str_is_lowercase(char *str)
{
	int i;
	int answer;

	i = 0;
	answer = 1;
	while(str[i] && answer > 0)
	{
				if (str[i] < 'a' || str[i] > 'z')
			answer = 0;
		i++;
	}
		return (answer);
			
			
}
