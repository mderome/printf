/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_final.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderome <mderome@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 19:58:17 by mderome           #+#    #+#             */
/*   Updated: 2021/08/31 12:55:57 by mderome          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	ft_putchar(char c, t_prc *flg)
{
	write(1, &c, 1);
	flg->ret++;
}

void	ft_putstr(char *str, t_prc *flg)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
		flg->ret++;
	}
}

char	*print_hexa(unsigned long long int nb, char *base)
{
	static char	str[100];
	int			i;

	i = 0;
	while (nb)
	{
		str[i] = base[nb % 16];
		nb = nb / 16;
		i++;
	}
	str[i] = '\0';
	ft_rev_str(str);
	return (str);
}
