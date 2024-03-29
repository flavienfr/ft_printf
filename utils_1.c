/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: froussel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 18:03:28 by froussel          #+#    #+#             */
/*   Updated: 2019/11/04 17:39:32 by froussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*chr_to_str(char c)
{
	char *str;

	if (!(str = ft_calloc(2, sizeof(*str))))
		return (NULL);
	*str = c;
	return (str);
}

char		*dec_to_hex(long int dec, char c)
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
	while (--i >= 0)
		dhex[j++] = shex[i];
	return (dhex);
}

char		*address_ptr(void *ptr)
{
	char		*p;
	char		*tmp;
	long int	add;

	if (!ptr)
		return (ft_strdup("0x0"));
	add = (long int)&*ptr;
	tmp = dec_to_hex(add, 'a');
	if (add == 0)
		p = ft_strdup("0x");
	else
		p = ft_strjoin("0x", tmp);
	free(tmp);
	return (p);
}

static int	len(long int n)
{
	int len;

	len = 0;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	else if (n == 0)
		return (1);
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char		*ft_itoa_long(long n)
{
	long int	i;
	long int	nn;
	char		*s;

	nn = n;
	i = len(nn);
	if (!(s = ft_calloc(i + 1, sizeof(*s))))
		return (0);
	i--;
	if (nn == 0)
		s[0] = '0';
	if (nn < 0)
	{
		s[0] = '-';
		nn *= -1;
	}
	while (nn > 0)
	{
		s[i] = (nn % 10) + 48;
		nn = nn / 10;
		i--;
	}
	return (s);
}
