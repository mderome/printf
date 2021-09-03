/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderome <mderome@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 19:58:27 by mderome           #+#    #+#             */
/*   Updated: 2021/09/03 21:21:07 by mderome          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_prc
{
	int	ret;
	int	star;
	int	hstg;
	int	zero;
	int	minus;
	int	plus;
	int	space;
	int	wdtmn;
	int	wdtmx;
	int	point;
}				t_prc;

int		ft_printf(const char *format, ...);
int		ft_cmp(char *check, char c);
char	find_flag(char *format);
void	ft_putchar(char c, t_prc *flg);
void	print_c(char *format, va_list args, t_prc *flg);
void	check_flag(char *format, t_prc *flg, char flag);
int		ft_atoi_f(char *str);
void	print_s(char *format, va_list args, t_prc *flg);
void	ft_putstr(char *str, t_prc *flg);
int		ft_len(char *str);
char	*ft_itoa(long long int nb, char *base);
void	ft_print_di(char *format, char flag, va_list args, t_prc *flg);
void	ft_print_xX(char *format, char flag, va_list args, t_prc *flg);
void	ft_print_u(char *format, char flag, va_list args, t_prc *flg);
void	print_diuxX(char *format, char flag, va_list args, t_prc *flg);
char	*ft_rev_str(char *str);
char	*ft_itoa_u(unsigned long long int nb, char *base);
void	check_width(char *format, t_prc *flg, va_list args);
void	print_space(int lentgh, t_prc *flg);
char	*print_hexa(unsigned long long int nb, char *base);
void	ft_print_p(char *format, char flag, va_list args, t_prc *flg);
void	ft_print_point(char *str, t_prc *flg);
void	reset_struct(t_prc *flg);

#endif
