/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trying_every_case.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarash <pmarash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 13:43:53 by pmarash           #+#    #+#             */
/*   Updated: 2020/12/24 19:19:35 by pmarash          ###   ########.fr       */
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
	
	printf("%0+d\n", printf(""));
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
	printf("%-10.*s %*i\n\n", 0, "printf float", 5, nb);
	printf("%-++++++++++++---10.5i - %X\n\n", b, b);

	int		wild_cards_width = 5;
	int		wild_cards_precision = -1;
	int	fl_nb = -3;

	printf("%d\n", printf("%0*.*d\n", wild_cards_width, wild_cards_precision, fl_nb));
	printf("%5.*d\n", 0, 0);
	//const char pr[] = "sdfa\'df % -3d\n";
	//printf(pr, 1);
	//int bv = -1;
	//printf ("%u\n", bv);
	//printf ("%+i\n", bv);
	//printf("%%%d\n", printf("%s", ""));
	/*char str[] = "print %d %d safa";
	va_list ap;
	va_start(ap, str);
	int x = va_arg(ap, int);*/
	//printf("%0-8.3d", -8473);
	printf("%%S tests\n\n");
	printf("%.02s\n", "test");
	printf("%.07s\n", NULL);
	char	*string;
	string = "string";
	printf("%d\n", printf("%.1000s\n", string));
	printf("%%C tests\n\n");
	printf("%d\n", printf("%c\n", 0));
	printf("%% tests\n\n");
	
	printf("%d\n", printf("%010.1u", 10 /*4294967294*/));
	printf("%%X tests\n\n");
	printf("%d\n", printf("%10.0x\n", 2345));
	printf("this %x number", 0);
	printf("\n--------\n");
	printf("%-2.7x", 3267);
	printf("%%P tests\n\n");
	int		tst_ptr;
	
	tst_ptr = 15;
	printf("%.*o", -3, 12345);
	
	return (0);
}