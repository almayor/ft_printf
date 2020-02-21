# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: unite <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/26 02:09:26 by unite             #+#    #+#              #
#    Updated: 2020/02/21 03:42:38 by unite            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC_NAME = ./ft_printf.c

SRC_NAME += \
./parse_specif/parse_specif.c

SRC_NAME += \
./check_specif/check_specif.c \
./check_specif/functions/check_specif_x.c \
./check_specif/functions/check_specif_u.c \
./check_specif/functions/check_specif_i.c \
./check_specif/functions/check_specif_c.c \
./check_specif/functions/check_specif_p.c \
./check_specif/functions/check_specif_f.c \
./check_specif/functions/check_specif_s.c \

SRC_NAME += \
./fetch_data/fetch_data.c \
./fetch_data/functions/fetch_data_pc.c \
./fetch_data/functions/fetch_data_s.c \
./fetch_data/functions/fetch_data_f.c \
./fetch_data/functions/fetch_data_p.c \
./fetch_data/functions/fetch_data_c.c \
./fetch_data/functions/fetch_data_i.c \
./fetch_data/functions/fetch_data_u.c \

SRC_NAME += \
./before_print/functions/before_print_f.c \
./before_print/functions/before_print_p.c \
./before_print/functions/before_print_o.c \
./before_print/functions/before_print_s.c \
./before_print/functions/before_print_x.c \
./before_print/functions/before_print_c.c \
./before_print/functions/before_print_i.c \
./before_print/functions/before_print_u.c \
./before_print/before_print.c \

SRC_NAME += \
./print_specif/print_specif.c \
./print_specif/functions/print_specif_x.c \
./print_specif/functions/print_specif_xx.c \
./print_specif/functions/print_specif_u.c \
./print_specif/functions/print_specif_i.c \
./print_specif/functions/print_specif_c.c \
./print_specif/functions/print_specif_p.c \
./print_specif/functions/print_specif_f.c \
./print_specif/functions/print_specif_s.c \
./print_specif/functions/print_specif_o.c \

SRC_NAME += \
./utils/buffered_nprint.c \
./utils/buffered_sprint.c \
./utils/buffered_print.c \
./utils/print_digits_ull.c \
./utils/get_ndigits_ll.c \
./utils/get_ndigits_ull.c \
./utils/print_digits_lf.c \
./utils/print_digits_ll.c \

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

################################################################################

PATHS = srcs
PATHO = objs

PATHFT = libft
PATHFTS = libft/srcs
PATHFTO = libft/objs

################################################################################

COMPILE = gcc -c
ARCHIVE = ar rc
INDEX = ranlib
LINK = gcc

CFLAGS = -Wall -Wextra -Werror
CFLAGS += -I$(PATHS) -I$(PATHFT)
CFLAGS += -O
CFLAGS_DEPEND = -MMD

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
	$(COMPILE) $(CFLAGS) $(CFLAGS_DEPEND) $< -o $@

$(PATHFTO)/%.o : $(PATHFTS)/%.c
	mkdir -p $(@D)
	$(COMPILE) $(CFLAGS) $< -o $@

################################################################################

DEP = $(patsubst %.c, $(PATHO)/%.d, $(SRC_NAME))

-include $(DEP)

################################################################################

.PHONY : all clean fclean re test

all : $(NAME)

fclean : clean
	rm -f $(NAME)

clean :
	rm -rf $(PATHO) $(PATHFTO) $(PATHTESTO) $(TEST_NAME)

re : fclean all

################################################################################
