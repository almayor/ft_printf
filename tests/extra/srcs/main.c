/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 17:33:51 by unite             #+#    #+#             */
/*   Updated: 2020/02/21 23:28:26 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "unity.h"
#include "ft_printf.h"

void	test_output(const char *expected, const char *format, ...)
{
	static char	zero = 0;
	char		buffer[100];
	int 		pipefd[2];
	va_list		ap;

	va_start(ap, format);
	pipe(pipefd);

	ft_vdprintf(pipefd[1], format, ap);
	write(pipefd[1], &zero, 1);
	read(pipefd[0], buffer, 100);
	TEST_ASSERT_EQUAL_STRING_MESSAGE(expected, buffer, format);

	close(pipefd[0]);
	close(pipefd[1]);
	va_end(ap);
}

void	setUp(void)
{
	return ;
}

void	tearDown(void)
{
	return ;
}

void	test_asterix(void)
{
	test_output("|  1|", "|%*d|", 3, 1);
	test_output("|02|", "|%.*d|", 2, 2);
}

void	test_bflag(void)
{
	test_output("|101|", "|%b|", 5);
	test_output("|-101|", "|%b|", -5);
	test_output("|0|", "|%b|", 0);
}

int		main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_asterix);
	RUN_TEST(test_bflag);

	return (UNITY_END());
}
