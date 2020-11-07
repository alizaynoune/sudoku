# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/17 13:12:14 by alzaynou          #+#    #+#              #
#    Updated: 2020/11/07 11:21:12 by alzaynou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			libftdprintf.a
GCC = 			gcc -g -Wall -Werror -Wextra -c
OBJS = 			objs/

#*
#*** src dires
#*

PATH_LIBFT_CONV =	./libft/convert/
PATH_LIBFT_COUNT =	./libft/count/
PATH_LIBFT_EDIT =	./libft/edit/
PATH_LIBFT_IS =		./libft/is/
PATH_LIBFT_LST = 	./libft/lst/
PATH_LIBFT_MEM = 	./libft/mem/
PATH_LIBFT_PUT = 	./libft/put/
PATH_LIBFT_SRCH = 	./libft/srch/
PATH_LIBFT_STR = 	./libft/str/
PATH_LIBFT_FREE = 	./libft/free/
PATH_DPRINTF = 		./src/
PATH_NLINE =		./gnl/
PATH_INC = 			./includes/

#*
#*** src files
#*

LIBFT_CONV = 		ft_atoi_all.c				\
					ft_atoi.c					\
					ft_atol.c					\
					ft_atol_all.c				\
					ft_atoll.c					\
					ft_atoll_all.c				\
					ft_itoa.c					\
					ft_ltoa.c					\
					ft_lltoa.c					\
					ft_tolower.c				\
					ft_toupper.c				\
					ft_atoi_base.c				\
					ft_power.c					\
					ft_itoa_base.c

LIBFT_COUNT = 		count_words.c				\
					ft_count_char.c				\
					ft_strnlen.c				\
					ft_strlen.c					\
					start_end_words.c			\
					ft_intlen.c

LIBFT_EDIT = 		ft_bzero.c					\
					remove_last_space.c			\
					ft_strclr.c					\
					ft_skip_char.c

LIBFT_IS =			ft_all_digit.c				\
					ft_isalnum.c				\
					ft_isalpha.c				\
					ft_isascii.c				\
					ft_isdigit.c				\
					ft_isprint.c

LIBFT_LST = 		ft_lstadd.c					\
					ft_lstdel.c					\
					ft_lstdelone.c				\
					ft_lstiter.c				\
					ft_lstmap.c					\
					ft_lstnew.c

LIBFT_MEM = 		ft_memalloc.c				\
					ft_memccpy.c				\
					ft_memchr.c					\
					ft_memcmp.c					\
					ft_memcpy.c					\
					ft_memmove.c				\
					ft_memset.c					\
					ft_memdynamic.c

LIBFT_PUT = 		ft_putchar.c				\
					ft_putchar_fd.c				\
					ft_putendl.c				\
					ft_putendl_fd.c				\
					ft_putnbr.c					\
					ft_putnbr_fd.c				\
					ft_putstr.c					\
					ft_putstr_fd.c

LIBFT_SRCH = 		ft_strchr.c					\
					ft_strrchr.c				\
					ft_strstr.c					\
					ft_strnstr.c				\
					ft_strchrstr.c

LIBFT_STR = 		ft_strcat.c					\
					ft_strcmp.c					\
					ft_strhcmp.c				\
					ft_strcpy.c					\
					ft_strdup.c					\
					ft_strequ.c					\
					ft_striter.c				\
					ft_striteri.c				\
					ft_strjoin.c				\
					ft_strlcat.c				\
					ft_strmap.c					\
					ft_strmapi.c				\
					ft_strncat.c				\
					ft_strncmp.c				\
					ft_strncpy.c				\
					ft_strndup.c				\
					ft_strnequ.c				\
					ft_strnew.c					\
					ft_strsplit.c				\
					ft_strsub.c					\
					ft_strtrim.c				\
					split_by_str.c				\
					ft_nstrjoin.c

LIBFT_FREE = 		free_rev.c					\
					free_tab_char.c				\
					ft_strdel.c					\
					ft_memdel.c	

DPRINTF = 			dprintf.c					\
					specifier.c					\
					get_args.c					\
					helper_args.c				\
					convert_args.c				\
					put.c						\
					helper_put.c				\
					tools.c		

NLINE =				get_next_line.c

LIB_INC = 			./includes/libft.h
DPRINT_INC = 		./includes/ft_dprintf.h
NLINE_INC =			./includes/get_next_line.h
#*
#*** obj files
#*


