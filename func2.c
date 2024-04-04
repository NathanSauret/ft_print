/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:10:59 by nsauret           #+#    #+#             */
/*   Updated: 2024/04/04 15:17:25 by nsauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_print.h"

//void	ft_putnbr(int nb);
//int		ft_atoi(char *str);

void	ft_puttab(int tab[], int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_putnbr(tab[i]);
		if (i < size - 1)
			write(1, ", ", 2);
		i++;
	}
}

void	ft_putstr2d(char **str, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (str[i][j] != '\0')
		{
			write(1, &str[i][j], 1);
			j++;
		}
		if (i < size - 1)
			write(1, ", ", 2);
		i++;
	}
}

void	ft_putint2d(int rows, int cols, int tab[rows][cols])
{
	int	i;

	i = 0;
	write(1, "\n", 1);
	while (i < rows)
	{
		ft_puttab(tab[i], cols);
		write(1, "\n", 1);
		i++;
	}
}

int	is_numeric(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	get_col_size(char *str)
{
	while (*str != '|')
	{
		if (*str == '\0' || *str == ' ')
			return (0);
		str++;
	}
	return (ft_atoi(str));
}
