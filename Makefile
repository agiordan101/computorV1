# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/01/16 17:11:58 by agiordan     #+#   ##    ##    #+#        #
#    Updated: 2019/03/15 07:47:28 by agiordan    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = computorV1

SRCS_PATH = srcs
SRCS_FILES =	main.c \
				resolve.c \
				list_functions.c \
				error.c \
				reduce.c
SRCS = $(addprefix $(SRCS_PATH)/, $(SRCS_FILES))

OBJS_PATH = objs
OBJS_NAME = $(SRCS_FILES:.c=.o)
OBJS = $(addprefix $(OBJS_PATH)/, $(OBJS_NAME))

INCLUDE_PATH = include
CC = gcc
FLAGS = -Wall -Werror -Wextra -I$(INCLUDE_PATH)

LIB1 = libft
LIBS = $(LIB1)/$(LIB1).a

all: $(NAME)

$(NAME): $(OBJS)
		make -C $(LIB1)
		$(CC) $(FLAGS) $(LIBS) $^ -o $@

$(OBJS_PATH)/%.o: $(SRCS_PATH)/%.c
		@mkdir $(OBJS_PATH) 2> /dev/null || true
		$(CC) $(FLAGS) -c $< -o $@

clean:
		make clean -C $(LIB1)
		@rm -rf $(OBJS_PATH) 2> /dev/null || true

fclean: clean
		make fclean -C $(LIB1)
		rm -f $(NAME)

re: fclean all

norme:
		@norminette $(LIB1)
		@norminette $(SRCS_PATH)
		@norminette $(INCLUDE_PATH)

.PHONY: all, clean, flcean, re
