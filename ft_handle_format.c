/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrito <jbrito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 10:58:45 by jbrito            #+#    #+#             */
/*   Updated: 2026/11/04 10:58:46 by jbrito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_format(char c, va_list *args)
{
	char	p;

	p = '%';
	if (c == 'c')
		return (ft_print_char(va_arg(*args, int)));
	else if (c == 's')
		return (ft_print_str(va_arg(*args, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_print_nbr(va_arg(*args, int)));
	else if (c == 'u')
		return (ft_print_unb(va_arg(*args, unsigned int)));
	else if (c == 'x')
		return (ft_print_hex(va_arg(*args, unsigned int), 'x'));
	else if (c == 'X')
		return (ft_print_hex(va_arg(*args, unsigned int), 'X'));
	else if (c == 'p')
		return (ft_print_ptr(va_arg(*args, void *)));
	else if (c == '%')
		return (write(1, &p, 1));
	return (0);
}
