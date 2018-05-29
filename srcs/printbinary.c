/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printbinary.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 15:28:40 by oespion           #+#    #+#             */
/*   Updated: 2018/05/29 15:30:56 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	printbinary(t_list *p)
{
	int		brett;
	char	*total;

	brett = va_arg(p->ap, int);
	total = ft_convert_binary(brett);
	while (*total)
	{
		ft_putchar(*total);
		total++;
		p->nbout++;
	}
}