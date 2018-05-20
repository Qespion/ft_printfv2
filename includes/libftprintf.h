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

typedef struct	s_list
{
	va_list			ap;
	void			*str;
	char			*base_str;
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
	int				h;
	int				hh;
	int				l;
	int				ll;
	int				j;
	int				z;
}				t_list;

int	ft_printf(const char* format, ...);

int	ft_int_len(long long nb);
const char	*end_of_int(const char *str);
int	ft_strlen(char *str);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_strdel(char **as);
int	ft_atoi(const char *str);
void	printchar(t_list *p, char letter);
void	ft_putcharnf(t_list *p);
void	ft_putcharn(t_list *p, char c);

void	write_with_precision(char *str, t_list *p);
void	ft_putstrn(t_list *p, char *str);
t_list	*create_struct(void);
t_list	*reset_struct(t_list *p);
void	ft_get_arg(char letter, t_list *p);

#endif
