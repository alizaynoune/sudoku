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

all: $(NAME)

$(OBJS): $(OBJDIR)%.o: $(SRCDIR)%.c $(HEADER)
	@$(GCC) $(INCLUDE) -c $< -o $@
$(OBJDIR):
	@mkdir -p $@
$(LIBS):
	@make all -C libprintf/
$(NAME): $(OBJDIR) $(LIBS) $(OBJS)
	@$(GCC) $(OBJS) -L ./libprintf -lftprintf -o $@
clean:
	@rm -rf $(OBJDIR)
	@make clean -C libprintf/
fclean: clean
	@rm $(NAME)
	@make fclean -C libprintf/
re: fclean all

.PHONY: re clean all
