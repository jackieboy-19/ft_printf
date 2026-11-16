/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrito <jbrito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 10:59:02 by jbrito            #+#    #+#             */
/*   Updated: 2026/11/04 10:59:03 by jbrito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unb(unsigned int n)
{
	int		count;
	char	c;

	count = 0;
	if (n < 10)
	{
		count = 1;
		c = n + '0';
		ft_putchar_fd(c, 1);
	}
	else
	{
		count += ft_print_unb(n / 10);
		count += ft_print_unb(n % 10);
	}
	return (count);
}
