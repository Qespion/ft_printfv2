/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printable_adv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 12:34:52 by oespion           #+#    #+#             */
/*   Updated: 2018/05/31 17:16:50 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	printchar(t_list *p, char letter)
{
	char c;

	if (letter != '%')
		c = getnb(p, 0);
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
