/*	************************************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 13:38:23 by oespion           #+#    #+#             */
/*   Updated: 2018/06/02 16:44:04 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <locale.h>
#include <wchar.h>
#include <limits.h>

void	ft_printf(const char *format, ...);

int main()
{
	setlocale(LC_ALL, "");
	ft_printf("%hhO, %hhO", 0, USHRT_MAX);
	printf("\n");
	printf("\nstdout = %d\n", printf("%hhO, %hhO", 0, USHRT_MAX));
	return (0);
}
