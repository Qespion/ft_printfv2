/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printunicode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 12:37:33 by oespion           #+#    #+#             */
/*   Updated: 2018/05/31 19:14:25 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

void	print_first(char *binary, int nlen)
{
	int		r;
	char	tab[] = "00000000";
	int		index;

	index = (ft_strlen(binary) - (nlen - 1) * 6) - 1;
	r = 0;
	while (r < nlen)
		tab[r++] = '1';
	r = 7;
	while (index >= 0)
	{
		if (binary[index] == '1')
			tab[r] = '1';
		index--;
		r--;
	}
	r = bin_to_dec(tab);
	write(1, &r, 1);
}

void	print_uni_width(t_list *p, int nlen)
{
	int		width_tmp;
	int		r;
	char	spaces;

	spaces = ' ';
	r = 0;
	p->zeros ? spaces = '0' : 0;
	width_tmp = p->width - nlen;
	while (r < width_tmp)
	{
		p->nbout++;
		ft_putchar(spaces);
		r++;
	}
}

void	print_rest(char *binary, int index)
{
	int	r;

	char	tab[] = "10000000";
	r = 2;
	while (r < 8)
	{
		tab[r++] = binary[index++];
	}
	r = bin_to_dec(tab);
//	printf("str == %s\n", tab);
//	printf("start nb  = %d\n", r);
	write(1, &r, 1);
}

void	break_bin(char *binary, t_list *p)
{
	int	r;
	int	nlen;
	int	index;
	int	tmp;

	r = ft_strlen(binary) - 1;
	nlen = r / 6;
	if (r > 0)
		nlen += (r % 6 < 5) ? 1 : 2;
	index = (ft_strlen(binary) - (nlen - 1) * 6);
	!p->negative ? print_uni_width(p, nlen) : 0;
	tmp = nlen;
	print_first(binary, nlen);
	p->nbout += nlen;
	while (nlen - 1 > 0)
	{
		print_rest(binary, index);
		nlen--;
		index += 6;
	}
	p->negative ? print_uni_width(p, tmp) : 0;
}

int		printunicode(t_list *p)
{
	int		brett;
	char	*binary;

	!p->brett ? brett = va_arg(p->ap, int) : 0;
	p->brett ? brett = p->brett : 0;
	if ((MB_CUR_MAX == 1 && brett > 255) || (brett <= 917759 && brett >= 917632)
			|| (brett <= 196608 && brett >= 917503)|| (brett >= 918000 && brett <= 983039)
			|| (brett >= 55296 && brett <= 57343)|| (brett >= 196608 && brett <= 917503)
			|| brett >= 1114112)
	{
		p->brett = -1;
		return (0);
	}
	if (brett < 256)
	{
		write(1, &brett, 1);
		p->nbout++;
		return (1);
	}
	binary = ft_convert_base(brett, 2);
	break_bin(binary, p);
	return (1);
}

int		checkunicode(t_list *p)
{
	int		brett;

	brett = va_arg(p->ap, int);
//	printf("brett is equal to = %d\n", brett);
	if ((MB_CUR_MAX == 1 && brett > 255) || (brett <= 917759 && brett >= 917632)
			|| (brett <= 196608 && brett >= 917503)|| (brett >= 918000 && brett <= 983039)
			|| (brett >= 55296 && brett <= 57343)|| (brett >= 196608 && brett <= 917503)
			|| brett >= 1114112)
	{
		p->brett = -1;
		return (1);
	}
	p->brett = brett;
	return (0);
}
