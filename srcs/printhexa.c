/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printhexa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 14:35:35 by oespion           #+#    #+#             */
/*   Updated: 2018/05/21 17:26:21 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

void	print_precision(t_list *p, char *str)
{
	int	precision_tmp;

	precision_tmp = p->precision - ft_strlen(str);
	while (precision_tmp-- > 0)
	{
		ft_putchar('0');
		p->nbout++;
	}
}

/*
**	check this function
*/

void	print_width(t_list *p, char *str)
{
	int	spaces;
	int	max;
	int	width_tmp;

	max = 0;
	width_tmp = p->width;
	spaces = ' ';
	p->zeros && p->precision == -1 && !p->negative ? spaces = '0' : 0;
	if ((p->neg || p->positive) && !p->negative)
		width_tmp--;
	if (ft_strlen(str) > p->precision)
		max += ft_strlen(str);
	else
		max += p->precision;
	p->sharp && p->hexa ? max += 2 : 0;
	p->sharp && !p->hexa ? max++ : 0;
	(p->width != -1 && str[0] == '\0' && p->precision != '0') ? max++ : 0;
	while (max < width_tmp--)
	{
		p->nbout++;
		ft_putchar(spaces);
	}
	if (p->width != -1 && str[0] == '\0' && p->precision != 0)
	{
		ft_putchar('0');
		p->nbout++;
	}
}

void	ft_putstrn_hexa(t_list *p, char *str, int maj)
{
	p->nbout += ft_strlen(str);
	if (p->sharp && p->zeros && str[0] != '\0')
	{
		maj ? ft_putstr("0X") : ft_putstr("0x");
		print_precision(p, str);
		p->nbout += 2;
	}
	!p->negative ? print_width(p, str) : 0;
	if (p->sharp && !p->zeros && str[0] != '\0')
	{
		maj ? ft_putstr("0X") : ft_putstr("0x");
		print_precision(p, str);
		p->nbout += 2;
	}
	!p->sharp ? print_precision(p, str) : 0;
	ft_putstr(str);
	p->negative ? print_width(p, str) : 0;
}

void	ft_putstrn_octal(t_list *p, char *str)
{
	p->nbout += ft_strlen(str);
	if (p->sharp && p->zeros)
	{
		ft_putchar('0');
		print_precision(p, str);
		p->nbout++;
	}
	!p->negative ? print_width(p, str) : 0;
	if (p->sharp && !p->zeros)
	{
		ft_putchar('0');
		print_precision(p, str);
		p->nbout++;
	}
	!p->sharp ? print_precision(p, str) : 0;
	ft_putstr(str);
	p->negative ? print_width(p, str) : 0;
}

void	printhexa(t_list *p, int maj)
{
	intmax_t	nb;
	char		*total;

	p->hexa = 1;
	nb = getunb(p, 0);
	total = ft_convert_base(nb, 16);
	if (maj)
		total = ft_toupper(total);
	if (p->precision == -1 && p->width == -1)
	{
		p->nbout = ft_strlen(total);
		if (p->sharp && total[0] != '\0')
		{
			maj ? ft_putstr("0X") : ft_putstr("0x");
			p->nbout += 2;
		}
		total[0] == '\0' && p->precision != 0 ? ft_putchar('0') : 0;
		total[0] == '\0' && p->precision != 0 ? p->nbout++ : 0;
		ft_putstr(total);
	}
	else
		ft_putstrn_hexa(p, total, maj);
}

void	printoctal(t_list *p, int maj)
{
	intmax_t	nb;
	char		*total;

	p->hexa = 0;
	nb = getunb(p, 0);
	total = ft_convert_base(nb, 8);
	if (maj)
		total = ft_toupper(total);
	if (p->precision == -1 && p->width == -1)
	{
		p->nbout += ft_strlen(total);
		if (p->sharp && total[0] != '\0')
		{
			ft_putchar('0');
			p->nbout++;
		}
		total[0] == '\0' && p->precision != 0 ? p->nbout++ : 0;
		total[0] == '\0' && p->precision != 0 ? ft_putchar('0') : 0;
		ft_putstr(total);
	}
	else
		ft_putstrn_octal(p, total);
}
