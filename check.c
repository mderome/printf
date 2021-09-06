/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderome <mderome@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 19:58:34 by mderome           #+#    #+#             */
/*   Updated: 2021/09/03 22:00:58 by mderome          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	ft_cmp(char *check, char c)
{
	int	i;

	i = 0;
	while (check[i])
	{
		if (check[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	check_flag(char *format, t_prc *flg, char flag)
{
	int	i;

	i = 0;
	while (format[i] != flag && (format[i] <= '0' || format[i] > '9'))
	{
		if (format[i] == '*')
			flg->star += 1;
		if (format[i] == ' ')
			flg->space = 1;
		if (format[i] == '-')
			flg->minus = 1;
		if (format[i] == '+')
			flg->plus = 1;
		if (format[i] == '#')
			flg->hstg = 1;
		if (format[i] == '0')
			flg->zero = 1;
		if (format[i] == '.')
			flg->point = 1;
		i++;
	}
}
