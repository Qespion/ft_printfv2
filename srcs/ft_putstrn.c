/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 15:57:55 by oespion           #+#    #+#             */
/*   Updated: 2018/05/20 10:33:54 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

void	write_with_precision(char *str, t_list *p)
{
	int	r;

	r = 0;
	if (p->precision == -1)
		while (str[r])
		{
			p->nbout++;
			ft_putchar(str[r++]);
		}
	else
		while (str[r] && r < p->precision)
		{
			p->nbout++;
			ft_putchar(str[r++]);
		}
}

void	ft_putstrn(t_list *p, char *str)
{
	int		len_width;
	char	spaces;

	spaces = ' ';
	if (p->zeros && p->negative == 0)
		spaces = '0';
	if (!str)
		return ;
	len_width = p->precision + 1;
	if (len_width > (int)ft_strlen(str)
			|| p->precision == -1)
		len_width = ft_strlen(str) + 1;
	if (p->negative == 0)
		while (len_width++ <= p->width)
		{
			p->nbout++;
			ft_putchar(spaces);
		}
	write_with_precision(str, p);
	if (p->negative == 1)
		while (len_width++ <= p->width)
		{
			p->nbout++;
			ft_putchar(spaces);
		}
}
