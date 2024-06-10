.SILENT:

# Define colors
GREEN=\033[0;32m
RED=\033[0;31m
CYAN=\033[0;36m
YELLOW=\033[0;35m
RESET=\033[0m

CLIENT = client
SERVER = server
CLIENT_BONUS = client_bonus
SERVER_BONUS = server_bonus
CC = cc
CFLAGS = -Werror -Wextra -Wall
LIBFT_PATH = ./libft
RM = rm -f
NAME = minitalk
NAME_BONUS = minitalk_bonus

all: libft  ${NAME}

bonus: libft  ${NAME_BONUS}

libft:
	if [ ! -d "$(LIBFT_PATH)" ]; then \
		echo "${RED}Downloading LIBFT...${RESET}";	\
		git clone git@github.com:Harley-Davidson/libft.git $(LIBFT_PATH) > /dev/null 2>&1; \
	fi 
	${MAKE} -C ${LIBFT_PATH} > /dev/null 2>&1
	echo "${GREEN}LIBFT downloaded\n${RESET}";

.c.o:
	${CC} ${CFLAGS} -g -c $< -o ${<:.c=.o}

minitalk:
	${CC} ${CFLAGS} ${CLIENT}.c -o ${CLIENT} -L${LIBFT_PATH} -lft
	if [ "$(CLIENT)" ]; then \
		echo "${YELLOW}CLIENT is ready${RESET}"; fi
	${CC} ${CFLAGS} ${SERVER}.c -o ${SERVER} -L${LIBFT_PATH} -lft
	if [ "$(SERVER)" ]; then \
		echo "${CYAN}SERVER is ready\n${RESET}"; fi

minitalk_bonus:
	${CC} ${CFLAGS} ${CLIENT_BONUS}.c -o ${CLIENT_BONUS} -L${LIBFT_PATH} -lft
	if [ "$(CLIENT_BONUS)" ]; then \
		echo "${YELLOW}CLIENT is ready${RESET}"; fi
	${CC} ${CFLAGS} ${SERVER_BONUS}.c -o ${SERVER_BONUS} -L${LIBFT_PATH} -lft
	if [ "$(SERVER_BONUS)" ]; then \
		echo "${CYAN}SERVER is ready\n${RESET}"; fi

clean:
	${MAKE} -C ${LIBFT_PATH} clean > /dev/null 2>&1

fclean: clean
	${MAKE} -C ${LIBFT_PATH} fclean > /dev/null 2>&1
	${RM} ${CLIENT}
	${RM} ${SERVER}
	${RM} ${CLIENT_BONUS}
	${RM} ${SERVER_BONUS}
	${RM} -rf ${LIBFT_PATH}

re:			fclean all

.PHONY:		all bonus clean fclean re libft











