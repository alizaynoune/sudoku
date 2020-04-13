NAME = sudoku
GCC = gcc -Wall -Werror -Wextra

SRC = error.c		\
      free.c		\
      solution.c	\
      main.c
SRCDIR = src/

OBJDIR = obj/

SRCS = $(addprefix $(SRDIR), $(SRC))
OBJS = $(addprefix $(OBJDIR), $(SRC:.c=.o))
LIBS = libprintf/libftprintf.a
HEADER = include/sudoku.h
INCLUDE = -I./include

RED = \e[1;31m
MOVE = \e[1;34m
BLUE = \e[1;96m
GREEN = \e[1;32m
GREY = \e[1;90m
DEF = \e[0m

all: $(NAME)

$(OBJS): $(OBJDIR)%.o: $(SRCDIR)%.c $(HEADER)
	@$(GCC) $(INCLUDE) -c $< -o $@
	@echo "$(GREY)[ $(MOVE)Object file$(BLUE) $(notdir $@) $(GREY)] $(GREEN)Created.$(DEF)"
$(OBJDIR):
	@mkdir -p $@
$(LIBS):
	@make all -C libprintf/
$(NAME): $(OBJDIR) $(LIBS) $(OBJS)
	@$(GCC) $(OBJS) -L ./libprintf -lftprintf -o $@
	@echo "$(GREY)[ $(MOVE)Binary file$(BLUE) $(NAME) $(GREY)] $(GREEN)Created.$(DEF)"
clean:
	@rm -rf $(OBJDIR)
	@make clean -C libprintf/
fclean: clean
	@/bin/rm -f $(NAME)
	@echo "$(GREY)[ $(MOVE)Binary file$(BLUE) $(NAME) $(GREY)] $(RED)Deleted.$(DEF)"
	@make fclean -C libprintf/
re: fclean all

.PHONY: re clean all
