/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrito <jbrito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 10:58:50 by jbrito            #+#    #+#             */
/*   Updated: 2026/11/04 10:58:51 by jbrito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned long n, char format)
{
	int	count;

	count = 0;
	if (n >= 16)
	{
		count += ft_print_hex (n / 16, format);
		count += ft_print_hex (n % 16, format);
	}
	else
	{
		if (n <= 9)
			ft_putchar_fd(n + '0', 1);
		else
		{
			if (format == 'X')
				ft_putchar_fd(n - 10 + 'A', 1);
			if (format == 'x')
				ft_putchar_fd(n - 10 + 'a', 1);
		}
		count++;
	}
	return (count);
}
