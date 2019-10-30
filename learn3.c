/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   learn3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: froussel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 15:28:45 by froussel          #+#    #+#             */
/*   Updated: 2019/10/29 17:52:47 by froussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
char	*dec_to_hex(unsigned long dec, char c)
{
	char	shex[20];
	char	*dhex;
	int		i;
	int		j;

	i = 0;
	while (dec)
	{
		if ((dec % 16) < 10)
			shex[i++] = (dec % 16) + '0';
		else
			shex[i++] = (dec % 16) - 10 + c;
		dec = dec / 16;
	}
	if (i == 0)
		shex[i++] = '0';
	if (!(dhex = malloc(sizeof(*dhex) * (i + 1))))
		return (NULL);
	dhex[i] = '\0';
	j = 0;
	while (j <= i)
		dhex[j++] = shex[--i];
	return (dhex);
}

int main (void)
{	
	char st[8];
	char *f;
	unsigned long i;
	void *vd;
	int ret, ret1;
	f = dec_to_hex(0, 'a');
	ret = printf("0x%s\n", f);
/*
	i = (unsigned long)&*vd;
	printf("i =%lu\n", i);
	f = dec_to_hex(i, 'a');
	ret = printf("0x%s\n", f);
	ret1 = printf("%p\n", vd);
	printf("ret :%d, ret1 :%d", ret, ret1);*/
}
