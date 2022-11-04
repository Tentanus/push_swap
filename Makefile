# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mweverli <mweverli@student.codam.n>          +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/01 17:54:19 by mweverli      #+#    #+#                  #
#    Updated: 2022/11/04 15:22:06 by mweverli      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#========================================#
#=========  GENERAL VARIABLES:  =========#
#========================================#

NAME		:=	./push_swap
BONUS		:=	./checker

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
				utils/stack_check.c 

SRC_BONUS	:=	checker/checker_bonus.c \
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

DEP			:=	$(OBJ:.o=.d)
DEP_BONUS	:=	$(OBJ_BONUS:.o=.d)

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

INCLUDE		:=	-I $(INC_DIR)\
				-I $(LIB_LIBFT)/include

LIB			:=

CC			:=	gcc
CFL			:=	-Wall -Werror -Wextra -g
COMPILE		:=	$(CC) $(CFL)

#========================================#
#============== RECIPIES  ===============#
#========================================#

all: $(NAME)

-include $(DEP)
-include $(DEP_BONUS)

$(OBJ_DIR):
	@mkdir -p $@

$(NAME): $(LIB_LIST) $(OBJ) 
	@$(COMPILE) $(INCLUDE) $(LIB) -o $(NAME) $^ 
	@echo "$(GREEN)$(BOLD)======= $(NAME) COMPILED =======$(RESET)"

bonus: $(BONUS)

$(BONUS): $(LIB_LIST) $(OBJ_BONUS)
	@$(COMPILE) $(INCLUDE) $(LIB) -o $(BONUS) $^ 
	@echo "$(GREEN)$(BOLD)======== $(BONUS) COMPILED ========$(RESET)"

$(OBJ_DIR)/%.o:$(SRC_DIR)/*/%.c | $(OBJ_DIR)
	@$(COMPILE) -o $@ -c $< $(INCLUDE) -MMD
	@echo "$(CYAN)COMPILING: $(notdir $<)$(RESET)"

clean:
	@mkdir -p $(OBJ_DIR)
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)$(BOLD)Cleaning $(notdir $(NAME))$(RESET)"

fclean: clean 
	@rm -f $(NAME)
	@rm -f $(BONUS)

lclean:
	@make -C $(LIB_LIBFT) clean
	@$(RM) $(LIB_LIB_ARC)

flclean: lclean fclean

re: fclean all

#========================================#
#============== LIBRARIES ===============#
#========================================#

$(LIB_LIB_ARC):
	@make -C $(LIB_LIBFT)

#========================================#
#============ MISCELLANEOUS =============#
#========================================#

.PHONY: all bonus clean fclean lclean flclean re

.DEFAULT_GOAL	:= all
