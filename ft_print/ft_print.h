/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsauret <nsauret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 10:13:51 by nsauret           #+#    #+#             */
/*   Updated: 2024/04/04 11:46:58 by nsauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_H
# define FT_PRINT_H

# include <unistd.h>

void	ft_putstr(char *str);
void	ft_putnbr(int nb);
void	ft_putfloat(float f);
void	ft_puttab(int *tab, int size);
int		ft_atoi(char *str);
void	ft_putstr2d(char **str, int size);
int		is_numeric(char c);
int		get_col_size(char *str);
int		display_type(int type, void *val, char *str);
void	ft_putint2d(int rows, int cols, int tab[][cols]);
int		get_type(char *str);
int		ft_print(char *str, void *val);

#endif
