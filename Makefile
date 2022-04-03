SVR_NAME	= server.out
CNT_NAME	= client.out
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM 			= /bin/rm -f

INCS_DIR	= ./includes
LIBFT_DIR	= ./libft
LIBFT		= $(LIBFT_DIR)/libft.a

IFLAGS		= -I $(INCS_DIR) -I $(LIBFT_DIR)
LFLAGS		= -L libft -lft

SRV_SRCS	= server.c
CNT_SRCS	= client.c

all: $(NAME)

server:
	@make -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) $(SRV_SRCS) $(IFLAGS) $(LFLAGS) -o $(SRV_NAME)

client:
	@make -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) $(CNT_SRCS) $(IFLAGS) $(LFLAGS) -o $(CNT_NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)
	cp $(LIBFT) $(NAME)

bonus: all

clean:
	make clean -C $(LIBFT_DIR)
	$(RM) -r $(BUILD_DIR)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

re: fclean all

rebonus: fclean bonus

test: re
	@$(CC) main.c -lftprintf -L . -I $(INCS_DIR) -o runner.out
	@echo "\033[0;32m=== RUNNER ===\033[0m"
	@./runner.out

testmem: re
	@$(CC) $(CFLAGS) main.c -lftprintf -L . -I $(INCS_DIR) -o runner.out
	@echo "\033[0;32m=== RUNNER ===\033[0m"
	@valgrind -q --leak-check=full --track-origins=yes ./runner.out
	
.PHONY: all clean fclean re