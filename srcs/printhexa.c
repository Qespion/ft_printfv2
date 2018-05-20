/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printhexa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 14:35:35 by oespion           #+#    #+#             */
/*   Updated: 2018/05/20 16:22:58 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

void	ft_putstrn_hexa(t_list *p, char *str, int maj)
{
	int		len_width;
	char	spaces;

	spaces = ' ';
	len_width = ft_strlen(str) + 1;
	p->sharp ? len_width += 2 : 0;
	p->zeros && !p->negative ? spaces = '0' : 0;
	if (p->negative == 0)
		while (len_width++ <= p->width)
		{
			p->nbout++;
			ft_putchar(spaces);
		}
	p->nbout += ft_strlen(str);
	if (p->sharp)
	{
		maj ? ft_putstr("0X") : ft_putstr("0x");
		p->nbout += 2;
	}
	ft_putstr(str);
	if (p->negative == 1)
		while (len_width++ <= p->width)
		{
			p->nbout++;
			ft_putchar(spaces);
		}
}

void	ft_putstrn_octal(t_list *p, char *str)
{
	int		len_width;
	char	spaces;

	spaces = ' ';
	len_width = ft_strlen(str) + 1;
	p->sharp ? len_width++ : 0;
	p->zeros && !p->negative ? spaces = '0' : 0;
	if (p->negative == 0)
		while (len_width++ <= p->width)
		{
			p->nbout++;
			ft_putchar(spaces);
		}
	p->nbout += ft_strlen(str);
	if (p->sharp)
	{
		ft_putchar('0');
		p->nbout++;
	}
	ft_putstr(str);
	if (p->negative == 1)
		while (len_width++ <= p->width)
		{
			p->nbout++;
			ft_putchar(spaces);
		}
}

void	printhexa(t_list *p, int maj)
{
	intmax_t	nb;
	char		*total;

	nb = getunb(p, 0);
	total = ft_convert_base(nb, 16);
	if (maj)
		total = ft_toupper(total);
	if (p->precision == -1 && p->width == -1)
	{
		p->nbout = ft_strlen(total);
		if (p->sharp)
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

	nb = getunb(p, 0);
	total = ft_convert_base(nb, 8);
	if (maj)
		total = ft_toupper(total);
	if (p->precision == -1 && p->width == -1)
	{
		p->nbout = ft_strlen(total);
		if (p->sharp)
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
