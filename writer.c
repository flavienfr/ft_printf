/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: froussel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 14:39:06 by froussel          #+#    #+#             */
/*   Updated: 2019/11/04 16:34:04 by froussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	write_digit(t_arg *narg, int len)
{
	if (narg->prec && narg->type == 's' && narg->precision >= 0
		&& narg->precision < narg->len)
		narg->digit -= narg->precision;
	else
		narg->digit -= narg->len;
	if (*narg->arg == '-' && narg->type != 's' && narg->type != 'c')
	{
		len += ft_putchar_fd_len('-', 1);
		if (narg->digit > 0)
			len += fill_in(narg->digit, '0');
		len += ft_putstr_fd_len(&narg->arg[1], 1, narg);
		return (len);
	}
	if (narg->digit > 0)
		len += fill_in(narg->digit, '0');
	if (narg->prec && narg->precision < len && narg->type == 's')
		len += ft_putnstr_fd(narg->arg, 1, narg->precision);
	else
		len += ft_putstr_fd_len(narg->arg, 1, narg);
	return (len);
}

static int	write_width(t_arg *narg, int len)
{
	if (*narg->arg == '-' && narg->type != 's' && narg->type != 'c'
		&& narg->sign != -1 && narg->precision > narg->len - 1)
		narg->width -= narg->len - 1;
	if (narg->type != '%' && narg->type != 'c'
		&& ((narg->prec && narg->precision < narg->len && (narg->type == 's'))
		|| (narg->precision > narg->len && (narg->type != 's'))))
	{
		if (narg->precision < 0)
			narg->width -= narg->len;
		else
			narg->width -= narg->precision;
	}
	else
		narg->width -= narg->len;
	if (narg->width > 0)
		len += fill_in(narg->width, ' ');
	return (len);
}

static int	write_precision(t_arg *narg, int len)
{
	if (narg->type == 's')
		len += ft_putnstr_fd(narg->arg, 1, narg->precision);
	else if (narg->type == 'c' || narg->type == 'p' || narg->type == '%')
		return (len += ft_putstr_fd_len(narg->arg, 1, narg));
	else
	{
		if (narg->precision == 0 && narg->prec
		&& !(ft_strncmp(narg->arg, "0", narg->len)))
			return (len);
		if (*narg->arg == '-')
		{
			len += ft_putchar_fd_len('-', 1);
			if (narg->precision - (narg->len - 1) > 0)
				len += fill_in(narg->precision - (narg->len - 1), '0');
			len += ft_putstr_fd_len(&narg->arg[1], 1, narg);
			if (narg->precision < narg->width
			&& narg->precision > narg->len - 1)
				narg->width--;
			return (len);
		}
		if (narg->precision - narg->len > 0)
			len += fill_in(narg->precision - narg->len, '0');
		len += ft_putstr_fd_len(narg->arg, 1, narg);
	}
	return (len);
}

static int	write_arg(t_arg *narg, int len)
{
	if (narg->precision == 0 && narg->prec
	&& !(ft_strncmp(narg->arg, "0", narg->len)))
		narg->len = 0;
	if (narg->type == 'c' && *narg->arg == 0)
		len++;
	if (narg->type == '\0')
		return (len);
	if (narg->digit)
	{
		len = write_digit(narg, len);
		return (len);
	}
	if (narg->width > 0 && narg->sign != -1)
		len = write_width(narg, len);
	if (narg->prec)
		len = write_precision(narg, len);
	else
		len += ft_putstr_fd_len(narg->arg, 1, narg);
	if (narg->width > 0 && narg->sign == -1)
		len = write_width(narg, len);
	return (len);
}

int			writer(const char *format, t_arg *narg, int len)
{
	int	i;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			++i;
			while (!(first_in_set(format[i], "cspdiuxX%")) && format[i]
				&& first_in_set(format[i], "0123456789.-*"))
				i++;
			len = write_arg(narg, len);
			narg = narg->next;
		}
		else
			len += ft_putchar_fd_len(format[i], 1);
		if (format[i])
			i++;
	}
	return (len);
}
