/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_private.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 11:31:07 by unite             #+#    #+#             */
/*   Updated: 2020/02/21 03:12:13 by unite            ###   ########.fr       */
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
# define KWHT  "\x1B[37m"

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

int				parse_specif(t_specifier *specif, const char **format, va_list ap);
int 			check_specif(t_specifier *specif);
int 			fetch_data(t_specifier *specif, void **data, va_list ap);
int 			before_print(t_specifier *specif, void *data);
int 			print_specif(t_specifier *specif, void *data);

/* utils */

size_t 			buffered_nprint(unsigned char c, size_t n, int flush, int cleanup);
size_t			buffered_sprint(char *str, int flush, int cleanup);
size_t 			buffered_print(unsigned char c, int flush, int cleanup);
size_t			get_ndigits_ll(long long num, size_t base_len);
size_t			get_ndigits_ull(unsigned long long num, size_t base_len);
int				print_digits_ll(long long num, char *radix);
int				print_digits_ull(unsigned long long num, char *radix);
int				print_digits_lf(long double num, char *radix,
								size_t precision, int print_dot);

#endif
