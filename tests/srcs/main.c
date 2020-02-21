/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 17:33:51 by unite             #+#    #+#             */
/*   Updated: 2020/02/21 22:14:42 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "unity.h"
#include "ft_printf.h"

void	test_output(int testid, const char *expected, const char *format, ...)
{
	static char	zero = 0;
	char		buffer[100];
	int 		pipefd[2];
	va_list		ap;
	char		*message;

	va_start(ap, format);
	pipe(pipefd);

	ft_vdprintf(pipefd[1], format, ap);
	write(pipefd[1], &zero, 1);
	read(pipefd[0], buffer, 100);
	asprintf(&message, "test id: %d", testid);
	TEST_ASSERT_EQUAL_STRING_MESSAGE(expected, buffer, message);

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
	int testid = 1;

	test_output(testid++, "|  1|", "|%*d|", 3, 1);
	test_output(testid++, "|02|", "|%.*d|", 2, 2);
}

void	test_bflag(void)
{
	int testid = 1;

	test_output(testid++, "|101|", "|%b|", 5);
	test_output(testid++, "|-101|", "|%b|", -5);
	test_output(testid++, "|0|", "|%b|", 0);
}

int		main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_asterix);
	RUN_TEST(test_bflag);

	return (UNITY_END());
}
