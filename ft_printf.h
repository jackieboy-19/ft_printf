/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrito <jbrito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 10:59:07 by jbrito            #+#    #+#             */
/*   Updated: 2026/11/04 10:59:08 by jbrito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_print_char(char c);
int	ft_print_str(char *s);
int	ft_print_ptr(void *ptr);
int	ft_print_nbr(int n);
int	ft_print_unb(unsigned int n);
int	ft_print_hex(unsigned long n, char format);
int	ft_handle_format(char c, va_list *args);

#endif