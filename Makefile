NAME		= philo

FLAGS		= -Wall -Wextra -Werror -g

FILES		= 1_main 2_check_valid 3_init_input 4_set_philos 5_creating_threads 6_eat_sleep_think 7_get_time errors utils

SRCS		= $(patsubst %, ./%.c, $(FILES))

OBJ			= $(SRCS:.c=.o)

HEADER		= philos.h

#TEST_INPUT	= check_parsed_input.c

%.o: %.c $(HEADER)
	gcc $(FLAGS) $< -c -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	gcc -g -o $(NAME) $(OBJ)

norm: $(SRCS) $(HEADER)
	norminette $(SRCS) $(HEADER)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all