LIB_OBJ :=	$(addprefix $(OBJS), $(LIBFT_CONV:.c=.o))		\
			$(addprefix $(OBJS), $(LIBFT_COUNT:.c=.o))		\
			$(addprefix $(OBJS), $(LIBFT_EDIT:.c=.o))		\
			$(addprefix $(OBJS), $(LIBFT_IS:.c=.o))			\
			$(addprefix $(OBJS), $(LIBFT_LST:.c=.o))		\
			$(addprefix $(OBJS), $(LIBFT_MEM:.c=.o))		\
			$(addprefix $(OBJS), $(LIBFT_PUT:.c=.o))		\
			$(addprefix $(OBJS), $(LIBFT_STR:.c=.o))		\
			$(addprefix $(OBJS), $(LIBFT_FREE:.c=.o))		\
			$(addprefix $(OBJS), $(LIBFT_SRCH:.c=.o))
OBJ_ALL := $(LIB_OBJ) $(addprefix $(OBJS), $(DPRINTF:.c=.o))
OBJ_ALL := $(OBJ_ALL) $(addprefix $(OBJS), $(NLINE:.c=.o))


#*
#*** colors
#*

DEF = 		\x1B[1;0m
RED = 		\x1B[1;31m
PURPLE =	\x1B[1;34m
BLUE = 		\x1B[1;96m
GREEN = 	\x1B[1;32m
SILVER = 	\x1B[1;90m
YELLOW = 	\x1B[1;33m

#*
#*** functions
#*

define compile
@mkdir -p $(OBJS)
@$(GCC) $1 -o $2 -I $(PATH_INC)
@printf "$(SILVER)[$(PURPLE)Object file$(BLUE) $(notdir $2)$(SILVER)] $(GREEN)Created.$(DEF)\n"
endef

define to_lib
@ar rc $1 $2
@ranlib $1
@printf "$(SILVER)[$(PURPLE)Library file$(YELLOW) $(notdir $1)$(SILVER)] $(GREEN)Created.$(DEF)\n"

endef

define remove_lib
@rm -f $1
@printf "$(SILVER)[$(PURPLE)library file$(YELLOW)$1$(SILVER)] $(RED)deleted.$(DEF)\n"
endef

#*
#*** rules
#*

all: $(NAME)

$(NAME): $(OBJ_ALL)
	@$(call to_lib, $(NAME), $(OBJ_ALL))

$(OBJS)%.o: $(PATH_LIBFT_CONV)%.c $(LIB_INC)
	@$(call compile,$<, $@)

$(OBJS)%.o: $(PATH_LIBFT_COUNT)%.c $(LIB_INC)
	@$(call compile,$<, $@)

$(OBJS)%.o: $(PATH_LIBFT_EDIT)%.c $(LIB_INC)
	@$(call compile,$<, $@)

$(OBJS)%.o: $(PATH_LIBFT_IS)%.c $(LIB_INC)
	@$(call compile,$<, $@)

$(OBJS)%.o: $(PATH_LIBFT_LST)%.c $(LIB_INC)
	@$(call compile,$<, $@)

$(OBJS)%.o: $(PATH_LIBFT_MEM)%.c $(LIB_INC)
	@$(call compile,$<, $@)

$(OBJS)%.o: $(PATH_LIBFT_PUT)%.c $(LIB_INC)
	@$(call compile,$<, $@)

$(OBJS)%.o: $(PATH_LIBFT_STR)%.c $(LIB_INC)
	@$(call compile,$<, $@)

$(OBJS)%.o: $(PATH_LIBFT_FREE)%.c $(LIB_INC)
	@$(call compile, $<, $@)

$(OBJS)%.o: $(PATH_LIBFT_SRCH)%.c $(LIB_INC)
	@$(call compile, $<, $@)

$(OBJS)%.o: $(PATH_DPRINTF)%.c $(DPRINTF_INC)
	@$(call compile,$<, $@)

$(OBJS)%.o: $(PATH_NLINE)%.c $(NLINE_INC)
	@$(call compile,$<, $@)

clean:
	@rm -rf $(OBJS)
	@printf "$(SILVER)[$(PURPLE)Path objects$(DEF) $(OBJS)$(SILVER)] $(RED)Deleted.$(DEF)\n"

fclean: clean
	@$(call remove_lib, $(NAME))

re: fclean all

.PHONY: re clean fclean all
