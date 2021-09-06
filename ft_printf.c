/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderome <mderome@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 09:27:47 by mderome           #+#    #+#             */
/*   Updated: 2021/09/04 10:26:34 by mderome          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	next_flag(char *format)
{
	int		i;
	char	flag;

	i = 1;
	flag = find_flag(format);
	if (flag == '%')
		return (2);
	if (flag == 0)
		return (2);
	while (format[i] && format[i] != flag)
		i++;
	return (i + 1);
}

char	find_flag(char *format)
{
	int	i;

	i = 1;
	if (!format[i])
		return (0);
	while (format[i] && ft_cmp("cspdiuxX%", format[i]) == 0)
		i++;
	if (!format[i])
		return (0);
	return (format[i]);
}

void	reset_struct(t_prc *flg)
{
	flg->star = 0;
	flg->hstg = 0;
	flg->zero = 0;
	flg->minus = 0;
	flg->plus = 0;
	flg->wdtmn = 0;
	flg->wdtmx = 0;
	flg->point = 0;
	flg->space = 0;
}

void	init_struct(t_prc *flg)
{
	flg->ret = 0;
	flg->star = 0;
	flg->hstg = 0;
	flg->zero = 0;
	flg->minus = 0;
	flg->plus = 0;
	flg->wdtmn = 0;
	flg->wdtmx = 0;
	flg->point = 0;
	flg->space = 0;
}

void	parsing_flag(char *format, va_list args, t_prc *flg)
{
	char	flag;

	flag = find_flag(format);
	if (ft_cmp("diuxX", flag) == 1)
		print_diuxX(format, flag, args, flg);
	if (ft_cmp("c", flag) == 1)
		print_c(format, args, flg);
	if (ft_cmp("s", flag) == 1)
		print_s(format, args, flg);
	if (ft_cmp("p", flag) == 1)
		ft_print_p(format, flag, args, flg);
	else if (ft_cmp("%", flag) == 1)
		ft_putchar('%', flg);
}

int	ft_printf(const char *format, ...)
{
	t_prc	flg;
	va_list	args;

	va_start(args, format);
	init_struct(&flg);
	while (*format)
	{
		if (*format == '%')
		{
			parsing_flag((char *)format, args, &flg);
			format = format + next_flag((char *)format);
		}
		else
		{
			ft_putchar(*format, &flg);
			format++;
		}
	}
	va_end(args);
	return ((int)flg.ret);
}
