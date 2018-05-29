/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printaddress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 18:23:55 by oespion           #+#    #+#             */
/*   Updated: 2018/05/28 15:42:34 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	address_width(t_list *p, char *total)
{
	int	r;

	r = p->width;
	p->precision != -1 ? r -= p->precision - ft_strlen(total) : 0;
	total[0] == '\0' ? r-- : 0;
	while (r > ft_strlen(total) + 2)
	{
		ft_putchar(' ');
		r--;
		p->nbout++;
	}
}

void	address_precision(t_list *p, char *total)
{
	int	r;

	r = p->precision;
	total[0] == '\0' ? r-- : 0;
	while (r > ft_strlen(total))
	{
		ft_putchar('0');
		r--;
		p->nbout++;
	}
}

void	printaddress(t_list *p)
{
	uintmax_t	adr;
	char		*total;

	adr = (uintmax_t)va_arg(p->ap, void*);
	total = ft_convert_base(adr, 16);
	if (p->negative)
	{
		ft_putstr("0x");
		address_precision(p, total);
		ft_putstr(total);
		total[0] == '\0' ? ft_putchar('0') : 0;
		address_width(p, total);
	}
	else
	{
		address_width(p, total);
		ft_putstr("0x");
		address_precision(p, total);
		ft_putstr(total);
		total[0] == '\0' ? ft_putchar('0') : 0;
	}
	total[0] == '\0' ? p->nbout++ : 0;
	p->nbout += ft_strlen(total) + 2;
	ft_strdel(&total);
}
