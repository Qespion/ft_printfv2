/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printunicode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 12:37:33 by oespion           #+#    #+#             */
/*   Updated: 2018/05/29 17:58:56 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

void	print_first(char *binary, int nlen)
{
	int		r;
	char	tab[] = "00000000";
	int		index;
	char	*hexa;

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
	hexa = ft_strjoin("0x", ft_convert_base(r, 16));
	ft_printf("\nFIRST HEXA %s\n", hexa);
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
	//ft_printf("\nbin = %s\n", tab);
	r = bin_to_dec(tab);
	ft_printf("\nNEXT HEXA %#x\n", r);
//	write(1, "0x"ft_convert_base(r, 16), 1);
}

void	break_bin(char *binary)
{
	int	r;
	int	nlen;
	int	index;

	r = ft_strlen(binary) - 1;
	nlen = r / 6;
	if (r > 0)
		nlen += (r % 6 < 5) ? 1 : 2;
	index = (ft_strlen(binary) - (nlen - 1) * 6);
	print_first(binary, nlen);
	while (nlen - 1 > 0)
	{
		print_rest(binary, index);
		nlen--;
		index += 6;
	}
}

void	printunicode(t_list *p)
{
	int		brett;
	char	*binary;

	brett = va_arg(p->ap, int);
	binary = ft_convert_base(brett, 2);
//	printf("number === %s\n", binary);
	break_bin(binary);
}