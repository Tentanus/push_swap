# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mweverli <mweverli@student.codam.n>          +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/01 17:54:19 by mweverli      #+#    #+#                  #
#    Updated: 2022/10/13 22:33:21 by mweverli      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#========================================#
#=========  GENERAL VARIABLES:  =========#
#========================================#

NAME		:=	push_swap

OBJ_DIR		:=	./OBJ
SRC_DIR		:=	./src
INC_DIR		:=	./include
LIB_DIR		:=	./lib

SRC			:=	ush_swap/push_swap_exit.c \
				push_swap/push_swap_init.c \
				push_swap/push_swap_init_utils.c \
				push_swap/push_swap_sort.c \
				operations/op_swap.c \
				operations/op_push.c \
				utils/list_utils.c \
				utils/stack_check.c

ifndef TEST
SRC			+=	push_swap/push_swap.c
else
SRC			+=	tester/test_main.c \
				tester/test_print.c
endif

OBJ			:=	$(addprefix $(OBJ_DIR)/,$(notdir $(SRC:.c=.o)))

SRC			:=	$(addprefix $(SRC_DIR)/,$(SRC))

#============== LIBRARIES ===============#

LIBFT		:=	libft
LIB_LIBFT	:=	$(LIB_DIR)/$(LIBFT)
LIB_LIB_ARC	:=	$(LIB_LIBFT)/$(LIBFT).a

LIB_LIST	:=	$(LIB_LIB_ARC)

#=============== COLOURS ================#

BOLD	:= \033[1m
RED		:= \033[31;1m
GREEN	:= \033[32;1m
CYAN	:= \033[36;1m
RESET	:= \033[0m

#============= COMPILATION ==============#

HEADER		:=	-I $(INC_DIR)\
				-I $(LIB_LIBFT)/include

ifdef TEST
HEADER		+=	-I ./src/tester/include
endif

LIB			:=

CC			:=	gcc
CFL			:=	-Wall -Werror -Wextra -g#fsanitize=address
COMPILE		:=	$(CC) $(CFL)

#========================================#
#============== RECIPIES  ===============#
#========================================#

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $@

$(NAME): $(LIB_LIST) $(OBJ) 
	@$(COMPILE) $^ $(HEADER) -o $(NAME) $(LIB) $(LIB_LIST) 
	@echo "$(CYAN)$(BOLD)COMPILING COMPLETE$(RESET)"

$(OBJ_DIR)/%.o:$(SRC_DIR)/*/%.c | $(OBJ_DIR)
	@$(COMPILE) -o $@ -c $< $(HEADER)
	@echo "$(CYAN)COMPILING: $(notdir $<)$(RESET)"

flclean: lclean fclean

lclean:
	@make -C $(LIB_LIBFT) clean
	@$(RM) $(LIB_LIB_ARC)

clean:
	@mkdir -p $(OBJ_DIR)
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)$(BOLD)Cleaning $(NAME)$(RESET)"

fclean: clean 
	@rm -f $(NAME)

re: fclean all

tclean: fclean
	rm -f $(EXE)

#========================================#
#============== LIBRARIES ===============#
#========================================#

$(LIB_LIB_ARC):
	@make -C $(LIB_LIBFT)

#========================================#
#============ MISCELLANEOUS =============#
#========================================#

.PHONY: all clean fclean tclean re test

.DEFAULT_GOAL := all
