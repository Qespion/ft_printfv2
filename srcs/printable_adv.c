/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printable_adv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 12:34:52 by oespion           #+#    #+#             */
/*   Updated: 2018/06/02 15:20:50 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print_c_width(t_list *p)
{
	int		width_tmp;
	int		r;
	char	spaces;

	spaces = ' ';
	r = 0;
	p->zeros && !p->negative ? spaces = '0' : 0;
	width_tmp = p->width - 1;
	while (r < width_tmp)
	{
		p->nbout++;
		ft_putchar(spaces);
		r++;
	}
}

int		printc(t_list *p)
{
	int		brett;

	!p->brett ? brett = getnb(p, 0) : 0;
	p->brett ? brett = p->brett : 0;
	if (p->l)
	{
		p->brett = brett;
		printunicode(p);
	//	ft_printf("nbout is = %d\n", p->nbout);
		return(1) ;
	}
	!p->l ? brett = (char)brett : 0;
	if ((brett > 255 || brett < -255) && !p->l)
	{
		ft_putchar('\0');
		p->nbout++;
		return (0);
	}
	ft_putcharn(p, brett);
	return (1);
}

void	printchar(t_list *p, char letter)
{
	if (letter == 'c')
	{
		printc(p);
		return ;
	}
	if ((p->precision != -1 || p->width != -1)
			&& letter != 'c')
		letter != '\0' ? ft_putcharnf(p, letter) : 0;
	else
		letter != '\0' ? ft_putchar(letter) : 0;
	letter != '\0' ? p->nbout++ : 0;
	letter != '\0' ? p->increment++ : 0;
}
