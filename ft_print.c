/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 11:15:01 by nsauret           #+#    #+#             */
/*   Updated: 2024/04/03 19:05:43 by nsauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str);
void	ft_putnbr(int nb);
void	ft_putfloat(float f);
void	ft_puttab(int *tab, int size);
int		ft_atoi(char *str);
void	ft_putstr2d(char **str, int size);
void	ft_putint2d(int rows, int cols, int **tab);

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
		ft_putint2d(ft_atoi(str), ft_atoi(str), (int **)val);
	}
	else
		return (1);
	return (0);
}

int	get_type(char *str)
{
	if (str[1] == 'd' && str[2] == 'd' && str[3] != ' ')
		return (6);
	if (str[1] == 's' && str[2] != ' ')
		return (5);
	if (str[1] == 'd' && str[2] != ' ')
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

int	main(void)
{
	int		nb = 42;
	float	f = 3.14159;
	char	c = 'q';
	char	*str = "Hello World!";
	int		tab[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
	char	*str2d[10] = {"un", "deux", "trois", "quatre", "cinq", "six", "sept", "huit", "neuf", "dix"};
	int		int2d[10][10];

	int n = 0;
	for (int i=0; i<10; i++)
		for (int j=0; j<10; j++)
			int2d[i][j] = n++;

	ft_print("int: %d \n", &nb);
	ft_print("float: %f \n", &f);
	ft_print("char: %c \n", &c);
	ft_print("str: %s \n", str);
	ft_print("str2d: %s10 \n", str2d);
	ft_print("tab: %d20 \n", tab);
	ft_print("int2d: %dd10 \n", int2d);
	return (0);
}
