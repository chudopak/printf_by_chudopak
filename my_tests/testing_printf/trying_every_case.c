/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trying_every_case.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarash <pmarash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 13:43:53 by pmarash           #+#    #+#             */
/*   Updated: 2020/11/28 19:12:09 by pmarash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		main(void)
{
	int		c = -15;
	long		a = 10;

	//printing %
	printf("test %% -");
	printf("%%\n\n");

	//printing double quotes
	printf("test double quotes - ");
	printf("returned with right input - %d\n\n", printf("\"\"\"\"\"\n"));

	//testing 2 parameters with one %d
	printf("test 2 params with one %%d - ");
	printf("%d\n", c, a);
	printf("it worked, but returned 3 (equal nb of output characters) and warning\n");
	printf("printf return - %d\n\n", printf("%d\n", c, a, 6));

	//test output characters
	printf("test output nb - %d\n\n", printf("123456789 %d\n", 15));

	//test wrong output
	char	str[] = "test";
	printf("test wrong output %i\n\n", c);
	int	b;
	scanf("%i", &b);
	printf("%i - %X\n\n", b, b);
	
	//trying flags
	int	nb = -15;
	printf("%.5s %*i\n", "printf float", 5, nb);
	return (0);
}