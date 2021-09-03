/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderome <mderome@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 19:38:51 by mderome           #+#    #+#             */
/*   Updated: 2021/09/01 15:38:10 by mderome          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	ft_len(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_rev_str(char *str)
{
	int		i;
	int		len;
	char	tmp;

	i = 0;
	len = ft_len(str);
	while (i < len - 1)
	{
		tmp = str[i];
		str[i] = str[len - 1];
		str[len - 1] = tmp;
		i++;
		len--;
	}
	return (str);
}

void	ft_print_point(char *str, t_prc *flg)
{
	int	i;

	i = 0;
	if (flg->wdtmn < ft_len(str))
		while (i++ < flg->wdtmn)
			ft_putchar(str[i], flg);
	else
		while (i++ < (flg->wdtmn - ft_len(str)))
			ft_putchar(' ', flg);
}
