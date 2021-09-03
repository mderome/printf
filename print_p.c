/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderome <mderome@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 13:13:35 by mderome           #+#    #+#             */
/*   Updated: 2021/09/03 21:21:55 by mderome          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	display_p(long long int nb, t_prc *flg)
{
	char	*str;

	str = print_hexa(nb, "0123456789abcdef");
	if (nb == 0)
		ft_putstr("0x0", flg);
	else
	{
		ft_putstr("0x", flg);
		ft_putstr(str, flg);
	}
	reset_struct(flg);
}

void	ft_print_p(char *format, char flag, va_list args, t_prc *flg)
{
	long long int	addr;
	char			*addr2;
	int				lentgh;
	int				lentgh2;

	check_flag(format, flg, flag);
	check_width(format, flg, args);
	addr = (long long int)va_arg(args, void *);
	addr2 = print_hexa(addr, "0123456789abcdef");
	lentgh = flg->wdtmx;
	lentgh2 = flg->wdtmn;
	if (flg->wdtmn < ft_len(addr2))
		lentgh2 = ft_len(addr2);
	if ((flg->point || flg->wdtmn || flg->wdtmx) && !flg->minus)
	{
		print_space((lentgh - (lentgh2 + 2)), flg);
		display_p(addr, flg);
	}
	else if (flg->minus)
	{
		display_p(addr, flg);
		print_space((lentgh - (lentgh2 + 2)), flg);
	}
	else
		display_p(addr, flg);
}
