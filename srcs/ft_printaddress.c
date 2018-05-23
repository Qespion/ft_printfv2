/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printaddress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 18:23:55 by oespion           #+#    #+#             */
/*   Updated: 2018/05/23 18:50:09 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

void	printaddress(t_list *p)
{
	uintmax_t	adr;
	char		*total;
	adr = (uintmax_t)va_arg(p->ap, void*);
	total = ft_convert_base(adr, 16);
	ft_putstr(total);
}