/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: froussel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 11:26:35 by froussel          #+#    #+#             */
/*   Updated: 2019/11/07 11:34:15 by froussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*ps;

	i = 0;
	if (!s1)
		return (0);
	while (s1[i])
		i++;
	if (!(ps = malloc(sizeof(*ps) * (i + 1))))
		return (0);
	i = 0;
	while (s1[i])
	{
		ps[i] = s1[i];
		i++;
	}
	ps[i] = '\0';
	return (ps);
}

char	*ft_strjoin(char const *str1, char const *str2)
{
	char	*res;
	char	*beg;
	int		len;

	if (!str1 && !str2)
		return (0);
	len = 0;
	if (str1)
		len = ft_strlen(str1);
	if (str2)
		len += ft_strlen(str2);
	if (!(res = malloc(sizeof(*res) * (len + 1))))
		return (0);
	beg = res;
	if (str1)
		while (*str1)
			*res++ = *str1++;
	if (str2)
		while (*str2)
			*res++ = *str2++;
	*res = '\0';
	return (beg);
}

size_t	ft_strlen(const char *s)
{
	size_t i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*p1;
	unsigned char	*p2;

	if (n == 0)
		return (0);
	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	i = 0;
	while (p1[i] && p2[i] && i < n - 1 && p1[i] == p2[i])
		i++;
	return (p1[i] - p2[i]);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ps;
	size_t	i;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		len = 0;
	else
		len -= start;
	if (!(ps = malloc(sizeof(*ps) * (len + 1))))
		return (0);
	i = 0;
	while (len-- > 0 && s[start + i])
	{
		ps[i] = s[start + i];
		i++;
	}
	ps[i] = '\0';
	return (ps);
}
