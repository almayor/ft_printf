/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_private.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 11:31:07 by unite             #+#    #+#             */
/*   Updated: 2020/03/30 00:01:50 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_PRIVATE_H
# define FT_PRINTF_PRIVATE_H

# include <stdarg.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "libft.h"

# define BUFFER_SIZE	1024

# define KNRM  "\x1B[0m"
# define KRED  "\x1B[31m"
# define KGRN  "\x1B[32m"
# define KYEL  "\x1B[33m"
# define KBLU  "\x1B[34m"
# define KMAG  "\x1B[35m"
# define KCYN  "\x1B[36m"

# define MAX(A, B)	(A < B ? B : A)
# define MIN(A, B)	(A < B ? A : B)

typedef struct	s_buffer
{
	char		buffer[BUFFER_SIZE];
	size_t		inbuffer;
}				t_buffer;

typedef enum	e_length
{
	h, l, hh, ll, L, NONE
}				t_length;

typedef struct	s_optional
{
	size_t		value;
	int			isgiven;
}				t_optional;

typedef struct	s_specifier
{
	int					zero;
	int					minus;
	int					space;
	int					hash;
	int					plus;
	t_optional			precision;
	t_optional			width;
	t_length			length;
	unsigned char		formatid;
	size_t				npad_precision;
	size_t				npad_width;
}				t_specifier;

int				ft_vprintf(const char *format, va_list ap);
int				ft_vdprintf(int fd, const char *format, va_list ap);
int				ft_printf(const char *format, ...);
int				ft_dprintf(int fd, const char *format, ...);

/* 
** dispatchers
*/

int				parse_specifier(t_specifier *specif, const char **format, va_list ap);
int 			validate_specifier(t_specifier *specif);
int 			fetch_data(t_specifier *specif, void **data, va_list ap);
int 			complete_specifier(t_specifier *specif, void *data);
int 			print_data(t_specifier *specif, void *data);

/*
** utils
*/

size_t 			buffered_putchar(char c);
size_t			buffered_puts(const char *str);
size_t 			buffered_putnchar(char c, size_t n);

void			set_fd(int fd);
int				get_fd(void);
void			cleanup_buffer(void);
size_t			flush_buffer(void);

size_t			get_ndigits_ll(long long num, size_t base_len);
size_t			get_ndigits_ull(unsigned long long num, size_t base_len);
int				print_digits_ll(long long num, char *radix);
int				print_digits_ull(unsigned long long num, char *radix);
int				print_digits_lf(long double num, char *radix,
								size_t precision, int print_dot);

#endif
