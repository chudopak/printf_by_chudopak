/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trying_every_case.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chudapak <chudapak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 13:43:53 by pmarash           #+#    #+#             */
/*   Updated: 2020/12/01 21:31:39 by chudapak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

int		main(void)
{
	int		c = -15;
	//long		a = 10;

	//printing %
	printf("test  /%%%%%d/ -", printf("%%\n\n"));
	
	printf("%d\n", printf(""));
	//printing double quotes
	printf("test double quotes - ");
	printf("returned with right  %d\n\n", printf("input -\"\"\"\"\"\n"));

	//testing 2 parameters with one %d
	printf("test 2 params with one %%d - ");
	//printf("%d\n", c, a);
	printf("it worked, but returned 3 (equal nb of output characters) and warning\n");
	//printf("printf return - %d\n\n", printf("%d\n", c, a, 6));

	//test output characters
	printf("test output nb - %d\n\n", printf("123456789 %d\n", 15));

	//test wrong output
	printf("test wrong output %i\n\n", c);
	int	b;
	scanf("%i", &b);
	printf("%i - %X\n\n", b, b);
	
	//trying flagsmake
	int	nb = -15;
	printf("%-10.5s %*i\n\n", "printf float", 5, nb);
	printf("%-++++++++++++---10.5i - %X\n\n", b, b);

	/*char str[] = "print %d %d safa";
	va_list ap;
	va_start(ap, str);
	int x = va_arg(ap, int);
	printf("%d\n", x);*/
	return (0);
}