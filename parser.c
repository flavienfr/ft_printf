/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: froussel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 14:26:27 by froussel          #+#    #+#             */
/*   Updated: 2019/11/05 14:06:27 by froussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_number(char *str, int *var, int i)
{
	char	*tmp;
	int		start;

	if (ft_isdigit(str[i]))
	{
		start = i;
		while (ft_isdigit(str[i + 1]))
			i++;
		tmp = ft_substr(str, start, i + 1);
		*var = ft_atoi(tmp);
		free(tmp);
	}
	return (i);
}

static void	parse_precision(char *str, t_arg *narg, va_list ap)
{
	int		i;
	int		var;

	i = 0;
	var = 0;
	if (str[i] == '.')
	{
		narg->prec = 1;
		while (str[i++])
		{
			if (str[i] == '*')
				var = va_arg(ap, int);
			i = check_number(str, &var, i);
		}
	}
	narg->precision = var;
}

static void	parse_flag(char *str, t_arg *narg, va_list ap)
{
	int		var;
	int		i;

	i = -1;
	var = 0;
	while (str[++i] && str[i] != '.')
	{
		if (str[i] == '*')
			var = va_arg(ap, int);
		if (str[i] == '-' || var < 0)
			narg->sign = -1;
		i = check_number(str, &var, i);
	}
	parse_precision(&str[i], narg, ap);
	if (str[0] == '0' && narg->sign != -1 &&
		(narg->precision < 0 || narg->prec == 0 || narg->type == 's'
		|| narg->type == 'c' || narg->type == '%'))
		narg->digit = var;
	else
		narg->width = (var < 0) ? var * -1 : var;
}

static void	parse_arg(t_arg *narg, va_list ap)
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
	else
		narg->arg = ft_strdup(&narg->type);
	if (narg->arg == NULL)
		narg->arg = ft_strdup("(null)");
	if (narg->type == 'c')
		narg->len = 1;
	else
		narg->len = ft_strlen(narg->arg);
}

void		parser(const char *format, va_list ap, t_arg **lst)
{
	int		i;
	int		start;
	t_arg	*narg;
	char	*str;

	i = -1;
	while (format[++i])
	{
		if (format[i] == '%')
		{
			start = ++i;
			while (!(first_in_set(format[i], "cspdiuxX%")) && format[i]
				&& first_in_set(format[i], "0123456789.-*"))
				i++;
			str = ft_substr(format, start, i);
			narg = argnew(format[i]);
			parse_flag(str, narg, ap);
			parse_arg(narg, ap);
			arg_lstadd_back(lst, narg);
			free(str);
		}
	}
}
