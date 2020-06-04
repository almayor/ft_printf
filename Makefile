# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: unite <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/26 02:09:26 by unite             #+#    #+#              #
#    Updated: 2020/06/05 01:57:51 by unite            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

TESTFUNC_NAME = test_functional
TESTPERF_NAME = test_performance

################################################################################

SRC_NAME = \
ft_printf.c \
ft_dprintf.c \
ft_vprintf.c \
ft_vdprintf.c \

SRC_NAME += \
parse_specifier/parse_specifier.c

SRC_NAME += \
validate_specifier/validate_specifier.c \
validate_specifier/functions/validate_specifier_b.c \
validate_specifier/functions/validate_specifier_c.c \
validate_specifier/functions/validate_specifier_f.c \
validate_specifier/functions/validate_specifier_i.c \
validate_specifier/functions/validate_specifier_p.c \
validate_specifier/functions/validate_specifier_s.c \
validate_specifier/functions/validate_specifier_u.c \
validate_specifier/functions/validate_specifier_x.c \

SRC_NAME += \
fetch_data/fetch_data.c \
fetch_data/functions/fetch_data_pc.c \
fetch_data/functions/fetch_data_s.c \
fetch_data/functions/fetch_data_f.c \
fetch_data/functions/fetch_data_p.c \
fetch_data/functions/fetch_data_c.c \
fetch_data/functions/fetch_data_i.c \
fetch_data/functions/fetch_data_u.c \

SRC_NAME += \
complete_specifier/complete_specifier.c \
complete_specifier/functions/complete_specifier_b.c \
complete_specifier/functions/complete_specifier_c.c \
complete_specifier/functions/complete_specifier_f.c \
complete_specifier/functions/complete_specifier_i.c \
complete_specifier/functions/complete_specifier_o.c \
complete_specifier/functions/complete_specifier_p.c \
complete_specifier/functions/complete_specifier_s.c \
complete_specifier/functions/complete_specifier_u.c \
complete_specifier/functions/complete_specifier_x.c \

SRC_NAME += \
print_data/print_data.c \
print_data/functions/print_data_b.c \
print_data/functions/print_data_c.c \
print_data/functions/print_data_f.c \
print_data/functions/print_data_i.c \
print_data/functions/print_data_o.c \
print_data/functions/print_data_p.c \
print_data/functions/print_data_s.c \
print_data/functions/print_data_u.c \
print_data/functions/print_data_x.c \
print_data/functions/print_data_xx.c \

SRC_NAME += \
utils/min.c \
utils/get_ndigits_ll.c \
utils/get_ndigits_ull.c \
utils/print_digits_lf.c \
utils/print_digits_ll.c \
utils/print_digits_ull.c \
utils/printing/buffered_putchar.c \
utils/printing/buffered_putnchar.c \
utils/printing/buffered_puts.c \

TESTFUNCSRC_NAME = \
main.c \
Unity/unity.c \

TESTPERFSRC_NAME = \
main.c \

################################################################################

PATHI = src
PATHS = src
PATHO = obj

PATHFT = libft
PATHFTA = $(PATHFT)/libft.a

PATHTESTFUNC = test/functional
PATHTESTFUNCI = $(PATHTESTFUNC)/src/Unity
PATHTESTFUNCS = $(PATHTESTFUNC)/src
PATHTESTFUNCO = $(PATHTESTFUNC)/obj

PATHTESTPERF = test/performance
PATHTESTPERFI = 
PATHTESTPERFS = $(PATHTESTPERF)/src
PATHTESTPERFO = $(PATHTESTPERF)/obj

################################################################################

COMPILE = gcc -c
LINK = gcc

CFLAGS = -Wall -Wextra -Werror
CFLAGS += -I$(PATHI) -I$(PATHFT)
CFLAGS_OPTIMISE = -O3 -std=gnu11 -ffast-math -march=native
CFLAGS_DEPEND = -MMD

CFLAGS_TESTFUNC = -I$(PATHTESTFUNCI)
CFLAGS_TESTPERF = -I$(PATHTESTPERFI)

################################################################################

ifeq ($(DEBUG), 1)
	COMPILE += -g
endif

################################################################################

SRC = $(patsubst %.c, $(PATHS)/%.c, $(SRC_NAME))
OBJ = $(patsubst %.c, $(PATHO)/%.o, $(SRC_NAME))


$(NAME) : $(OBJ) $(PATHFT)/libft.a
	cp $(PATHFTA) $(NAME)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(PATHO)/%.o : $(PATHS)/%.c
	mkdir -p $(@D)
	$(COMPILE) $(CFLAGS) $(CFLAGS_DEPEND) $(CFLAGS_OPTIMISE) $< -o $@

################################################################################

TESTFUNCSRC = $(patsubst %.c, $(PATHTESTFUNCS)/%.c, $(TESTFUNCSRC_NAME))
TESTFUNCOBJ = $(patsubst %.c, $(PATHTESTFUNCO)/%.o, $(TESTFUNCSRC_NAME))

$(PATHTESTFUNC)/$(TESTFUNC_NAME) : $(NAME) $(TESTFUNCOBJ)
	$(LINK) $^ -o $@

$(PATHTESTFUNCO)/%.o : $(PATHTESTFUNCS)/%.c
	mkdir -p $(@D)
	$(COMPILE) $< -o $@ -I . -I $(PATHTESTFUNCI) $(CFLAGS_TESTFUNC)

################################################################################

TESTPERFSRC = $(patsubst %.c, $(PATHTESTPERFS)/%.c, $(TESTPERFSRC_NAME))
TESTPERFOBJ = $(patsubst %.c, $(PATHTESTPERFO)/%.o, $(TESTPERFSRC_NAME))

$(PATHTESTPERF)/$(TESTPERF_NAME) : $(NAME) $(TESTPERFOBJ)
	$(LINK) $^ -o $@

$(PATHTESTPERFO)/%.o : $(PATHTESTPERFS)/%.c
	mkdir -p $(@D)
	$(COMPILE) $< -o $@ -I . $(CFLAGS_TESTPERF)

################################################################################

.PHONY : all clean fclean re test-functional test-performance test docs

all : $(NAME)

fclean : clean
	rm -f $(NAME)
	$(MAKE) -C $(PATHFT) fclean

clean :
	rm -rf $(PATHO)
	rm -rf $(PATHTESTFUNCO) $(PATHTESTFUNC)/$(TESTFUNC_NAME)
	rm -rf $(PATHTESTPERFO) $(PATHTESTPERF)/$(TESTPERF_NAME)
	$(MAKE) -C $(PATHFT) clean

re : fclean all

test : test-functional test-performance

test-functional : $(NAME) $(PATHTESTFUNC)/$(TESTFUNC_NAME)
	@echo "\n========= FUNCTIONAL TESTS =========\n"
	$(PATHTESTFUNC)/$(TESTFUNC_NAME) 2>/dev/null

test-performance : $(NAME) $(PATHTESTPERF)/$(TESTPERF_NAME)
	@echo "\n========= PERFORMANCE TESTS =========\n"
	$(PATHTESTPERF)/$(TESTPERF_NAME) 2>/dev/null

$(PATHFT)/libft.a :
	$(MAKE) -C $(PATHFT)

docs :
	docs/.doxygen/42toDoxygen.sh

################################################################################

DEP = $(patsubst %.c, $(PATHO)/%.d, $(SRC_NAME))

-include $(DEP)

################################################################################
