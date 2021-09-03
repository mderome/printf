/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderome <mderome@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 10:21:18 by mderome           #+#    #+#             */
/*   Updated: 2021/09/03 21:21:31 by mderome          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	print_c(char *format, va_list args, t_prc *flg)
{
	char	c;

	check_flag(format, flg, 'c');
	check_width(format, flg, args);
	c = va_arg(args, int);
	if (flg->wdtmx)
	{
		if (flg->minus)
		{
			ft_putchar(c, flg);
			print_space((flg->wdtmx - 1), flg);
		}
		else
		{
			print_space((flg->wdtmx - 1), flg);
			ft_putchar(c, flg);
		}
	}
	else
		ft_putchar(c, flg);
	reset_struct(flg);
}
