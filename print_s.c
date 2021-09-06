/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderome <mderome@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 18:57:28 by mderome           #+#    #+#             */
/*   Updated: 2021/09/03 22:00:54 by mderome          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	print_space(int lentgh, t_prc *flg)
{
	int	i;

	i = 0;
	while (i++ < lentgh)
		ft_putchar(' ', flg);
}

void	print_larger_s(char *str, t_prc *flg)
{
	int		length;

	length = 0;
	if (flg->wdtmn == 0 && !flg->point)
		length = ft_len(str);
	if (ft_len(str) < flg->wdtmn)
	{
		if (flg->wdtmn < flg->wdtmx)
			print_space((flg->wdtmx - (flg->wdtmn - ft_len(str))), flg);
		else
			print_space(length, flg);
	}
}

void	display_s(char *str, t_prc *flg)
{
	int	i;
	int	length;

	length = 0;
	if (flg->wdtmn == 0 && !flg->point)
		length = ft_len(str);
	if (flg->point)
		length = flg->wdtmn;
	i = 0;
	if (!str)
	{
		ft_putstr("(null)", flg);
		return ;
	}
	print_larger_s(str, flg);
	if (flg->space && flg->wdtmx >= 1)
		ft_putchar(' ', flg);
	while (str[i] && i < length)
		ft_putchar(str[i++], flg);
	reset_struct(flg);
}

void	print_s(char *format, va_list args, t_prc *flg)
{
	char	*str;
	int		lentgh;

	check_flag(format, flg, 's');
	str = va_arg(args, char *);
	lentgh = ft_len(str);
	if (flg->point && flg->wdtmn == 0 && flg->wdtmx)
		print_space(flg->wdtmx, flg);
	else if (flg->wdtmn || flg->wdtmx)
	{
		if (flg->minus)
		{
			display_s(str, flg);
			print_space((flg->wdtmx - lentgh), flg);
		}
		else
		{
			print_space((flg->wdtmx - lentgh), flg);
			display_s(str, flg);
		}
	}
	else
		display_s(str, flg);
}
