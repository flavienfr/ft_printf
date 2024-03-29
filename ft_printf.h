/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: froussel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 13:52:09 by froussel          #+#    #+#             */
/*   Updated: 2019/11/04 17:06:41 by froussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct	s_arg
{
	char			type;
	int				width;
	int				digit;
	int				precision;
	int				prec;
	int				sign;
	int				len;
	char			*arg;
	struct s_arg	*next;
}				t_arg;
/*
** ft_printf
*/
int				ft_printf(const char *format, ...);
void			arg_lstdelone(t_arg *lst);
void			arg_lstclear(t_arg **lst);
t_arg			*argnew(char type);
void			arg_lstadd_back(t_arg **alst, t_arg *new);
/*
** parser
*/
void			parser(const char *format, va_list ap, t_arg **lst);
/*
** writer
*/
int				writer(const char *format, t_arg *narg, int len);
/*
** utils_1
*/
char			*chr_to_str(char c);
char			*dec_to_hex(long int dec, char c);
char			*address_ptr(void *ptr);
char			*ft_itoa_long(long n);
/*
** utils_2
*/
int				fill_in(int field, char c);
int				ft_putnstr_fd(char *s, int fd, int n);
int				ft_putchar_fd_len(char c, int fd);
int				ft_putstr_fd_len(char *s, int fd, t_arg *narg);
int				first_in_set(char c, char *set);
/*
** utils_3
*/
char			*car_to_str(t_arg *narg);

#endif
