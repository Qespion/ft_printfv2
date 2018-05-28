/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 11:37:15 by oespion           #+#    #+#             */
/*   Updated: 2018/05/28 15:06:06 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	prints(t_list *p)
{
	char*	str;

	str = va_arg(p->ap, char*);
	if (!str)
		str = "(null)";
	if (p->precision != -1 || p->width != -1)
		ft_putstrn(p, str);
	else
	{
		p->nbout += ft_strlen(str);
		ft_putstr(str);
	}
}

void	ft_get_arg(char letter, t_list *p)
{
	if (letter == 's' || letter == 'd' || letter == 'c' || letter == 'x'
			|| letter == 'b' || letter == 'i' || letter == 'X' || letter == 'u'
			|| letter == 'o' || letter == 'O' || letter == 'U' || letter == 'D'
			|| letter == '%' || letter == 'p' || letter == 'c')
		p->increment = 1;
	if (letter == 's')
		prints(p);
	else if (letter == 'd' || letter == 'i')
		printnb(p, 0);
	else if (letter == 'c' || letter == '%')
		printchar(p, letter);
	else if (letter == 'D')
		printnb(p, 1);
	else if (letter == 'x')
		printhexa(p, 0);
	else if (letter == 'X')
		printhexa(p, 1);
	else if (letter == 'u')
		printunb(p, 0);
	else if (letter == 'U')
		printunb(p, 1);
	else if (letter == 'o')
		printoctal(p, 0);
	else if (letter == 'O')
		printoctal(p, 1);
	else if (letter == 'p')
		printaddress(p);/*
	else if (letter == 'c')
		printunicode(p);
	else if (letter == 'b')
		printbinary(p);
	*/
}
