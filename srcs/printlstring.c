/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printlstring.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 15:33:10 by oespion           #+#    #+#             */
/*   Updated: 2018/06/02 11:38:12 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		single_len(t_list *p, int nb)
{
	int	len;

	len = 0;
	if (p->precision == -1)
		return (1);
	nb < 128 ? len = 1 : 0;
	nb >= 128 && nb < 2048 ? len = 2 : 0;
	nb >= 2048 && nb < 65536 ? len = 3 : 0;
	nb >= 65536 ? len = 4 : 0;
	MB_CUR_MAX == 1 ? len = 1 : 0;
	return (len);
}

int		check_brett_tab(wchar_t *brett, t_list *p)
{
	int	r;
	int	len;

	len = 0;
	r = 0;
	while (brett[r])
	{
		len += single_len(p, brett[r]);
		if (len > p->precision && p->precision != -1)
			break ;
	//	ft_printf("hexa of brett_tab[r] == %d", brett[r]);
		if ((MB_CUR_MAX == 1 && brett[r] > 255) || (brett[r] <= 917759 && brett[r] >= 917632)
				|| (brett[r] >= 918000 && brett[r] <= 983039)
				|| (brett[r] >= 55296 && brett[r] <= 57343)
				|| brett[r] >= 1114112 || brett[r] < 0)
			return (0);
		r++;
	}
	return (1);
}

int		calc_len(t_list *p, int nb, int output)
{
	int	len;

	if (p->precision == -1)
		return (1);
	nb < 128 ? len = 1 : 0;
	nb >= 128 && nb < 2048 ? len = 2 : 0;
	nb >= 2048 && nb < 65536 ? len = 3 : 0;
	nb >= 65536 ? len = 4 : 0;
	MB_CUR_MAX == 1 ? len = 1 : 0;
	if (len + output <= p->precision)
		return (1);
	return (0);
}

int		calc_global_len(t_list *p, wchar_t *brett_tab)
{
	int	r;
	int	total;

	total = 0;
	r = 0;
	while (brett_tab[r] && p->precision == -1)
	{
		brett_tab[r] < 128 ? total += 1 : 0;
		brett_tab[r] >= 128 && brett_tab[r] < 2048 ? total += 2 : 0;
		brett_tab[r] >= 2048 && brett_tab[r] < 65536 ? total += 3 : 0;
		brett_tab[r] >= 65536 ? total += 4 : 0;
		r++;
	}
	while (brett_tab[r] && p->precision != -1)
	{
		brett_tab[r] < 128 && total + 1 <= p->precision ? total += 1 : 0;
		brett_tab[r] >= 128 && brett_tab[r] < 2048 && total + 2 <= p->precision ? total += 2 : 0;
		brett_tab[r] >= 2048 && brett_tab[r] < 65536 && total + 3 <= p->precision ? total += 3 : 0;
		brett_tab[r] >= 65536 && total + 4 <= p->precision ? total += 4 : 0;
		r++;
	}
	if (MB_CUR_MAX == 1)
	{
		total = 0;
		r = 0;
		while (brett_tab[r++])
			total++;
	}
	return (total);
}

void	printlstring(t_list *p)
{
	wchar_t *brett_tab;
	int	r;
	int	nlen;
	int	output;

	output = 0;
	nlen = 0;
	brett_tab = va_arg(p->ap, wchar_t*);
	while (brett_tab[nlen])
		nlen++;
	r = 0;
	if (check_brett_tab(brett_tab, p) == 0)
	{
		p->brett = -1;
		return ;
	}
	!p->negative ? print_uni_width(p, calc_global_len(p, brett_tab)) : 0;
	while (brett_tab[r])
	{
		if (calc_len(p, brett_tab[r], output) == 0)
			break ;
		output += ft_printf("%C", brett_tab[r++]);
	}
	p->nbout += output;
	p->negative ? print_uni_width(p, calc_global_len(p, brett_tab)) : 0;
}
