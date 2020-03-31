# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: unite <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/26 02:09:26 by unite             #+#    #+#              #
#    Updated: 2020/03/31 17:53:16 by unite            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

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

FTSRC_NAME = \
ft_abs.c \
ft_atoi.c \
ft_bzero.c \
ft_chrinstr.c \
ft_chrisalnum.c \
ft_chrisalpha.c \
ft_chrisdigit.c \
ft_chrisprint.c \
ft_chrisspace.c \
ft_chrtolower.c \
ft_chrtoupper.c \
ft_exit.c \
ft_intlen.c \
ft_isalnum.c \
ft_isalpha.c \
ft_isascii.c \
ft_isdigit.c \
ft_isprint.c \
ft_isspace.c \
ft_itoa.c \
ft_lstadd.c \
ft_lstappend.c \
ft_lstcpy.c \
ft_lstcpy_str.c \
ft_lstcpyone.c \
ft_lstcpyone_str.c \
ft_lstdel.c \
ft_lstdel_str.c \
ft_lstdelone.c \
ft_lstdelone_str.c \
ft_lstiter.c \
ft_lstlast.c \
ft_lstmap.c \
ft_lstncpy.c \
ft_lstncpy_str.c \
ft_lstnew.c \
ft_lstnew_empty.c \
ft_lstnew_str.c \
ft_lstnew_str_empty.c \
ft_lstrev.c \
ft_lstrotate.c \
ft_max.c \
ft_memalloc.c \
ft_memccpy.c \
ft_memchr.c \
ft_memcmp.c \
ft_memcpy.c \
ft_memdel.c \
ft_memmove.c \
ft_memset.c \
ft_min.c \
ft_power.c \
ft_putchar.c \
ft_putchar_fd.c \
ft_putendl.c \
ft_putendl_fd.c \
ft_putnbr.c \
ft_putnbr_fd.c \
ft_putnstr.c \
ft_putnstr_fd.c \
ft_putstr.c \
ft_putstr_fd.c \
ft_range.c \
ft_sqrt.c \
ft_sqrtceil.c \
ft_strappend.c \
ft_strcapitalize.c \
ft_strcat.c \
ft_strcchr.c \
ft_strcdigits.c \
ft_strchr.c \
ft_strclr.c \
ft_strcmp.c \
ft_strcount.c \
ft_strcpy.c \
ft_strdel.c \
ft_strdup.c \
ft_strequ.c \
ft_strintab.c \
ft_striter.c \
ft_striteri.c \
ft_strjoin.c \
ft_strjoin_variadic.c \
ft_strlast.c \
ft_strlcat.c \
ft_strlcpy.c \
ft_strlen.c \
ft_strmap.c \
ft_strmap_inplace.c \
ft_strmapi.c \
ft_strncat.c \
ft_strncmp.c \
ft_strncpy.c \
ft_strndup.c \
ft_strnequ.c \
ft_strnew.c \
ft_strnotchr.c \
ft_strnstr.c \
ft_strprepend.c \
ft_strpsub.c \
ft_strrchr.c \
ft_strrev.c \
ft_strrsrch.c \
ft_strsplit.c \
ft_strsrch.c \
ft_strstr.c \
ft_strsub.c \
ft_strtrim.c \
ft_sum.c \
ft_tolower.c \
ft_toupper.c \
get_next_line.c \
get_next_line_untrim.c \

TESTBEHAV_NAME = test_behavior
TESTSPEED_NAME = test_speed

TESTBEHAVSRC_NAME = \
main.c \

TESTSPEEDSRC_NAME = \
main.c \

FRAMEWORKSRC_NAME = \
Unity/unity.c

################################################################################

PATHI = srcs
PATHS = srcs
PATHO = objs

PATHFTI = libft
PATHFTS = libft/srcs
PATHFTO = libft/objs

PATHTESTBEHAVI = tests/behavior/srcs/Unity
PATHTESTBEHAVS = tests/behavior/srcs
PATHTESTBEHAVO = tests/behavior/objs

PATHFRAMEWORKI = tests/behavior/srcs/Unity
PATHFRAMEWORKS = tests/behavior/srcs/Unity
PATHFRAMEWORKO = tests/behavior/objs

PATHTESTSPEEDI = .
PATHTESTSPEEDS = tests/speed/srcs
PATHTESTSPEEDO = tests/speed/objs

################################################################################

COMPILE = gcc -c
ARCHIVE = ar rc
INDEX = ranlib
LINK = gcc

