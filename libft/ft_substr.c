/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: froussel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:54:32 by froussel          #+#    #+#             */
/*   Updated: 2019/10/16 15:07:52 by froussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ps;
	size_t	i;

	if (!s)
		return (NULL);
	if (!(ps = malloc(sizeof(*ps) * (len + 1))))
		return (0);
	if (ft_strlen(s) < start)
		*ps = '\0';
	else
	{
		i = 0;
		while (s[start + i] && len-- > 0)
		{
			ps[i] = s[start + i];
			i++;
		}
		ps[i] = '\0';
	}
	return (ps);
}
