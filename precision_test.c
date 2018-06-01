/*	************************************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 13:38:23 by oespion           #+#    #+#             */
/*   Updated: 2018/06/01 18:10:11 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <locale.h>
#include <wchar.h>

void	ft_printf(const char *format, ...);

int main()
{
	setlocale(LC_ALL, "");
	wchar_t	*s;
	int		r;

	r = 129;
	s[0] = 'a';
	s[1] = 250;
	s[2] = 'b';
	s[3] = '\0';
	ft_printf("%lc", 254);
	printf("\n");
	printf("\nstdout = %d\n", printf("%lc", 254));
	return (0);
}
