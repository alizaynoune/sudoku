NAME = sudoku

GCC = gcc -Wall -Werror -Wextra

SRC = 	error.c			\
      	free.c			\
      	solution.c		\
	  	main.c
 
SRCDIR = src/

OBJDIR = obj/

OBJS = 		$(addprefix $(OBJDIR), $(SRC:.c=.o))
LIBS = 		libprintf/libftdprintf.a
HEADER = 	include/sudoku.h
INCLUDE = 	-I ./include -I libprintf/includes

RED = 		\e[1;31m
MOVE = 		\e[1;34m
BLUE = 		\e[1;96m
GREEN = 	\e[1;32m
GREY = 		\e[1;90m
DEF = 		\e[0m

define compile
@mkdir -p $(OBJDIR)
@$(GCC) $(INCLUDE) -c $1 -o $2
@printf "$(GREY)[$(MOVE)Object file$(BLUE) $(notdir $2) $(GREY)] $(GREEN)Created.$(DEF)\n"
endef

define call_make
@make $1 --no-print-directory -C libprintf/
endef

all: $(NAME)

$(NAME): $(OBJS) $(LIBS)
	@$(GCC) $(OBJS) -L ./libprintf -lftdprintf -o $@
	@printf "$(GREY)[$(MOVE)Binary file$(BLUE) $(NAME) $(GREY)] $(GREEN)Created.$(DEF)\n"

$(LIBS):
	@$(call call_make, all)

$(OBJS): $(OBJDIR)%.o: $(SRCDIR)%.c $(HEADER)
		   @$(call compile, $<, $@)

clean:
	@rm -rf $(OBJDIR)
	@printf "$(GREY)[$(MOVE)Path objects$(DEF) $(OBJDIR)$(GREY)] $(RED)Deleted.$(DEF)\n"
	@$(call call_make, clean)

fclean: clean
	@/bin/rm -f $(NAME)
	@printf "$(GREY)[$(MOVE)Binary file$(BLUE) $(NAME) $(GREY)] $(RED)Deleted.$(DEF)\n"
	@$(call call_make, fclean)

re: fclean all

.PHONY: re clean all
