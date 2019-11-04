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
	if (narg->digit > 0)
		len += fill_in(narg->digit, '0');
	if (narg->prec && narg->precision < len && narg->type == 's')
		len += ft_putnstr_fd(narg->arg, 1, narg->precision);
	else
		len += ft_putstr_fd_len(narg->arg, 1);
	return (len);
}

static int	write_width(t_arg *narg, int len)
{
	if ((narg->prec && narg->precision < narg->len
		&& (narg->type == 's')) || (narg->precision > narg->len
		&& (narg->type != 's')))
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
		return (len += ft_putstr_fd_len(narg->arg, 1));
	else
	{
		if (narg->precision - narg->len > 0)
			len += fill_in(narg->precision - narg->len, '0');
		len += ft_putstr_fd_len(narg->arg, 1);
	}
	return (len);
}

static int	write_arg(t_arg *narg, int len)
{
	if (narg->type == 'c')
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
		len += ft_putstr_fd_len(narg->arg, 1);
	if (narg->width > 0 && narg->sign == -1)
		len = write_width(narg, len);
	return (len);
}

int			writer(const char *format, t_arg *narg, int len)
{
	int	i;

	i = -1;
	while (format[++i])
	{
		if (format[i] == '%')
		{
			++i;
			while (!(first_in_set(format[i], "cspdiuxX%")) && format[i + 1]
				&& first_in_set(format[i], "0123456789.-*"))
				i++;
			len = write_arg(narg, len);
			narg = narg->next;
		}
		else
			len += ft_putchar_fd_len(format[i], 1);
	}
	return (len);
}
