/*	************************************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 13:38:23 by oespion           #+#    #+#             */
/*   Updated: 2018/05/31 19:20:19 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <locale.h>
#include <wchar.h>

void	ft_printf(const char *format, ...);

int main()
{
	setlocale(LC_ALL, "");
	wchar_t	test;

	test = 0x23;
	ft_printf("%s %C fdsfsdf", "dsf", 0x110000);
	printf("\n");
	printf("\nstdout = %d\n", printf("%s %C fdsfsda", "fds", 0x110000));
	return (0);
}
