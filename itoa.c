/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderome <mderome@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 17:30:19 by mderome           #+#    #+#             */
/*   Updated: 2021/09/01 15:41:50 by mderome          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

char	*ft_itoa(long long int nb, char *base)
{
	static char	str[100];
	int			len_base;
	int			neg;
	int			i;

	i = 0;
	neg = 0;
	len_base = ft_len(base);
	if (nb < 0)
	{
		nb *= -1;
		neg = 1;
	}
	while (nb)
	{
		str[i] = base[nb % len_base];
		nb = nb / len_base;
		i++;
	}
	if (neg)
		str[i++] = '-';
	str[i] = '\0';
	return (ft_rev_str(str));
}

char	*ft_itoa_u(unsigned long long int nb, char *base)
{
	static char	str[100];
	int			len_base;
	int			i;

	i = 0;
	len_base = ft_len(base);
	while (nb)
	{
		str[i] = base[nb % len_base];
		nb = nb / len_base;
		i++;
	}
	str[i] = '\0';
	ft_rev_str(str);
	return (str);
}
