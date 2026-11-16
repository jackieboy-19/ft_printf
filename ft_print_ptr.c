/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrito <jbrito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 10:58:56 by jbrito            #+#    #+#             */
/*   Updated: 2026/11/04 10:58:57 by jbrito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(void *ptr)
{
	unsigned long	n;

	if (ptr == NULL)
		return (write(1, "(nil)", 5));
	n = (unsigned long) ptr;
	write (1, "0x", 2);
	return (ft_print_hex(n, 'x') + 2);
}
