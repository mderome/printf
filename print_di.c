/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderome <mderome@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 20:07:32 by mderome           #+#    #+#             */
/*   Updated: 2021/09/03 21:21:42 by mderome          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	print_space_di(int lentgh, t_prc *flg)
{
	int	i;

	i = 0;
	if (flg->plus)
		lentgh--;
	while (i++ < lentgh)
	{
		if (flg->zero)
			ft_putchar('0', flg);
		else
			ft_putchar(' ', flg);
	}
}

void	display_di(long long int nb, t_prc *flg)
{
	char	*str;
	int		length;

	str = ft_itoa(nb, "0123456789");
	if (flg->wdtmx == 0 || nb == 0)
		length = 0;
	else
		length = flg->wdtmn - ft_len(str);
	if (flg->plus && nb >= 0)
		ft_putstr("+", flg);
	while (length--)
		ft_putstr("0", flg);
	if (flg->space && !flg->plus && nb >= 0)
		ft_putchar(' ', flg);
	if (nb == 0)
		ft_putchar('0', flg);
	else
		ft_putstr(str, flg);
	reset_struct(flg);
}

void	display_di_min(long long int nb, t_prc *flg)
{
	char	*str;
	int		length;

	str = ft_itoa(nb, "0123456789");
	length = 0;
	if (flg->wdtmx)
		length = flg->wdtmn - ft_len(str);
	if (flg->plus && nb >= 0)
		ft_putstr("+", flg);
	while (length--)
		ft_putstr("0", flg);
	if (flg->space && !flg->plus && nb >= 0)
		ft_putchar(' ', flg);
	if (nb == 0)
	{
		ft_putchar('0', flg);
		print_space_di(flg->wdtmx - 1, flg);
	}
	else
	{
		ft_putstr(str, flg);
		print_space_di(flg->wdtmx - ft_len(str), flg);
	}
	flg->wdtmn = 0;
	flg->wdtmx = 0;
}

void	ft_print_di(char *format, char flag, va_list args, t_prc *flg)
{
	int	nb;
	int	lengthmx;

	check_flag(format, flg, flag);
	check_width(format, flg, args);
	nb = va_arg(args, long long int);
	lengthmx = flg->wdtmx;
	if (flg->wdtmn < ft_len(ft_itoa(nb, "0123456789")) && !flg->point)
		flg->wdtmn = ft_len(ft_itoa(nb, "0123456789"));
	if ((flg->point || flg->wdtmn || flg->wdtmx) && !flg->minus)
	{
		print_space_di((lengthmx - flg->wdtmn), flg);
		display_di(nb, flg);
	}
	else if (flg->minus)
		display_di_min(nb, flg);
	else
	{
		if (nb == INT_MIN)
			ft_putstr("-2147483648", flg);
		else
			display_di(nb, flg);
	}
}
