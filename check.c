/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderome <mderome@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 19:58:34 by mderome           #+#    #+#             */
/*   Updated: 2021/09/01 15:29:12 by mderome          ###   ########.fr       */
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

void	check_width_atoi(char *format, t_prc *flg, va_list args)
{
	while (*format++ != '.')
		if (ft_atoi_f(format))
			flg->wdtmx = ft_atoi_f(format);
	if (*format == '.')
	{
		if (flg->star)
			flg->wdtmn = va_arg(args, int);
		else
			flg->wdtmn = ft_atoi_f(format + 1);
	}
}

void	check_width(char *format, t_prc *flg, va_list args)
{
	if (flg->star == 2)
	{
		flg->wdtmx = va_arg(args, int);
		flg->wdtmn = va_arg(args, int);
	}
	else
	{	
		while (*format && (*format < '0' || *format > '9')
			&&*format != '*' && *format != '.')
			format++;
		if (*format)
		{
			if (*format == '*')
			{
				flg->wdtmx = va_arg(args, int);
				while (*format && *format != '.')
					format++;
				if (ft_atoi_f(format))
					flg->wdtmn = ft_atoi_f(format);
			}
			else
				check_width_atoi(format, flg, args);
		}
	}
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
