NAME		= minitalk
SVR_NAME	= server
CNT_NAME	= client
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM 			= /bin/rm -f

INCS_DIR	= ./includes
IFLAGS		= -I $(INCS_DIR)

SVR_SRCS	= server.c
CNT_SRCS	= client.c
UTILS_SRCS	= utils/ft_atoi.c \
			  utils/ft_bzero.c \
			  utils/ft_calloc.c \
			  utils/ft_putchar_fd.c \
			  utils/ft_putnbr_fd.c \
			  utils/ft_putstr_fd.c \
			  utils/my_bitv.c

all: $(NAME)

$(NAME): server client

server:
	@$(CC) $(CFLAGS) $(UTILS_SRCS) $(SVR_SRCS) $(IFLAGS) -o $(SVR_NAME)

client:
	@$(CC) $(CFLAGS) $(UTILS_SRCS) $(CNT_SRCS) $(IFLAGS) -o $(CNT_NAME)

clean:
	$(RM) $(SVR_NAME)
	$(RM) $(CNT_NAME)

fclean: clean

re: fclean all

bonus: all

rebonus: fclean bonus

test: re
	@valgrind -q --leak-check=full --track-origins=yes ./$(CNT_NAME) $(pid) "$(text)"
	
.PHONY: all clean fclean re