
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
# include <stdio.h>
int main() {
   int i;
   i = 0;
   char string[] = "string";
   void *ptr_1;
   char *ptr_2;
   int  *ptr_3;
   void *ptr_null;
   ptr_null = NULL;
   printf("\033[1;31m");
   printf("=============================================================================\n");
   printf("=============================================================================\n");
   printf("=============================================================== mabois ======\n");
   printf("******************** PART 1 :\n\n\n");
   printf("\033[0m;");
       printf("\033[0;36m======================= TEST\033[0m 1\n");
       i = printf("|TEST|\n");
           fflush(stdout);
       printf("                                             \033[1;33mretour officiel   : %d\033[0m\n", i);
       i = ft_printf("|TEST|\n");
       printf("                                             \033[1;33mretour unofficiel : %d\033[0m\n", i);
       printf("\033[0;36m======================= TEST\033[0m 2\n");
       i = printf("||\n");
           fflush(stdout);
       printf("                                             \033[1;33mretour officiel   : %d\033[0m\n", i);
       i = ft_printf("||\n");
       printf("                                             \033[1;33mretour unofficiel : %d\033[0m\n", i);
       printf("\033[0;36m======================= TEST\033[0m 3\n");
       i = printf("\n");
           fflush(stdout);
       printf("                                             \033[1;33mretour officiel   : %d\033[0m\n", i);
       i = ft_printf("\n");
       printf("                                             \033[1;33mretour unofficiel : %d\033[0m\n", i);
       printf("\033[0;36m======================= TEST\033[0m 4\n");
       i = printf("|fin des TESTs qui servenr a rien\200 < negatif|\n");
           fflush(stdout);
       printf("                                             \033[1;33mretour officiel   : %d\033[0m\n", i);
       i = ft_printf("|fin des TESTs qui servenr a rien\200 < negatif|\n");
       printf("                                             \033[1;33mretour unofficiel : %d\033[0m\n", i);
   printf("\033[1;31m");
   printf("\n=============================================================================\n");
   printf("******************** PART 2 :\n\n\n");
   printf("\033[0m;");
       printf("\033[0;36m======================= TEST\033[0m 1\n");
       i = printf("|ok %d , %d , %d , %d *** %u , %u, %u , %u|\n", 123, -500000000, 5000000000, -2147483648, 123, -500000000, 5000000000, -2147483648);
           fflush(stdout);
       printf("                                             \033[1;33mretour officiel   : %d\033[0m\n", i);
       i = ft_printf("|ok %d , %d , %d , %d *** %u , %u, %u , %u|\n", 123, -500000000, 5000000000, -2147483648, 123, -500000000, 5000000000, -2147483648);
       printf("                                             \033[1;33mretour unofficiel : %d\033[0m\n", i);
       printf("\033[0;36m======================= TEST\033[0m 2\n");
       i = printf("|ok %x , %x , %x , %x *** %X , %X, %X , %X|\n", 123, -500000000, 5000000000, -2147483648, 123, -500000000, 5000000000, -2147483648);
           fflush(stdout);
       printf("                                             \033[1;33mretour officiel   : %d\033[0m\n", i);
       i = ft_printf("|ok %x , %x , %x , %x *** %X , %X, %X , %X|\n", 123, -500000000, 5000000000, -2147483648, 123, -500000000, 5000000000, -2147483648);
       printf("                                             \033[1;33mretour unofficiel : %d\033[0m\n", i);
       printf("\033[0;36m======================= TEST\033[0m 2\n");
       i = printf("|ok %x , %x , %x , %x *** %X , %X, %X , %X|\n", -9999999999, -4294967296, 4294967295, -2147483648, -9999999999, -4294967296, 4294967295, -2147483648);
           fflush(stdout);

printf("                                             \033[1;33mretour officiel   : %d\033[0m\n", i);
       i = ft_printf("|ok %x , %x , %x , %x *** %X , %X, %X , %X|\n", -9999999999, -4294967296, 4294967295, -2147483648, -9999999999, -4294967296, 4294967295, -2147483648);
       printf("                                             \033[1;33mretour unofficiel : %d\033[0m\n", i);
       printf("\033[0;36m======================= TEST\033[0m 3\n");
       i = printf("|ok %i , %i , %i , %i\n", 123, -500000000, 5000000000, -2147483648);
           fflush(stdout);
       printf("                                             \033[1;33mretour officiel   : %d\033[0m\n", i);
       i = ft_printf("|ok %i , %i , %i , %i\n", 123, -500000000, 5000000000, -2147483648);
       printf("                                             \033[1;33mretour unofficiel : %d\033[0m\n", i);
   printf("\033[1;31m");
   printf("\n=============================================================================\n");
   printf("******************** PART 3 :\n\n\n");
   printf("\033[0m;");

}
