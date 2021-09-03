/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_print_diuxX.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderome <mderome@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 20:07:03 by mderome           #+#    #+#             */
/*   Updated: 2021/09/01 15:33:00 by mderome          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	print_diuxX(char *format, char flag, va_list args, t_prc *flg)
{
	if (flag == 'd' || flag == 'i')
		ft_print_di(format, flag, args, flg);
	if (flag == 'u')
		ft_print_u(format, flag, args, flg);
	if (flag == 'x' || flag == 'X')
		ft_print_xX(format, flag, args, flg);
}
