/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 12:15:47 by oespion           #+#    #+#             */
/*   Updated: 2018/05/06 11:31:54 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define BUFF_SIZE 10
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct	s_list
{
	va_list			ap;
	void			*str;
	char			*base_str;
	int				brett;
	int				increment;
	int				nbout;
	int				precision;
	int				width;
	int				negative;
	int				positive;
	int				zeros;
	int				blank;
	int				neg;
	int				sharp;
	int				nopesign;
	int				hexa;
	int				h;
	int				hh;
	int				l;
	int				ll;
	int				j;
	int				z;
}				t_list;

int	ft_printf(const char* format, ...);

char	*ft_convert_base(uintmax_t nb, int base);
int	longlong_len(intmax_t nb);
const char	*end_of_int(const char *str);
int	uintmax_t_len(uintmax_t nb);
int	ft_strlen(char *str);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_strdel(char **as);
int	ft_atoi(const char *str);
void	printchar(t_list *p, char letter);
void	ft_putcharnf(t_list *p);
void	ft_putcharn(t_list *p, char c);
void	ft_putnbr(intmax_t nb);
uintmax_t	ft_abs(long long nb);
void	printunb(t_list*p, int maj);
void	printhexa(t_list *p, int maj);
char	*ft_toupper(char *str);

void	printaddress(t_list *p);
intmax_t	getnb(t_list *p, int maj);
uintmax_t	getunb(t_list *p, int maj);
void	ft_putstrn_hexa(t_list *p, char *str, int maj);
void	printnb(t_list *p, int maj);
void	ft_putnbr_uintmax(uintmax_t nb);
void	printoctal(t_list *p, int maj);
int		bin_to_dec(char *bin);
char	*ft_strjoin(char *s1, char *s2);

void	write_with_precision(char *str, t_list *p);
void	ft_putstrn(t_list *p, char *str);
t_list	*create_struct(void);
t_list	*reset_struct(t_list *p);
void	ft_get_arg(char letter, t_list *p);
void	printunicode(t_list *p);
char	*ft_convert_binary(uintmax_t nb);
void	ft_bzero(void *s, size_t n);
char	*ft_strcat(char *dest, const char *src);

void	ft_get_width(t_list *p, uintmax_t nbr);
void	ft_get_precision(uintmax_t nbr, t_list *p);
void	ft_pos(t_list *p);
void	width_write(int max, int width_tmp, char spaces, t_list *p);
void	printbinary(t_list *p);

void	ft_putstrn_octal(t_list *p, char *str);
int		checkunicode(t_list *p);
void	break_bin(char *binary, t_list *p);

void	print_uni_width(t_list *p, int nlen);
void	printlstring(t_list *p);

#endif
