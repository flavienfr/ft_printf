/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcraipea <mcraipea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 11:39:18 by mcraipea          #+#    #+#             */
/*   Updated: 2019/11/05 14:16:37 by mcraipea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../ft_printf.h"

void	test_c()
{
	char 	c = 'A';
	int		i, j;

	printf("\033[1;34m");
	printf("--------------------------------------TEST %%C--------------------------------------\n\n\n");
	printf("\033[0m");
	printf("\n");

	if (((i = ft_printf("START%cEND\n", c)))
	== (j = printf("START%cEND\n", c)))
	{
		printf("\033[0;32m");
		printf("RETURN OK\n\n\n");
		printf("\033[0m");
		printf("\n");
	}
	else
	{
		printf("\033[0;31m");
		printf("printf =%d, ft_print=%d\n", i, j);
		printf("RETURN FALSE\n\n\n");
		printf("\033[0m");
		printf("\n");
	}

	printf("\033[0;34m");
	printf("--------------------- NBR %%C -------------------\n\n\n");
	printf("\033[0m");
	printf("\n");

	if ((ft_printf("START%20cEND\n", c))
	== printf("START%20cEND\n", c))
	{
		printf("\033[0;32m");
		printf("RETURN OK\n\n\n");
		printf("\033[0m");
		printf("\n");
	}
	else
	{
		printf("\033[0;31m");
		printf("printf =%d, ft_print=%d\n", i, j);
		printf("RETURN FALSE\n\n\n");
		printf("\033[0m");
		printf("\n");
	}

	if ((ft_printf("START%1cEND\n", c))
	== printf("START%1cEND\n", c))
	{
		printf("\033[0;32m");
		printf("RETURN OK\n\n\n");
		printf("\033[0m");
		printf("\n");
	}
	else
	{
		printf("\033[0;31m");
		printf("printf =%d, ft_print=%d\n", i, j);
		printf("RETURN FALSE\n\n\n");
		printf("\033[0m");
		printf("\n");
	}

	printf("\033[0;34m");
	printf("------------------ TIRET %%C ------------------\n\n\n");
	printf("\033[0m");
	printf("\n");

	if ((i=ft_printf("START%-20cEND\n", c))
	== (j=printf("START%-20cEND\n", c)))
	{
		printf("\033[0;32m");
		printf("RETURN OK\n\n\n");
		printf("\033[0m");
		printf("\n");
	}
	else
	{
		printf("\033[0;31m");
		printf("printf =%d, ft_print=%d\n", i, j);
		printf("RETURN FALSE\n\n\n");
		printf("\033[0m");
		printf("\n");
	}

	if ((i=ft_printf("START%-1cEND\n", c))
	== (j=printf("START%-1cEND\n", c)))
	{
		printf("\033[0;32m");
		printf("RETURN OK\n\n\n");
		printf("\033[0m");
		printf("\n");
	}
	else
	{
		printf("\033[0;31m");
		printf("printf =%d, ft_print=%d\n", i, j);
		printf("RETURN FALSE\n\n\n");
		printf("\033[0m");
		printf("\n");
	}

	if (((j = ft_printf("START%-20cEND\n", 0)))
	== (i = printf("START%-20cEND\n", 0)))
	{
		printf("\033[0;32m");
		printf("RETURN OK\n\n\n");
		printf("\033[0m");
		printf("\n");
	}
	else
	{
		printf("\033[0;31m");
		printf("printf =%d, ft_print=%d\n", i, j);
		printf("RETURN FALSE\n\n\n");
		printf("\033[0m");
		printf("\n");
	}

	if ((i=ft_printf("START%-20cEND\n", 1))
	== (j=printf("START%-20cEND\n", 1)))
	{
		printf("\033[0;32m");
		printf("RETURN OK\n\n\n");
		printf("\033[0m");
		printf("\n");
	}
	else
	{
		printf("\033[0;31m");
		printf("printf =%d, ft_print=%d\n", i, j);
		printf("RETURN FALSE\n\n\n");
		printf("\033[0m");
		printf("\n");
	}

	printf("\033[0;34m");
	printf("------------------ POINT %%C ------------------\n");
	printf("\033[0m");
	printf("\n");

	printf("\033[1;35m");
	printf("POINT SEUL : WARNING\n\n\n");
	printf("\033[0m");
	printf("\n");

	printf("\033[0;34m");
	printf("---------------- WILDCARD %%C -----------------\n");
	printf("\033[0m");
	printf("\n");

	if ((i=ft_printf("START%*cEND\n", 20, c))
	== (j=printf("START%*cEND\n", 20, c)))
	{
		printf("\033[0;32m");
		printf("RETURN OK\n\n\n");
		printf("\033[0m");
		printf("\n");
	}
	else
	{
		printf("\033[0;31m");
		printf("printf =%d, ft_print=%d\n", i, j);
		printf("RETURN FALSE\n\n\n");
		printf("\033[0m");
		printf("\n");
	}

	if ((i=ft_printf("START%*cEND\n", 1, c))
	== (j=printf("START%*cEND\n", 1, c)))
	{
		printf("\033[0;32m");
		printf("RETURN OK\n\n\n");
		printf("\033[0m");
		printf("\n");
	}
	else
	{
		printf("\033[0;31m");
		printf("printf =%d, ft_print=%d\n", i, j);
		printf("RETURN FALSE\n\n\n");
		printf("\033[0m");
		printf("\n");
	}

	if ((i=ft_printf("START%*cEND\n", 20, 0))
	== (j=printf("START%*cEND\n", 20, 0)))
	{
		printf("\033[0;32m");
		printf("RETURN OK\n\n\n");
		printf("\033[0m");
		printf("\n");
	}
	else
	{
		printf("\033[0;31m");
		printf("printf =%d, ft_print=%d\n", i, j);
		printf("RETURN FALSE\n\n\n");
		printf("\033[0m");
		printf("\n");
	}

	if ((j=ft_printf("START%*cEND\n", 20, 1))
	== (i=printf("START%*cEND\n", 20, 1)))
	{
		printf("\033[0;32m");
		printf("RETURN OK\n\n\n");
		printf("\033[0m");
		printf("\n");
	}
	else
	{
		printf("\033[0;31m");
		printf("printf =%d, ft_print=%d\n", i, j);
		printf("RETURN FALSE\n\n\n");
		printf("\033[0m");
		printf("\n");
	}


	printf("\033[0;34m");
	printf("------------------ ZERO %%C -------------------\n");
	printf("\033[0m");
	printf("\n");

	printf("\033[1;35m");
	printf("ZERO : WARNING\n\n\n");
	printf("\033[0m");
	printf("\n");


	if (((j = ft_printf("START%cEND\n", 0)))
	== (i = printf("START%cEND\n", 0)))
	{
		printf("\033[0;32m");
		printf("RETURN OK\n\n\n");
		printf("\033[0m");
		printf("\n");
	}
	else
	{
		printf("\033[0;31m");
		printf("printf =%d, ft_print=%d\n", i, j);
		printf("RETURN FALSE\n\n\n");
		printf("\033[0m");
		printf("\n");
	}
}
