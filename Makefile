# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mweverli <mweverli@student.codam.n>          +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/01 17:54:19 by mweverli      #+#    #+#                  #
#    Updated: 2022/10/28 20:03:11 by mweverli      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#========================================#
#=========  GENERAL VARIABLES:  =========#
#========================================#

NAME		:=	push_swap
BONUS		:=	checker

OBJ_DIR		:=	./OBJ
SRC_DIR		:=	./src
INC_DIR		:=	./include
LIB_DIR		:=	./lib

SRC			:=	push_swap/push_swap.c \
				push_swap/push_swap_exit.c \
				push_swap/push_swap_init.c \
				push_swap/push_swap_init_utils.c \
				push_swap/push_swap_quick_sort.c \
				push_swap/push_swap_sort.c \
				operations/op_swap.c \
				operations/op_push.c \
				operations/op_rotate.c \
				utils/list_utils.c \
				utils/stack_check.c \
				tester/test_print.c

SRC_BONUS	:=	checker/checker.c \
				push_swap/push_swap_exit.c \
				push_swap/push_swap_init.c \
				push_swap/push_swap_init_utils.c \
				operations/op_push.c \
				operations/op_rotate.c \
				operations/op_swap.c \
				utils/list_utils.c \
				utils/stack_check.c

OBJ			:=	$(addprefix $(OBJ_DIR)/,$(notdir $(SRC:.c=.o)))
OBJ_BONUS	:=	$(addprefix $(OBJ_DIR)/,$(notdir $(SRC_BONUS:.c=.o)))

SRC			:=	$(addprefix $(SRC_DIR)/,$(SRC))
SRC_BONUS	:=	$(addprefix $(SRC_DIR)/,$(SRC_BONUS))

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

LIB			:=

CC			:=	gcc
CFL			:=	-Wall -Werror -Wextra -g
COMPILE		:=	$(CC) $(CFL)

#========================================#
#============== RECIPIES  ===============#
#========================================#

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $@

$(NAME): $(LIB_LIST) $(OBJ) 
	@$(COMPILE) $(HEADER) -o $(NAME) $(LIB) $^ 
	@echo "$(CYAN)$(BOLD)COMPILING $(NAME) COMPLETE$(RESET)"

bonus: $(BONUS)

$(BONUS): $(LIB_LIST) $(OBJ_BONUS)
	@$(COMPILE) $(HEADER) -o $(BONUS) $(LIB) $^ 
	@echo "$(CYAN)$(BOLD)COMPILING $(BONUS) COMPLETE$(RESET)"

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
	@rm -f $(BONUS)

re: fclean all

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
