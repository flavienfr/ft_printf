/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: froussel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 14:26:27 by froussel          #+#    #+#             */
/*   Updated: 2019/11/01 18:59:30 by froussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#define DP printf(‘’%s : %d”, __FILE__, __LINE__ );
#include "ft_printf.h"
void	parse_flag(char *str, t_arg *narg, va_list ap);
void	parser(const char *format, va_list ap, t_arg **lst)
{
	int 	i;
	int 	start;
	t_arg	*narg;
	char	*str;
	
	i = -1;
	while (format[++i])
	{
		//if (format[i] == '%' && format[i + 1] == '%')
		//	i++;
		if (format[i] == '%')
		{
			//printf("i =%d\n", i);
			start = ++i;
			while (!(first_in_set(format[i], "cspdiuxX%")))//flag %
				i++;
			str = ft_substr(format, start, i);
			//printf("ICI DEBUGG str =!%s! start=!%d! !i=%d!\n", str, start, i);
			narg = argnew(format[i]);
			//parse_width_sign(str, narg, ap);
			//parse_digit(str, narg, ap);
			parse_flag(str, narg, ap);
			parse_precision(str, narg, ap);
			
			parse_arg(narg, ap);
			arg_lstadd_back(lst, narg);
			free(str);
		}
	}
}
//RIP
void	parse_flag(char *str, t_arg *narg, va_list ap)
{
	int i;
	int var;
	int start;

	i = -1;
	var = 0;
	while(str[++i] && str[i] != '.')
	{
		if (str[i] == '*')
			var = va_arg(ap, int);
		if (str[i] == '-' || var < 0)
			narg->sign = -1;
		if (ft_isdigit(str[i]))
		{
			start = i;
			while (ft_isdigit(str[i + 1]))
				i++;
			var = ft_atoi(ft_substr(str, start, i + 1));//changer substr
		}
	}
	if (str[0] == '0' && narg->sign != -1 && str[i] == '\0')
		narg->digit = var;
	narg->width = (var < 0) ? var * -1 : var;
}

void	parse_precision(char *str, t_arg *narg, va_list ap)
{
	int i;
	int var;
	int start;

	i = 0;
	var = 0;
	while (str[i] && str[i] != '.')
		i++;
	if (str[i] == '.')
	{
		narg->prec = 1;
		while(str[i++])
		{
			if (str[i] == '*')
				var = va_arg(ap, int);
			/*if (str[i] == '-' || var < 0)
				narg->sign = -1;
			else if (var > 0)//utile ?
				narg->sign = 0;*/
			if (ft_isdigit(str[i]))
			{
				start = i;
				while (ft_isdigit(str[i + 1]))
					i++;
				var = ft_atoi(ft_substr(str, start, i + 1));//changer substr
			}
		}
	}
	narg->precision = var;
}
/*
void	parse_precision(char *str, t_arg *narg, va_list ap)
{
	int i;
	int start;

	i = 0;
	while (str[i])
	{
		if (str[i] == '.')//boucle tant aue .
		{
			narg->prec = 1;
			if (str[++i] == '*')
				narg->precision = va_arg(ap, int);
			else
			{
				start = i;
				while (ft_isdigit(str[i]))
					i++;
				narg->precision = ft_atoi(ft_substr(str, start, i));
			}
			return ;
		}
		//printf("la\n");
		i++;
	}
}
*/
char	*address_ptr(void *ptr)
{
	char *p;
	long int add;

	add = (long int)&*ptr;
	p = ft_strjoin("0x",dec_to_hex(add, 'a'));
	return (p);
}

void	parse_arg(t_arg *narg, va_list ap)
{
	if (narg->type == 'c')
		narg->arg = chr_to_str((char)va_arg(ap, int));
	else if (narg->type == 's')
		narg->arg = ft_strdup(va_arg(ap, char *));
	else if (narg->type == 'p')
		narg->arg = address_ptr(va_arg(ap, void *));
	else if (narg->type == 'd' || narg->type == 'i')
		narg->arg = ft_itoa(va_arg(ap, int));
	else if (narg->type == 'u')
		narg->arg = ft_itoa_long(va_arg(ap, unsigned int));
	else if (narg->type == 'x')
		narg->arg = dec_to_hex(va_arg(ap, unsigned int), 'a');
	else if (narg->type == 'X')
		narg->arg = dec_to_hex(va_arg(ap, unsigned int), 'A');
	else if (narg->type == '%')
		narg->arg = ft_strdup("%");
	if (narg->arg == NULL)
		narg->arg = ft_strdup("(null)");
	if (narg->type == 'c')
		narg->len = 1;
	else
		narg->len = ft_strlen(narg->arg);
	//if (narg->precision < 0)
	//	narg->precision *= -1; 
}
