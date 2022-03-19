# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msahli <msahli@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/20 17:47:26 by msahli            #+#    #+#              #
#    Updated: 2021/08/20 17:47:26 by msahli           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

HEAD = ./includes/philosophers.h
SRCS=./srcs/
UTILS=./srcs/utils/
CFLAGS = -Wall -Wextra -Werror
C_FILE =	$(SRCS)main.c $(SRCS)init.c $(SRCS)treads.c \
			$(UTILS)base_utils.c $(UTILS)philo_utils.c \
			$(UTILS)massages.c $(UTILS)wait_tread.c \
			$(SRCS)check_die.c $(UTILS)arg.c
O_FILE = $(C_FILE:.c=.o)

all:
	$(MAKE) $(NAME) -j 4

$(NAME): $(O_FILE)
	gcc $(O_FILE) -o $(NAME)

%.o: %.c $(HEAD)
	gcc -c $(СFLAGS) $< -o $@

clean:
	@rm -f $(O_FILE)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
