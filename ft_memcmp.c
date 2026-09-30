/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseltenr <kseltenr@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 00:37:03 by kseltenr          #+#    #+#             */
/*   Updated: 2026/09/30 03:26:24 by kseltenr        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	while (n-- > 0)
	{
		if (*(const unsigned char *)s1 != *(const unsigned char *)s2)
			return (*(const unsigned char *)s1 - *(const unsigned char *)s2);
		s1 = (const unsigned char *)s1 + 1;
		s2 = (const unsigned char *)s2 + 1;
	}
	return (0);
}
