/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexhandler.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:17:26 by lemercie          #+#    #+#             */
/*   Updated: 2024/05/29 14:17:53 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	handle_hex_helper(char *result, uintptr_t n, int len, char hexcase)
{
	const char	lower[] = {"0123456789abcdef"};
	const char	upper[] = {"0123456789ABCDEF"};

	while (n > 0)
	{
		len--;
		if (hexcase == 'X')
			result[len] = upper[n % 16];
		else
			result[len] = lower[n % 16];
		n = n / 16;
	}
}

// hex conversion takes unsigned input
char	*handle_hex(uintptr_t n, char hexcase)
{
	char		*result;
	int			len;
	int			neg;

	if (n == 0)
		return (handle_string("0"));
	neg = 0;
	if (n < 0)
	{
		neg = 1;
		n = -n;
	}
	len = get_hexlen(n) + neg;
	result = (char *) malloc(sizeof(char) * (len + 1));
	if (!result)
		return (0);
	result[len] = 0;
	handle_hex_helper(result, n, len, hexcase);
	if (neg)
		result[0] = '-';
	return (result);
}
