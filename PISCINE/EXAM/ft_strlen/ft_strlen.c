/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 14:17:11 by qdenizar          #+#    #+#             */
/*   Updated: 2022/08/03 14:31:16 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_strlen(char	*a)
{
	int jesus_est_parmi_nous_mais_il_ne_fait_pas_le_poids_face_a_int_i;

	jesus_est_parmi_nous_mais_il_ne_fait_pas_le_poids_face_a_int_i = 0;
	while (a[jesus_est_parmi_nous_mais_il_ne_fait_pas_le_poids_face_a_int_i])
		jesus_est_parmi_nous_mais_il_ne_fait_pas_le_poids_face_a_int_i++;
	return (jesus_est_parmi_nous_mais_il_ne_fait_pas_le_poids_face_a_int_i);
}



int main(void)
{
	char a[100] = "jshgfe fwb fuwefuwe fwebf ewbf uwebfu weu few";
	printf("%d", ft_strlen(a));
	return (0);
}

