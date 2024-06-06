.SILENT:

# Define colors
GREEN=\033[0;32m
RED=\033[0;31m
CYAN=\033[0;36m
YELLOW=\033[0;35m
RESET=\033[0m

CLIENT = client
SERVER = server
CC = cc
CFLAGS = -Werror -Wextra -Wall
LIBFT_PATH = ./libft
RM = rm -f
NAME = minitalk

all: libft  ${NAME}

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

run:	all
	./server;

clean:
	${MAKE} -C ${LIBFT_PATH} clean > /dev/null 2>&1

fclean: clean
	${MAKE} -C ${LIBFT_PATH} fclean > /dev/null 2>&1
	${RM} ${CLIENT}
	${RM} ${SERVER}
	${RM} -rf ${LIBFT_PATH}

re:			fclean all

.PHONY:		all clean fclean re libft











