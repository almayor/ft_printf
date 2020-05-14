/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 17:20:28 by unite             #+#    #+#             */
/*   Updated: 2020/05/14 23:42:22 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

/*
** @defgroup ft_printf ft_printf() family
** @brief Replicate behaviour of `printf(3)` functions.
** @details
** Support standard field values and combination thereof (where applicable):
** - flags: `#`, `0`, ` `, `-`, `+`
** - width and precision, including `*` options
** - length: `hh`, `h`, `l`, `ll`, `L`
** - type: `c`, `s`, `p`, `%`, `d`, `i`, `o`, `u`, `x`, `X`, `f`
**
** Custom specifications:
** - `b` type to print in binary format (supports same parameters as `i` type)
** - color support
**     - `cyan`
**     - `red`
**     - `green`
**     - `yellow`
**     - `blue`
**     - `magenta`
**     - <code> ft_printf("{red}Color-print. {eoc}Normal print."); </code><br>
**     gives<br>
**     <span style="font-family:monospace;"><span style="color:red;">
**     Color-print. </span>Normal print.</span>
**
** @see https://en.wikipedia.org/wiki/Printf_format_string
** @see https://linux.die.net/man/3/printf
*/
int	ft_printf(const char *format, ...);
int	ft_dprintf(int fd, const char *format, ...);
int	ft_vprintf(const char *format, va_list ap);
int	ft_vdprintf(int fd, const char *format, va_list ap);

#endif
