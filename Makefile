# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abutet <abutet@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/29 09:18:41 by abutet            #+#    #+#              #
#    Updated: 2024/03/29 09:18:42 by abutet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_MAIN	=	./srcs/main.c ./srcs/instructions_a.c ./srcs/instructions_b.c ./srcs/instructions_mix.c ./srcs/final.c\
				./srcs/lst.c ./srcs/error.c ./srcs/helper_libft0.c ./srcs/helper_libft.c ./srcs/parsing.c ./srcs/cost.c \
				./srcs/checking.c ./srcs/free.c ./srcs/algo.c ./srcs/median.c ./srcs/cost_helper.c ./srcs/operation_cost.c

SRCS_BONUS	=	./bonus/gnl_bonus.c ./bonus/checker_bonus.c ./bonus/main_bonus.c ./srcs/instructions_a.c ./srcs/instructions_b.c\
				./srcs/instructions_mix.c ./srcs/lst.c ./srcs/error.c ./srcs/helper_libft0.c ./srcs/helper_libft.c ./srcs/parsing.c \
				./srcs/checking.c ./srcs/free.c

OBJS_MAIN	=	$(SRCS_MAIN:.c=.o)
OBJS_BONUS	=	$(SRCS_BONUS:.c=.o)

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -g3
RM			=	rm -f

NAME		=	push_swap
BONUS		=	checker

all: $(NAME)

$(NAME): $(OBJS_MAIN)
	$(CC) $(OBJS_MAIN) -o $(NAME)

clean:
	$(RM) $(OBJS_MAIN) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME) $(BONUS)

re: fclean all

$(BONUS): $(OBJS_BONUS)
	$(CC) $(OBJS_BONUS) -o $(BONUS)

bonus: $(BONUS)

.PHONY: all clean fclean re bonus