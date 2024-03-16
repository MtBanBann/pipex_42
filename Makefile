# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afavier <afavier@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/02 14:45:57 by afavier           #+#    #+#              #
#    Updated: 2024/03/01 21:45:40 by afavier          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := pipex
SRC_DIR := src
BUILD_DIR := .build
DEPS_DIR := .deps
INC := inc/pipex.h

PIPEX =	$(SRC_DIR)/pipex.c \
		$(SRC_DIR)/pipex_utils.c \
		$(SRC_DIR)/pipex_close_all.c \
		$(SRC_DIR)/pipex_fd.c \
		$(SRC_DIR)/pipex_path.c \
		$(SRC_DIR)/cmd_one.c \
		$(SRC_DIR)/cmd_two.c \
		$(SRC_DIR)/pipex_error_path.c

SRC := $(PIPEX)

OBJS    := $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRC))
DEPS    := $(patsubst %.o, %.d,$(OBJS))

LIBS       				:= libft
LIBS_TARGET 			:= libft/libft.a

CC					    := cc -g3
CFLAGS					:= -Wall -Wextra -Werror
CPPFLAGS 				:= $(addprefix -I,$(INCS)) -MMD -MP
LDFLAGS 				:= $(addprefix -L,$(dir $(LIBS_TARGET)))
LDLIBS  				:= -L$(LIBS) -lft

RM := rm -f

all: $(NAME) 

force:


$(LIBS_TARGET): force
	@$(MAKE) -C $(@D) --no-print-directory

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
		mkdir -p $(@D)
		$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(LIBS_TARGET)
			$(CC) $(LDFLAGS) $(OBJS) $(LDLIBS) -o $(NAME)

-include $(DEPS)
# **************************************************************************** #
CLEAN_DIRS := libft/
clean:
	$(MAKE) -C $(CLEAN_DIRS) clean
	$(RM) -r $(BUILD_DIR) $(DEPS_DIR)
# **************************************************************************** #
fclean:
	$(MAKE) -C $(CLEAN_DIRS) fclean
	$(RM) -r $(BUILD_DIR) $(DEPS_DIR) $(NAME) $(BONUS)
# **************************************************************************** #
re: fclean all
# **************************************************************************** # # .PHONY #
.PHONY: all clean fclean re
# *****************************