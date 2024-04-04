/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 10:16:32 by nsauret           #+#    #+#             */
/*   Updated: 2024/04/04 16:59:07 by nsauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print/ft_print.h"

int	main(void)
{
	int		nb = 42;
	float	f = 3.14159;
	char	c = 'q';
	char	*str = "Hello World!";
	int		tab[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
					 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
	char	*str2d[10] = {"un", "deux", "trois", "quatre",
						  "cinq", "six", "sept", "huit", "neuf", "dix"};
	int		int2d[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

	ft_print("int: %d \n", &nb);
	ft_print("float: %f \n", &f);
	ft_print("char: %c \n", &c);
	ft_print("str: %s \n", str);
	ft_print("str2d: %s10 \n", str2d);
	ft_print("tab: %d20 \n", tab);
	ft_print("int2d: %d3|3 \n", int2d);
	return (0);
}
