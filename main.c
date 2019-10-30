/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: froussel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 14:37:54 by froussel          #+#    #+#             */
/*   Updated: 2019/10/30 19:08:11 by froussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define R "\x1b[31m"
#define G "\x1b[32m"
#define C "\x1b[36m"
#define S "\x1b[0m"
#define Y "\x1b[33m"
#define M "\x1b[34m"
#define B "\x1b[35m"

int main ()
{
	int i = -1, j = -1;
   	char ch = 'A';
   	char *str = "abcdef";
	void *ptr = str;
   	int no = 255;
   	int hex = 0X96;
   	unsigned int ui= 123456789;
	
	printf(B"=====================PRINTF VS FT_PRINTF=====================\n\n");
	printf("============== gestion de converstion simple ===================\n");
	printf("---------------------	  all type      ---------------------\n"S);
	printf("Char							%c \n"S, ch);
	ft_printf("Char							%c \n"S, ch);
   	printf("String							%s \n"S, str);
   	ft_printf("String							%s \n"S, str);
   	printf("Address							%p \n"S, ptr);
   	ft_printf("Address							%p \n"S, ptr);
   	printf("Integer							%d\n"S, no);
   	ft_printf("Integer							%d\n"S, no);
   	printf("Int (0 ou 0x)						%i \n"S, hex);
   	ft_printf("Int (0 ou 0x)						%i \n"S, hex);
   	printf("Unsignied int						%u \n"S, ui);
   	ft_printf("Unsignied int						%u \n"S, ui);
   	printf("Hexadecimal unsign int (lower-case)			%x \n"S, no);
   	ft_printf("Hexadecimal unsign int (lower-case)			%x \n"S, no);
   	printf("Hexadecimal unsign int (upper-case)			%X \n"S, no);
   	ft_printf("Hexadecimal unsign int (upper-case)			%X \n"S, no);
   	printf("Prints a literal %% character  				%% \n"S);
	ft_printf("Prints a literal %% character  				%% \n"S);
	printf(B"---------------------	  Type foirax    ---------------------\n");
	printf("-------- TEST 1 ---------\n"S);
   	i = printf("|%s| |%s|\n", NULL, "");
   	j = ft_printf("|%s| |%s|\n", NULL, "");
	(i != j) ? printf(R"KO Diff return\n") : printf(G"OK\n") ;
	printf("RETURN = printf :%d ft_printf: %d\n"S, i, j);
	printf(B"-------- TEST 2 ---------\n"S);
	char st2[55];
	long stl[100000];
	void *stv = stl;
	i=printf("Address |%p| void*|%p| char[55] |%p|, long *|%p|\n", NULL,stv,st2,stl);
  	j=ft_printf("Address |%p| void*|%p| char[55] |%p|, long *|%p|\n", NULL,stv,st2,stl);
	(i != j) ? printf(R"KO Diff return\n") : printf(G"OK\n") ;
	printf("RETURN = printf :%d ft_printf: %d\n"S, i, j);
	printf(B"-------- TEST 3 ---------\n"S);
	i = printf("|%-2c|\n", '\0');
	j = ft_printf("|%-2c|\n", '\0');
	(i != j) ? printf(R"KO Diff return\n") : printf(G"OK\n") ;
	printf("RETURN = printf :%d ft_printf: %d\n"S, i, j);
	printf(B"-------- TEST 4 ---------\n"S);
   	i=printf("Integer |%d| |%d|\n", -2147483648, 2147483647);
   	j=ft_printf("Integer |%d| |%d|\n", -2147483648, 2147483647);
	(i != j) ? printf(R"KO Diff return\n") : printf(G"OK\n") ;
	printf("RETURN = printf :%d ft_printf: %d\n"S, i, j);
	printf(B"-------- TEST 5 ---------\n"S);
   	i=printf("Unsignied int %u et 0 %u\n", 4294967295, 0);
   	j=ft_printf("Unsignied int %u et 0 %u\n", 4294967295, 0);
	(i != j) ? printf(R"KO Diff return\n") : printf(G"OK\n") ;
	printf("RETURN = printf :%d ft_printf: %d\n"S, i, j);
	printf(B"-------- TEST 6 ---------\n"S);
   	i=printf("Hexa time %x %X \n", 4294967295, 4294967295);
   	j=ft_printf("Hexa time %x %X \n", 4294967295, 4294967295);
	(i != j) ? printf(R"KO Diff return\n") : printf(G"OK\n") ;
	printf("RETURN = printf :%d ft_printf: %d\n"S, i, j);
	printf(B"-------- TEST 7 ---------\n"S);
   	i=printf("falg -0.*da.ns +le-%u%s.-50et apres 0x+%x.\n", 0, "text", 255);
   	j=ft_printf("falg -0.*da.ns +le-%u%s.-50et apres 0x+%x.\n", 0, "text", 255);
	(i != j) ? printf(R"KO Diff return\n") : printf(G"OK\n") ;
	printf("RETURN = printf :%d ft_printf: %d\n"S, i, j);
	printf(B"================= gestion de flads simple ===================\n");
	printf("-------- TEST 1 (width) ---------\n"S);
	char *txt = "Anticonstitutionnellement";
   	i=printf("|%1s|,|%24s|,|%25s|,|%26s|,|%50s|\n",txt,txt,txt,txt,txt);
   	j=ft_printf("|%1s|,|%24s|,|%25s|,|%26s|,|%50s|\n",txt,txt,txt,txt,txt);
	(i != j) ? printf(R"KO Diff return\n") : printf(G"OK\n") ;
	printf("RETURN = printf :%d ft_printf: %d\n"S, i, j);
	printf(B"-------- TEST 2 (-width) ---------\n"S);
   	i=printf("|%-1s|,|%-24s|,|%-25s|,|%-26s|,|%-50s|\n",txt,txt,txt,txt,txt);
   	j=ft_printf("|%-1s|,|%-24s|,|%-25s|,|%-26s|,|%-50s|\n",txt,txt,txt,txt,txt);
	(i != j) ? printf(R"KO Diff return\n") : printf(G"OK\n") ;
	printf("RETURN = printf :%d ft_printf: %d\n"S, i, j);
	printf(B"-------- TEST 3 (digit 0) ---------\n"S);
   	i=printf("|%01s|,|%024s|,|%025s|,|%026s|,|%050s|\n",txt,txt,txt,txt,txt);
   	j=ft_printf("|%01s|,|%024s|,|%025s|,|%026s|,|%050s|\n",txt,txt,txt,txt,txt);
	(i != j) ? printf(R"KO Diff return\n") : printf(G"OK\n") ;
	printf("RETURN = printf :%d ft_printf: %d\n"S, i, j);
	printf(B"-------- TEST 4 (precision) ---------\n"S);
   	i=printf("|%.s||%.1s|,|%.24s|,|%.25s|,|%.26s|,|%.50s|\n",txt,txt,txt,txt,txt,txt);
   	j=ft_printf("|%.s||%.1s|,|%.24s|,|%.25s|,|%.26s|,|%.50s|\n",txt,txt,txt,txt,txt,txt);
	(i != j) ? printf(R"KO Diff return\n") : printf(G"OK\n") ;
	printf("RETURN = printf :%d ft_printf: %d\n"S, i, j);
	printf(B"-------- TEST 5 (width) ---------\n"S);//
	unsigned int i2= 4294967295;
   	i=printf("|%1u|,|%24u|,|%25u|,|%26u|,|%50u|\n",i2,i2,i2,i2,i2);
   	j=ft_printf("|%1u|,|%24u|,|%25u|,|%26u|,|%50u|\n",i2,i2,i2,i2,i2);
	(i != j) ? printf(R"KO Diff return\n") : printf(G"OK\n") ;
	printf("RETURN = printf :%d ft_printf: %d\n"S, i, j);
	printf(B"-------- TEST 6 (-width) ---------\n"S);
    i=printf("|%-1u|,|%-24u|,|%-25u|,|%-26u|,|%-50u|\n",i2,i2,i2,i2,i2);
   	j=ft_printf("|%1u|,|%24u|,|%25u|,|%26u|,|%50u|\n",i2,i2,i2,i2,i2);
	(i != j) ? printf(R"KO Diff return\n") : printf(G"OK\n") ;
	printf("RETURN = printf :%d ft_printf: %d\n"S, i, j);
	printf(B"-------- TEST 7 (digit 0) ---------\n"S);
    i=printf("|%01u|,|%024u|,|%025u|,|%026u|,|%050u|\n",i2,i2,i2,i2,i2);
   	j=ft_printf("|%01u|,|%024u|,|%025u|,|%026u|,|%050u|\n",i2,i2,i2,i2,i2);
	(i != j) ? printf(R"KO Diff return\n") : printf(G"OK\n") ;
	printf("RETURN = printf :%d ft_printf: %d\n"S, i, j);
	printf(B"-------- TEST 8 (precision) ---------\n"S);
    i=printf("|%.1u|,|%.24u|,|%.25u|,|%.26u|,|%.50u|\n",i2,i2,i2,i2,i2);
   	j=ft_printf("|%.1u|,|%.24u|,|%.25u|,|%.26u|,|%.50u|\n",i2,i2,i2,i2,i2);
	(i != j) ? printf(R"KO Diff return\n") : printf(G"OK\n") ;
	printf("RETURN = printf :%d ft_printf: %d\n"S, i, j);
	printf(B"================= gestion de flads avancee ===================\n");
	printf("-------- TEST 1 (* precision) ---------\n"S);
	i=printf("|%.*s||%.*s|,|%.*s|,|%.*s|,|%.*s|,|%.*s|\n",0,txt,10,txt,-3,txt,30,txt,-30,txt,-10,txt);
   	j=ft_printf("|%.*s||%.*s|,|%.*s|,|%.*s|,|%.*s|,|%.*s|\n",0,txt,10,txt,-3,txt,30,txt,-30,txt,-10,txt);
	(i != j) ? printf(R"KO Diff return\n") : printf(G"OK\n") ;
	printf("RETURN = printf :%d ft_printf: %d\n"S, i, j);
	printf(B"-------- TEST 2 (* width) ---------\n"S);
   	i=printf("|%*s|,|%*s|,|%*s|,|%*s|,|%*s|\n",0,txt,10,txt,-3,txt,30,txt,-30,txt);
   	j=ft_printf("|%*s|,|%*s|,|%*s|,|%*s|,|%*s|\n",0,txt,10,txt,-3,txt,30,txt,-30,txt);
	(i != j) ? printf(R"KO Diff return\n") : printf(G"OK\n") ;
	printf("RETURN = printf :%d ft_printf: %d\n"S, i, j);
	

	//i=printf("|%.1u|,|%.24u|,|%.25u|,|%.26u|,|%.50u|\n",i2,i2,i2,i2,i2);
   	//j=ft_printf("|%.1u|,|%.24u|,|%.25u|,|%.26u|,|%.50u|\n",i2,i2,i2,i2,i2);

	
	return 0;
}
