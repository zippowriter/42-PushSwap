# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkono <hkono@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/24 23:15:37 by hkono             #+#    #+#              #
#    Updated: 2022/01/27 00:27:08 by hkono            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = main.c \
	error_checker.c \
	make_stacks.c \
	push_swap.c \
	rule_sort.c \
	quick_sort.c \
	quick_sort_helper.c \
	quick_sort_optimizer.c \
	cmd_p_and_s.c \
	cmd_r.c \
	doubly_linked_list.c \
	doubly_linked_list_delete.c \
	utils1.c \
	utils2.c
OBJS = $(addprefix srcs/, $(SRCS:.c=.o))

CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=leak
INCLUDES = -I./includes
LIBS = -L./libft -lft
vpath %.c srcs

$(NAME): $(OBJS)
	$(MAKE) bonus -C libft
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(INCLUDES) -o $@

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all: $(NAME)

clean:
	$(MAKE) fclean -C libft
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
