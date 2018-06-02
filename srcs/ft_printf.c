/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 11:52:36 by oespion           #+#    #+#             */
/*   Updated: 2018/06/02 16:12:52 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

const char	*ft_flags(const char *format, t_list *p)
{
	if (*format == '-')
		p->negative = 1;
	else if (*format == '+')
		p->positive = 1;
	else if (*format == '0')
		p->zeros = 1;
	else if (*format == ' ')
		p->blank = 1;
	else if (*format == '#')
		p->sharp = 1;
	if (*format == '#' || *format == ' ' || *format == '+' || *format == '-'
			|| *format == '0')
		format++;
	if (*format == '#' || *format == ' ' || *format == '+' || *format == '-'
			|| *format == '0')
		return (ft_flags(format, p));
	return (format);
}

const char	*ft_width(const char *format, t_list *p)
{
	while ((*format >= '0' && *format <= '9') || *format == '*')
	{
		if (*format >= '0' && *format <= '9')
		{
			p->width = ft_atoi(format);
			format = end_of_int(format);
		}
		if (*format == '*')
		{
			p->width = va_arg(p->ap, int);
			if (p->width < 0)
			{
				p->negative = 1;
				p->width = ft_abs(p->width);
			}
			format++;
		}
	}
	return (format);
}

const char	*ft_precision(const char *format, t_list *p)
{
	if (*format == '.')
	{
		p->precision = 0;
		format++;
		if (*format == '-')
		{
			format++;
			p->negative = 1;
			format = ft_width(format, p);
		}
		while ((*format >= '0' && *format <= '9') || *format == '*')
		{
			if (*format >= '0' && *format <= '9')
			{
				p->precision = ft_atoi(format);
				format = end_of_int(format);
			}
			if (*format == '*')
			{
				p->precision = va_arg(p->ap, int);
				p->precision < 0 ? p->precision = -1 : 0;
				format++;
			}
		}
	}
	return (format);
}

const char	*ft_lenght_mod(const char *format, t_list *p)
{
	if (*format == 'h' && format[1] == 'h')
		p->hh = 1;
	else if (*format == 'l' && format[1] == 'l')
		p->ll = 1;
	else if (*format == 'h')
		p->h = 1;
	else if (*format == 'l')
		p->l = 1;
	else if (*format == 'j')
		p->j = 1;
	else if (*format == 'z')
		p->z = 1;
	while (*format == 'h' || *format == 'j' || *format == 'l'
			|| *format == 'z')
		format++;
	ft_get_arg(*format, p);
	return (format);
}

int checkafter(const char* format, t_list *p)
{
	int	r;
	int	l;

	l = 0;
	r = 0;
	while (format[r] != '%' && format[r])
		r++;
	if (format[r] == '%')
	{
		r++;
		while (format[r] != 's' && format[r] != 'd' && format[r] != 'c' && format[r] != 'x'
		&& format[r] != 'b' && format[r] != 'i' && format[r] != 'X' && format[r] != 'u'
		&& format[r] != 'o' && format[r] != 'O' && format[r] != 'U' && format[r] != 'D'
		&& format[r] != '%' && format[r] != 'p' && format[r] != 'C' && format[r] != 'S'
		&& format[r])
		{
			format[r] == 'l' && format[r + 1] != 'l' && format[r - 1] != 'l' ? l = 1 : 0;
			r++;
		}
		if (format[r] == 'C' || (format[r] == 'c' && l == 1))
		{
			if (checkunicode(p))
				return (0);
		}
	}
	return (1);
}

int	ft_printf(const char* format, ...)
{
	t_list	*p;
	int	outnbr;

	p = create_struct();
	va_start(p->ap, format);
	if (!format)
		return (0);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			format = ft_flags(format, p);
			format = ft_width(format, p);
			format = ft_precision(format, p);
			format = ft_lenght_mod(format, p);
		}
		//*format == '%' ? p->nbout++ : 0;
		p->increment ? format++ : 0;
		if (checkafter(format, p) == 1)
		{
			while (*format != '\0' && *format != '%' && p->brett != -1)
			{
				p->nbout++;
				ft_putchar((char)*format);
				format++;
			}
		}
	//	p->brett ? ft_printf("p->brett == %d\n", p->brett) : 0;
		if (p->brett == -1)
			break ;
		p = reset_struct(p);
	}
	va_end(p->ap);
//	printf("precision = %d\n", p->precision);
//			************************************penser a mettre le -1 au retour
//	printf("width = %d\n", p->width);
	outnbr = (p->brett == -1 ? -1 : p->nbout);
//	printf("\nstdout = %d\n", outnbr);
//	printf("\npbrett === %d\n", outnbr);
	//ft_strdel(&p->base_str);
	free(p);
	return (outnbr);
}
