/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printnb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 12:48:45 by oespion           #+#    #+#             */
/*   Updated: 2018/05/20 16:34:36 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

intmax_t	getnb(t_list *p, int maj)
{
	intmax_t	nb;

	if (p->l || maj)
		nb = va_arg(p->ap, long);
	else if (p->ll)
		nb = va_arg(p->ap, long long);
	else if (p->z)
		nb = va_arg(p->ap, size_t);
	else if (p->j)
		nb = va_arg(p->ap, intmax_t);
	else if (p->h)
		nb = (short)va_arg(p->ap, int);
	else if (p->hh)
		nb = (char)va_arg(p->ap, int);
	else
		nb = va_arg(p->ap, int);
	return (nb);
}

uintmax_t	getunb(t_list *p, int maj)
{
	uintmax_t	nb;

	if (p->l || maj)
		nb = va_arg(p->ap, unsigned long);
	else if (p->ll)
		nb = va_arg(p->ap, unsigned long long);
	else if (p->z)
		nb = va_arg(p->ap, size_t);
	else if (p->j)
		nb = va_arg(p->ap, uintmax_t);
	else if (p->h)
		nb = (unsigned short)va_arg(p->ap, unsigned int);
	else if (p->hh)
		nb = (unsigned char)va_arg(p->ap, unsigned int);
	else
		nb = va_arg(p->ap, unsigned int);
	return (nb);
}

void	ft_pos(t_list *p)
{
	if (p->positive == 1 && !p->neg)
	{
		p->nbout++;
		ft_putchar('+');
	}
	if (p->neg == 1)
	{
		p->nbout++;
		ft_putchar('-');
	}
	p->neg = 2;
	p->positive = 2;
}

void	ft_get_precision(uintmax_t nbr, t_list *p)
{
	int	precision_tmp;

	precision_tmp = p->precision;
	if (p->neg || p->positive != -1)
		p->precision--;
	ft_pos(p);
	while (uintmax_t_len(nbr) < precision_tmp)
	{
		ft_putchar('0');
		p->nbout++;
		precision_tmp--;
	}
}

void	ft_get_width(t_list *p, uintmax_t nbr)
{
	int	spaces;
	int	max;
	int	width_tmp;

	max = 0;
	width_tmp = p->width;
	spaces = ' ';
	if ((p->neg || p->positive) && !p->negative)
		width_tmp--;
	if (spaces == '0' && p->neg && !p->negative)
		ft_pos(p);
	spaces == '0' && !p->negative && p->positive ? ft_pos(p): 0;
	if (uintmax_t_len(nbr) > p->precision)
		max += uintmax_t_len(nbr);
	else
		max += p->precision;
	while (max < width_tmp--)
	{
		p->nbout++;
		ft_putchar(spaces);
	}
}

void	printnbu(t_list *p, intmax_t nb)
{
	uintmax_t	pos;

	nb < 0 ? p->neg = 1 : 0;
	pos = ft_abs(nb);
	if (p->negative)
	{
		ft_get_precision(pos, p);
		if (pos != 0 || p->precision != 0)
		{
			p->nbout += uintmax_t_len(pos);
			ft_putnbr_uintmax(pos);
		}
		ft_get_width(p, pos);
	}
	else
	{
		ft_get_width(p, pos);
		ft_get_precision(pos, p);
		if (pos != 0 && p->precision != 0)
		{
			p->nbout += uintmax_t_len(pos);
			ft_putnbr_uintmax(pos);
		}
	}
}

void	printnb(t_list *p, int maj)
{
	intmax_t	nb;

	nb = getnb(p, maj);
	if (p->precision == -1 && p->width == -1)
	{
		if (p->positive)
		{
			p->nbout++;
			ft_putchar('+');
		}
		p->nbout = longlong_len(nb);
		ft_putnbr(nb);
	}
	else
		printnbu(p, nb);
}

void	printunb(t_list *p, int maj)
{
	uintmax_t	nb;

	nb = getunb(p, maj);
	if (p->precision == -1 && p->width == -1)
	{
		if (p->positive)
		{
			p->nbout++;
			ft_putchar('+');
		}
		p->nbout = uintmax_t_len(nb);
		ft_putnbr(nb);
	}
	else
	{
		printnbu(p, nb);
	}
}
