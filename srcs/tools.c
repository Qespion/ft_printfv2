/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 13:54:53 by oespion           #+#    #+#             */
/*   Updated: 2018/05/21 12:30:14 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

const char	*end_of_int(const char *str)
{
	str++;
	while (*str >= '0' && *str <= '9')
		str++;
	return (str);
}

int	uintmax_t_len(uintmax_t nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

int	longlong_len(intmax_t nb)
{
	int	i;

	i = 0;
	if (nb < -9223372036854775807)
		return (20);
	if (nb < 0)
	{
		i++;
		nb *= -1;
	}
	else if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

t_list	*create_struct(void)
{
	t_list	*p;

	if (!(p = (t_list*)malloc(sizeof(t_list))))
		return (0);
	p->nbout = 0;
	p->precision = -1;
	p->width = -1;
	p->increment = 0;
	p->negative = 0;
	p->zeros = 0;
	p->blank = 0;
	p->positive = 0;
	p->sharp = 0;
	p->h = 0;
	p->neg = 0;
	p->hh = 0;
	p->l = 0;
	p->ll = 0;
	p->j = 0;
	p->z = 0;
	return (p);
}

t_list	*reset_struct(t_list *p)
{
	p->precision = -1;
	p->width = -1;
	p->negative = 0;
	p->zeros = 0;
	p->blank = 0;
	p->neg = 0;
	p->increment = 0;
	p->positive = 0;
	p->sharp = 0;
	p->h = 0;
	p->hh = 0;
	p->l = 0;
	p->ll = 0;
	p->j = 0;
	p->z = 0;
	return (p);
}
//1000 0000
//0x80