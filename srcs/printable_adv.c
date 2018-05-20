/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printable_adv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 12:34:52 by oespion           #+#    #+#             */
/*   Updated: 2018/05/20 10:45:04 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

void	printchar(t_list *p, char letter)
{
	char c;
	if (letter != '%')
		c = va_arg(p->ap, int);
	if ((p->precision != -1 || p->width != -1)
			&& letter == '%')
		ft_putcharnf(p);
	else if (p->precision != -1 || p->width != -1)
	{
		ft_putcharn(p, c);
	}
	else
	{
		if (letter == '%')
			ft_putchar('%');
		if (letter != '%')
		{
			p->nbout++;
			ft_putchar(c);
		}
	}
}
