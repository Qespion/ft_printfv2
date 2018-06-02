/*	************************************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 13:38:23 by oespion           #+#    #+#             */
/*   Updated: 2018/06/02 11:53:31 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <locale.h>
#include <wchar.h>

void	ft_printf(const char *format, ...);

int main()
{
//	setlocale(LC_ALL, "");
	wchar_t	*s;
	int		r;

	r = 254;
	s[0] = 'S';
	s[1] = 256;
	s[2] = 'u';
	s[3] = '\0';
	ft_printf("%-+-12.7Dt%0 4i %04.2% et %lc titi", 125, 124, 256);
	printf("\n");
	printf("\nstdout = %d\n", printf("%-+-12.7Dt%0 4i %04.2% et %lc titi", 125, 124, 256));
	return (0);
}
