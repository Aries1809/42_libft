/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseltenr <kseltenr@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 00:37:03 by kseltenr          #+#    #+#             */
/*   Updated: 2026/09/29 11:28:03 by kseltenr        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(long n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*s;
	long	n1;
	int		len;

	n1 = n;
	len = ft_intlen(n1);
	s = (char *)malloc(sizeof(char) * (len + 1));
	if (!s)
		return (NULL);
	s[len] = '\0';
	if (n1 == 0)
		s[0] = '0';
	if (n1 < 0)
	{
		s[0] = '-';
		n1 = -n1;
	}
	while (n1 > 0)
	{
		s[--len] = (n1 % 10) + '0';
		n1 /= 10;
	}
	return (s);
}
