
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: froussel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 14:37:54 by froussel          #+#    #+#             */
/*   Updated: 2019/10/31 18:48:36 by froussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main ()
{
	int i = -1, j = -1;
   	char ch = 'A';
   	char *str = "abcdef";
	void *ptr = str;
   	int no = 255;
   	int hex = 0X96;
   	unsigned int ui= 123456789;
	/*
	printf("mon nom est |%000*0010*s|\n",-5,20,  "42");
	printf("mon nom est |%000*0010d|\n",-5, 42);

	printf("mon nom est |%000*0010s|\n",5, "42");
	printf("mon nom est |%000*0010d|\n",5, 42);

	printf("mon nom est |%000*0010.1s|\n",5, "42");
	printf("mon nom est |%000*0010.3d|\n",5, 42);

	printf("mon nom est |%-0-00*s|\n",-5, "42");//undefined
	printf("mon nom est |%-0-000d|\n", 42);*/
	

	printf("...%..0-0..*d\n",-5, 10);
	printf("...%..0-0..-5d\n", 10);
	printf("...%..0-0..*d\n",-5, 10);

	printf("mon %000-005d\n", 10);
	printf("mon %-5d\n", 10);

	//printf("...%.*d..%....%-5d....%...*d..\n",5, 14, 14, -5);
	//printf("...%..10.-..-..5d..%....%-5d....%...*d..\n", 14, 14, -5);
	//printf("...%.....5d..%....%-5d....%...*d..\n", 14, 14, -5);

	//printf("...%0..0.-..-..-5d..%....%-5d....%...*d..\n", 14, 14, -5);
	/*
	printf("Double -%--*d neg %--*d\n", 5,10,-5,10);
	printf("Double 0%00*d neg %00*d\n", 5,10,-5,10);

	printf("Double -%--*s neg %--*s\n", 5,"le42",-5,"le42");//undefined behavior
	printf("Double 0%00*s neg %00*s\n", 5,"le42",-5,"le42");//undefined behavior

	printf("Double -%--*.*d neg %--*.*d neg %--*.*d\n",5,3,10,-5,-3,10,5,-14);
	printf("Double -%00*.*d neg %00*.*d neg %00*.*d\n",5,3,10,-5,-3,10,5,-14);

	printf("le pourcentage %% , %5%, %-5%, %.3%, preci %*.*%\n", -5, -10);
	printf("le pourcentage %% , %5%, %-5%, %.3%, preci %*%\n", -5);*/
}
