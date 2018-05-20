/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 17:33:37 by oespion           #+#    #+#             */
/*   Updated: 2018/05/19 16:14:20 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

void	call_va(t_list *p)
{
	intmax_t		max;
	long long int	longlong;
	int				basenb;

	if (p->j)
	{
		max = va_arg(p->ap, intmax_t);
		if (p->blank == 1 && p->positive == 0 && max > 0)
		{
			ft_putchar(' ');
			p->width--;
			p->nbout++;
		}
		p->positive && p->width != -1 ? p->width-- : 0;
		if (!p->precision && max == 0)
		{
			ft_get_width(p, 0);
			return ;
		}
		if (p->precision != -1 || p->width != -1)
			ft_putnbrn(p, max);
		else
		{
			if (p->positive)
			{
				p->nbout++;
				ft_putchar('+');
			}
			max == 0 ? p->nbout++ : 0;
			p->nbout += ft_int_len(max);
			ft_putnbr_longlong(max);
		}
	}

	else if (p->l || p->ll || p->z)
	{
		longlong = va_arg(p->ap, long long);
		p->nbout += longlong_len(longlong);
		if (!p->precision && longlong == 0)
		{
			ft_get_width(p, 0);
			return ;
		}
		if (p->blank == 1 && p->positive == 0 && longlong > 0)
		{
			ft_putchar(' ');
			p->width--;
			p->nbout++;
		}
		if (p->positive && longlong >= 0)
		{
			p->nbout++;
			ft_putchar('+');
		}
		longlong < -0 ? p->nbout++ : 0;
		p->z ? p->nbout -= 2 : 0;
	//	longlong == 0 ? p->nbout = -1 : 0;
		ft_putnbrn(p, longlong);
	}
	else if (p->h)
	{
		longlong = va_arg(p->ap, long long);
		while (longlong < -32768)
			longlong += 65536;
		while (longlong > 32767)
			longlong -= 65536;
		if (!p->precision && longlong == 0)
		{
			ft_get_width(p, 0);
			return ;
		}
		if (longlong == 0)
			p->nbout--;
		ft_putnbrn(p, longlong);
	}
	else if (p->hh)
	{
		longlong = va_arg(p->ap, long long);
		while (longlong < -128)
			longlong += 256;
		while (longlong > 127)
			longlong -= 256;
		//p->nbout += longlong_len(longlong);
		if (!p->precision && longlong == 0)
		{
			ft_get_width(p, 0);
			return ;
		}
		ft_putnbrn(p, longlong);
	}
	else
	{
		basenb = va_arg(p->ap, int);
		p->nbout += longlong_len(basenb);
		if (!p->precision && basenb == 0)
		{
			ft_get_width(p, 0);
			return ;
		}
		ft_putnbrn(p, basenb);
	}
}
