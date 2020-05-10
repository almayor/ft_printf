# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: unite <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/26 02:09:26 by unite             #+#    #+#              #
#    Updated: 2020/05/10 21:05:34 by unite            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

TESTBEHAV_NAME = test_behavior
TESTSPEED_NAME = test_speed

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

TESTBEHAVSRC_NAME = \
main.c \
Unity/unity.c \

TESTSPEEDSRC_NAME = \
main.c \

################################################################################

PATHI = srcs
PATHS = srcs
PATHO = objs

PATHFT = libft
PATHFTA = $(PATHFT)/libft.a

PATHTESTBEHAVI = tests/behavior/srcs/Unity
PATHTESTBEHAVS = tests/behavior/srcs
PATHTESTBEHAVO = tests/behavior/objs

PATHTESTSPEEDI = 
PATHTESTSPEEDS = tests/speed/srcs
PATHTESTSPEEDO = tests/speed/objs

################################################################################

COMPILE = gcc -c
ARCHIVE = ar rc
INDEX = ranlib
LINK = gcc

CFLAGS = -Wall -Wextra -Werror
CFLAGS += -I$(PATHI) -I$(PATHFT)
CFLAGS_OPTIMISE = -O3 -std=gnu11 -ffast-math -march=native
CFLAGS_DEPEND = -MMD

CFLAGS_TESTBEHAV = -I$(PATHTESTBEHAVI)
CFLAGS_TESTSPEED = -I$(PATHTESTSPEEDI)

################################################################################

ifdef DEBUG
	COMPILE += -g
endif

################################################################################

SRC = $(patsubst %.c, $(PATHS)/%.c, $(SRC_NAME))
OBJ = $(patsubst %.c, $(PATHO)/%.o, $(SRC_NAME))


$(NAME) : $(OBJ) libft
	cp $(PATHFTA) $(NAME)
	$(ARCHIVE) $(NAME) $(OBJ)
	$(INDEX) $(NAME)

$(PATHO)/%.o : $(PATHS)/%.c
	mkdir -p $(@D)
	$(COMPILE) $(CFLAGS) $(CFLAGS_DEPEND) $(CFLAGS_OPTIMISE) $< -o $@

################################################################################

TESTBEHAVSRC = $(patsubst %.c, $(PATHTESTBEHAVS)/%.c, $(TESTBEHAVSRC_NAME))
TESTBEHAVOBJ = $(patsubst %.c, $(PATHTESTBEHAVO)/%.o, $(TESTBEHAVSRC_NAME))

$(TESTBEHAV_NAME) : $(NAME) $(TESTBEHAVOBJ)
	$(LINK) $^ -o $@

$(PATHTESTBEHAVO)/%.o : $(PATHTESTBEHAVS)/%.c
	mkdir -p $(@D)
	$(COMPILE) $(CFLAGS_TESTBEHAV) $< -o $@ -I . -I $(PATHTESTBEHAVI) 

################################################################################

TESTSPEEDSRC = $(patsubst %.c, $(PATHTESTSPEEDS)/%.c, $(TESTSPEEDSRC_NAME))
TESTSPEEDOBJ = $(patsubst %.c, $(PATHTESTSPEEDO)/%.o, $(TESTSPEEDSRC_NAME))

$(TESTSPEED_NAME) : $(NAME) $(TESTSPEEDOBJ)
	$(LINK) $^ -o $@

$(PATHTESTSPEEDO)/%.o : $(PATHTESTSPEEDS)/%.c
	mkdir -p $(@D)
	$(COMPILE) $(CFLAGS_TESTSPEED) $< -o $@ -I .

################################################################################

.PHONY : all clean fclean re test libft

all : $(NAME)

fclean : clean
	rm -f $(NAME)
	make -C $(PATHFT) fclean

clean :
	rm -rf $(PATHO)
	rm -rf $(PATHTESTBEHAVO) $(TESTBEHAV_NAME)
	rm -rf $(PATHTESTSPEEDO) $(TESTSPEED_NAME)
	make -C $(PATHFT) clean

re : fclean all

test-behavior : $(NAME) $(TESTBEHAV_NAME)
	@echo "\n======BEGIN TESTS======\n"
	./$(TESTBEHAV_NAME) 2>/dev/null

test-speed : $(NAME) $(TESTSPEED_NAME)
	@echo "\n======BEGIN TESTS======\n"
	./$(TESTSPEED_NAME) 2>/dev/null

libft :
	make -C $(PATHFT)

################################################################################

DEP = $(patsubst %.c, $(PATHO)/%.d, $(SRC_NAME))

-include $(DEP)

################################################################################