CFLAGS = -Wall -Wextra -Werror
CFLAGS += -I$(PATHI) -I$(PATHFTI)
CFLAGS_OPTIMISE = -O3 -std=gnu11 -ffast-math -march=native
CFLAGS_DEPEND = -MMD

CFLAGS_TESTBEHAV = -I$(PATHTESTBEHAVI) -I$(PATHFRAMEWORKI)
CFLAGS_FRAMEWORK = -I$(PATHFRAMEWORKI)
CFLAGS_TESTSPEED = -I$(PATHTESTSPEEDI)

################################################################################

TRUE = 1
FALSE = 0

ifeq ($(DEBUG), $(TRUE)) 
	COMPILE += -g
endif

################################################################################

SRC = $(patsubst %.c, $(PATHS)/%.c, $(SRC_NAME))
OBJ = $(patsubst %.c, $(PATHO)/%.o, $(SRC_NAME))

FTSRC = $(patsubst %.c, $(PATHFTS)/%.c, $(FTSRC_NAME))
FTOBJ = $(patsubst %.c, $(PATHFTO)/%.o, $(FTSRC_NAME))

$(NAME) : $(OBJ) $(FTOBJ)
	$(ARCHIVE) $(NAME) $(OBJ) $(FTOBJ)
	$(INDEX) $(NAME)

$(PATHO)/%.o : $(PATHS)/%.c
	mkdir -p $(@D)
	$(COMPILE) $(CFLAGS) $(CFLAGS_DEPEND) $(CFLAGS_OPTIMISE) $< -o $@

$(PATHFTO)/%.o : $(PATHFTS)/%.c
	mkdir -p $(@D)
	$(COMPILE) $(CFLAGS) $(CFLAGS_OPTIMISE) $< -o $@

################################################################################

DEP = $(patsubst %.c, $(PATHO)/%.d, $(SRC_NAME))

-include $(DEP)

################################################################################

TESTBEHAVSRC = $(patsubst %.c, $(PATHTESTBEHAVS)/%.c, $(TESTBEHAVSRC_NAME))
TESTBEHAVOBJ = $(patsubst %.c, $(PATHTESTBEHAVO)/%.o, $(TESTBEHAVSRC_NAME))

FRAMEWORKSRC = $(patsubst %.c, $(PATHFRAMEWORKS)/%.c, $(FRAMEWORKSRC_NAME))
FRAMEWORKOBJ = $(patsubst %.c, $(PATHFRAMEWORKO)/%.o, $(FRAMEWORKSRC_NAME))

$(TESTBEHAV_NAME) : $(NAME) $(TESTBEHAVOBJ) $(FRAMEWORKOBJ)
	$(LINK) $^ -o $@

$(PATHTESTBEHAVO)/%.o : $(PATHTESTBEHAVS)/%.c
	mkdir -p $(@D)
	$(COMPILE) $(CFLAGS_TESTBEHAV) $< -o $@ -I . -I $(PATHTESTBEHAVI) 

$(PATHFRAMEWORKO)/%.o : $(PATHFRAMEWORKS)/%.c
	mkdir -p $(@D)
	$(COMPILE) $(CFLAGS_FRAMEWORK) $< -o $@

################################################################################

TESTSPEEDSRC = $(patsubst %.c, $(PATHTESTSPEEDS)/%.c, $(TESTSPEEDSRC_NAME))
TESTSPEEDOBJ = $(patsubst %.c, $(PATHTESTSPEEDO)/%.o, $(TESTSPEEDSRC_NAME))

$(TESTSPEED_NAME) : $(NAME) $(TESTSPEEDOBJ)
	$(LINK) $^ -o $@

$(PATHTESTSPEEDO)/%.o : $(PATHTESTSPEEDS)/%.c
	mkdir -p $(@D)
	$(COMPILE) $(CFLAGS_TESTSPEED) $< -o $@ -I .

################################################################################

.PHONY : all clean fclean re test

all : $(NAME)

fclean : clean
	rm -f $(NAME)

clean :
	rm -rf $(PATHO) $(PATHFTO)
	rm -rf $(PATHTESTBEHAVO) $(PATHFRAMEWORKO) $(TESTBEHAV_NAME)
	rm -rf $(PATHTESTSPEEDO) $(TESTSPEED_NAME)

re : fclean all

test-behavior : $(NAME) $(TESTBEHAV_NAME)
	@echo "\n======BEGIN TESTS======\n"
	./$(TESTBEHAV_NAME) 2>/dev/null

test-speed : $(NAME) $(TESTSPEED_NAME)
	@echo "\n======BEGIN TESTS======\n"
	./$(TESTSPEED_NAME) 2>/dev/null

################################################################################
