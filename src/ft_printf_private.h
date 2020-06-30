/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_private.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 11:31:07 by unite             #+#    #+#             */
/*   Updated: 2020/06/30 14:42:26 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_PRIVATE_H
# define FT_PRINTF_PRIVATE_H

# include <limits.h>
# include <stdarg.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include "libft.h"

# define BUFFER_SIZE	INT_MAX

# define KNRM  "\x1B[0m"
# define KRED  "\x1B[31m"
# define KGRN  "\x1B[32m"
# define KYEL  "\x1B[33m"
# define KBLU  "\x1B[34m"
# define KMAG  "\x1B[35m"
# define KCYN  "\x1B[36m"

typedef enum	e_mode
{
	T_FILE, T_STRING
}				t_mode;

typedef enum	e_length
{
	h, l, hh, ll, L, NONE
}				t_length;

typedef struct	s_optional
{
	size_t			value;
	int				isgiven;
}				t_optional;

typedef struct	s_specifier
{
	int				zero;
	int				minus;
	int				space;
	int				hash;
	int				plus;
	t_optional		precision;
	t_optional		width;
	t_length		length;
	unsigned char	formatid;
	size_t			npad_precision;
	size_t			npad_width;
}				t_specifier;

int				ft_vasprintf(char **ret, const char *format, va_list ap);
int				ft_vdprintf(int fd, const char *format, va_list ap);
int				ft_vprintf(const char *format, va_list ap);
int				ft_vsnprintf(char *str, size_t size, const char *format,
							va_list ap);
int				ft_vsprintf(char *str, const char *format, va_list ap);
int				ft_asprintf(char **ret, const char *format, ...);
int				ft_dprintf(int fd, const char *format, ...);
int				ft_printf(const char *format, ...);
int				ft_snprintf(char *str, size_t size, const char *format, ...);
int				ft_sprintf(char *str, const char *format, ...);

/*
** dispatchers
*/

int				parse_specifier(t_specifier *specif, const char **format,
								va_list ap);

int				validate_specifier(t_specifier *specif);
int				validate_specifier_c(t_specifier *specif);
int				validate_specifier_f(t_specifier *specif);
int				validate_specifier_i(t_specifier *specif);
int				validate_specifier_p(t_specifier *specif);
int				validate_specifier_s(t_specifier *specif);
int				validate_specifier_u(t_specifier *specif);
int				validate_specifier_x(t_specifier *specif);
int				validate_specifier_b(t_specifier *specif);

int				data_specifier(t_specifier *specif, void **data, va_list ap);
int				data_specifier_c(t_specifier *specif, void **data, va_list ap);
int				data_specifier_f(t_specifier *specif, void **data, va_list ap);
int				data_specifier_i(t_specifier *specif, void **data, va_list ap);
int				data_specifier_p(t_specifier *specif, void **data, va_list ap);
int				data_specifier_pc(t_specifier *specif, void **data, va_list ap);
int				data_specifier_s(t_specifier *specif, void **data, va_list ap);
int				data_specifier_u(t_specifier *specif, void **data, va_list ap);

int				complete_specifier(t_specifier *specif, void *data);
int				complete_specifier_c(t_specifier *specif, void *data);
int				complete_specifier_f(t_specifier *specif, void *data);
int				complete_specifier_i(t_specifier *specif, void *data);
int				complete_specifier_o(t_specifier *specif, void *data);
int				complete_specifier_p(t_specifier *specif, void *data);
int				complete_specifier_s(t_specifier *specif, void *data);
int				complete_specifier_u(t_specifier *specif, void *data);
int				complete_specifier_x(t_specifier *specif, void *data);
int				complete_specifier_b(t_specifier *specif, void *data);

int				print_specifier(t_specifier *specif, void *data);
int				print_specifier_c(t_specifier *specif, void *data);
int				print_specifier_f(t_specifier *specif, void *data);
int				print_specifier_i(t_specifier *specif, void *data);
int				print_specifier_o(t_specifier *specif, void *data);
int				print_specifier_p(t_specifier *specif, void *data);
int				print_specifier_s(t_specifier *specif, void *data);
int				print_specifier_u(t_specifier *specif, void *data);
int				print_specifier_x(t_specifier *specif, void *data);
int				print_specifier_xx(t_specifier *specif, void *data);
int				print_specifier_b(t_specifier *specif, void *data);

/*
** printing
*/

size_t			buffered_putchar(char c);
size_t			buffered_puts(const char *str);
size_t			buffered_putnchar(char c, size_t n);
int				buffered_putll(long long num, char *radix);
int				buffered_putull(unsigned long long num, char *radix);
int				buffered_putlf(long double num, char *radix,
								size_t precision, int print_dot);

void			set_fd(int fd);
void			set_output_string(char *str, size_t size);
void			cleanup_buffer(void);
size_t			flush_buffer(void);

/*
** utils
*/

size_t			min(size_t a, size_t b);
size_t			get_ndigits_ll(long long num, size_t base_len);
size_t			get_ndigits_ull(unsigned long long num, size_t base_len);

#endif
