SRCS	=	./srcs/main.c ./srcs/instructions_a.c ./srcs/instructions_b.c ./srcs/instructions_mix.c ./srcs/final.c\
			./srcs/lst.c ./srcs/error.c ./srcs/helper_libft0.c ./srcs/helper_libft.c ./srcs/parsing.c ./srcs/cost.c \
			./srcs/checking.c ./srcs/free.c ./srcs/algo.c ./srcs/median.c ./srcs/cost_helper.c ./srcs/operation_cost.c

OBJS	=	$(SRCS:.c=.o)

BONUS           =   checker

BONUS_OBJS      =    $(BONUS:.c=.o)

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror -g3

RM		=	rm -f

NAME	=	push_swap

all:	$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(OBJS) -o $(NAME)

clean:
		$(RM) $(OBJS) $(BONUS_OBJS)

fclean:	clean
		$(RM) $(NAME)

re:		fclean $(NAME)

bonus:	$(OBJS) $(BONUS_OBJS)
	$(CC) $(OBJS) $(BONUS_OBJS) -o $(BONUS)

.PHONY:	all clean fclean re bonus
