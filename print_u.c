/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderome <mderome@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 20:07:17 by mderome           #+#    #+#             */
/*   Updated: 2021/09/03 21:22:21 by mderome          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	print_space_u(int lentgh, t_prc *flg)
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

void	display_u(unsigned long long int nb, t_prc *flg)
{
	char	*str;
	int		length;

	str = ft_itoa_u(nb, "0123456789");
	if (flg->wdtmx == 0 || nb == 0)
		length = 0;
	else
		length = flg->wdtmn - ft_len(str);
	if (flg->plus)
		ft_putstr("+", flg);
	while (length--)
		ft_putstr("0", flg);
	if (flg->space && !flg->plus)
		ft_putchar(' ', flg);
	if (nb == 0)
		ft_putchar('0', flg);
	else
		ft_putstr(str, flg);
	reset_struct(flg);
}

void	display_u_min(unsigned long long int nb, t_prc *flg)
{
	char	*str;
	int		length;

	str = ft_itoa_u(nb, "0123456789");
	length = 0;
	if (flg->wdtmx)
		length = flg->wdtmn - ft_len(str);
	if (flg->plus)
		ft_putstr("+", flg);
	while (length--)
		ft_putstr("0", flg);
	if (flg->space && !flg->plus)
		ft_putchar(' ', flg);
	if (nb == 0)
	{
		ft_putchar('0', flg);
		print_space_u(flg->wdtmx - 1, flg);
	}
	else
	{
		ft_putstr(str, flg);
		print_space_u(flg->wdtmx - ft_len(str), flg);
	}
	reset_struct(flg);
}

void	ft_print_u(char *format, char flag, va_list args, t_prc *flg)
{
	unsigned int	nb;
	int				lengthmx;

	check_flag(format, flg, flag);
	check_width(format, flg, args);
	nb = va_arg(args, unsigned long long int);
	lengthmx = flg->wdtmx;
	if (flg->wdtmn < ft_len(ft_itoa_u(nb, "0123456789")) && !flg->point)
		flg->wdtmn = ft_len(ft_itoa_u(nb, "0123456789"));
	if ((flg->point || flg->wdtmn || flg->wdtmx) && !flg->minus)
	{
		print_space_u((lengthmx - flg->wdtmn), flg);
		display_u(nb, flg);
	}
	else if (flg->minus)
		display_u_min(nb, flg);
	else
		display_u(nb, flg);
}
