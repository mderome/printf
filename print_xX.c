/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_xX.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderome <mderome@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 20:07:36 by mderome           #+#    #+#             */
/*   Updated: 2021/09/03 21:22:27 by mderome          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	display_xX(unsigned int nb, char flag, t_prc *flg)
{
	char	*str;

	if ((int)nb == 0)
		ft_putchar('0', flg);
	else
	{
		if (flag == 'x')
		{
			if (flg->hstg)
				ft_putstr("0x", flg);
			str = ft_itoa_u(nb, "0123456789abcdef");
		}
		if (flag == 'X')
		{
			if (flg->hstg)
				ft_putstr("0X", flg);
			str = ft_itoa_u(nb, "0123456789ABCDEF");
		}
		ft_putstr(str, flg);
	}
	reset_struct(flg);
}

void	ft_print_xX(char *format, char flag, va_list args, t_prc *flg)
{
	unsigned int	nb;

	check_flag(format, flg, flag);
	check_width(format, flg, args);
	nb = va_arg(args, unsigned int);
	if (flg->wdtmn < ft_len(ft_itoa_u(nb, "0123456789abcdef")))
		flg->wdtmn = ft_len(ft_itoa_u(nb, "0123456789abcdef"));
	if (flg->point || flg->wdtmn || flg->wdtmx)
	{
		print_space((flg->wdtmx - flg->wdtmn), flg);
		display_xX(nb, flag, flg);
	}
	else
		display_xX(nb, flag, flg);
}
