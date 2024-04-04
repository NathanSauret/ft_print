/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 11:15:01 by nsauret           #+#    #+#             */
/*   Updated: 2024/04/04 11:47:03 by nsauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_print.h"

//0 = int
//1 = char
//2 = char * (str)
//3 = float
//4 = int * (tab)
//5 = 2d char * tab
//6 = 2d int * tab
int	display_type(int type, void *val, char *str)
{
	if (type == 0)
		ft_putnbr(*(int *)val);
	if (type == 1)
		write(1, val, 1);
	else if (type == 2)
		ft_putstr(val);
	else if (type == 3)
		ft_putfloat(*(float *)val);
	else if (type == 4)
		ft_puttab((int *)val, ft_atoi(str));
	else if (type == 5)
		ft_putstr2d((char **)val, ft_atoi(str));
	else if (type == 6)
	{
		if (get_col_size(str) != 0)
			ft_putint2d(ft_atoi(str), get_col_size(str), (int **)val);
	}
	else
		return (1);
	return (0);
}

int	get_type(char *str)
{
	if (str[1] == 'd' && is_numeric(str[2]) && get_col_size(str) != 0)
		return (6);
	if (str[1] == 's' && is_numeric(str[2]))
		return (5);
	if (str[1] == 'd' && is_numeric(str[2]))
		return (4);
	if (str[1] == 'f')
		return (3);
	if (str[1] == 's')
		return (2);
	if (str[1] == 'c')
		return (1);
	if (str[1] == 'd')
		return (0);
	return (-1);
}

int	ft_print(char *str, void *val)
{
	int	i_val;
	int	type;

	i_val = 1;
	while (*str != '\0')
	{
		if (*str == '%')
		{
			type = get_type(str);
			if (type != -1)
				display_type(type, val, str);
			else
				return (1);
			while (*(str + 1) != ' ')
				str++;
			i_val++;
		}
		else
			write(1, &*str, 1);
		str++;
	}
	return (0);
}
