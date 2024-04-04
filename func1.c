/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 11:21:44 by nsauret           #+#    #+#             */
/*   Updated: 2024/04/04 11:47:01 by nsauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_print.h"

void	ft_putstr(char *str)
{
	while (*str != '\0')
		write(1, str++, 1);
}

void	ft_putnbr(int nb)
{
	char	to_write;

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
	}
	to_write = nb % 10 + '0';
	write(1, &to_write, 1);
}

int	ft_atoi(char *str)
{
	int	return_nb;
	int	minus_nb;
	int	multiply;
	int	i;

	if (str[0] == '\0')
		return (0);
	minus_nb = 0;
	i = 0;
	while (str[i] < '0' || str[i] > '9')
		minus_nb += (str[i++] == '-');
	if (minus_nb > 0 && str[i - 1] != '-' && str[i - 1] != '+')
		return (0);
	while (str[i + 1] >= '0' && str[i + 1] <= '9')
		i++;
	return_nb = 0;
	multiply = 1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		return_nb += (str[i--] - '0') * multiply;
		multiply *= 10;
	}
	if (minus_nb % 2 == 0)
		return (return_nb);
	return (-return_nb);
}

void	ft_putfloat2(int int_len, char buffer[20], int multi[2], float f)
{
	char		temp;
	float		fractional_part;
	int			decimal_places;
	float		digit;

	while (multi[0] < int_len / 2)
	{
		temp = buffer[multi[1] + multi[0]];
		buffer[multi[1] + multi[0]] = buffer[multi[1] + int_len - multi[0] - 1];
		buffer[multi[1] + int_len - multi[0]++ - 1] = temp;
	}
	multi[1] += int_len;
	buffer[multi[1]++] = '.';
	fractional_part = f - (int)f;
	decimal_places = 6;
	multi[0] = 0;
	while (multi[0]++ < decimal_places)
	{
		fractional_part *= 10;
		digit = (int)fractional_part;
		buffer[multi[1]++] = '0' + digit;
		fractional_part -= digit;
	}
	buffer[multi[1]] = '\0';
	write(1, buffer, multi[1]);
}

void	ft_putfloat(float f)
{
	char	buffer[20];
	int		int_part;
	int		int_len;
	int		multi[2];

	multi[1] = 0;
	if (f < 0)
	{
		write(1, "-", 1);
		f = -f;
		multi[1]++;
	}
	int_part = (int)f;
	int_len = 0;
	while (int_part > 0)
	{
		buffer[multi[1] + int_len] = '0' + (int_part % 10);
		int_part /= 10;
		int_len++;
	}
	multi[0] = 0;
	ft_putfloat2(int_len, buffer, multi, f);
}
