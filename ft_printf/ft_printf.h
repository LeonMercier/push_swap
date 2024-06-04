/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 09:52:11 by lemercie          #+#    #+#             */
/*   Updated: 2024/06/04 12:06:01 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h> // malloc(), free()
# include <unistd.h> // write()
# include <stdarg.h> // va_*()
# include <limits.h> // INT_MAX etc
# include "libft/libft.h"

int		get_hexlen(uintptr_t n);
int		ft_write_buf(char *buf, int buflen);
char	*ft_itoa_long(long int n);
char	*handle_string(char *s);
char	*handle_voidptr(void *ptr);
char	*handle_int(int n);
char	*handle_uint(unsigned int n);
char	*handle_hex(uintptr_t n, char hexcase);
int		ft_printf(const char *format, ...);
#endif
