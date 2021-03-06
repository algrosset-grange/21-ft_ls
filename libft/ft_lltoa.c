/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 14:36:51 by agrosset          #+#    #+#             */
/*   Updated: 2015/12/03 10:54:57 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

static int	getlength(long long n)
{
	int				length;
	unsigned int	absn;

	length = (n <= 0) ? 1 : 0;
	absn = ft_abs_ll(n);
	while (absn > 0)
	{
		length++;
		absn /= 10;
	}
	return (length);
}

char		*ft_lltoa(long long n)
{
	int					length;
	char				*ch;
	char				negative;
	unsigned long long	absn;

	length = getlength(n);
	negative = (n < 0) ? 1 : 0;
	if ((ch = ft_strnew(length)) == NULL)
		return (NULL);
	length--;
	absn = ft_abs_ll(n);
	while (length >= 0)
	{
		ch[length] = '0' + absn % 10;
		absn /= 10;
		length--;
	}
	if (negative)
		ch[0] = '-';
	return (ch);
}
