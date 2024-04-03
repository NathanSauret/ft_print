/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 11:21:44 by nsauret           #+#    #+#             */
/*   Updated: 2024/04/03 18:00:47 by nsauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str != '\0')
		write(1, str++, 1);
}

void	ft_putnbr(int nb)
{
	char	to_write;

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

void	ft_putfloat2(int int_len, char buffer[20], int length, float f, int i)
{
	char	temp;
	float	fractional_part;
	int		decimal_places;
	int		digit;

	while (i < int_len / 2)
	{
		temp = buffer[length + i];
		buffer[length + i] = buffer[length + int_len - i - 1];
		buffer[length + int_len - i++ - 1] = temp;
	}
	length += int_len;
	buffer[length++] = '.';
	fractional_part = f - (int)f;
	decimal_places = 6;
	i = 0;
	while (i++ < decimal_places)
	{
		fractional_part *= 10;
		digit = (int)fractional_part;
		buffer[length++] = '0' + digit;
		fractional_part -= digit;
	}
	buffer[length] = '\0';
	write(1, buffer, length);
}

void	ft_putfloat(float f)
{
	char	buffer[20];
	int		length;
	int		integer_part;
	int		integer_length;
	int		i;

	length = 0;
	if (f < 0)
	{
		write(1, "-", 1);
		f = -f;
		length++;
	}
	integer_part = (int)f;
	integer_length = 0;
	while (integer_part > 0)
	{
		buffer[length + integer_length] = '0' + (integer_part % 10);
		integer_part /= 10;
		integer_length++;
	}
	i = 0;
	ft_putfloat2(integer_length, buffer, length, f, i);
}
