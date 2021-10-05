NAME=program
BINPATH=unix/
SRCPATH=src/
SRCS=${SRCPATH}main.c
OBJS=${SRCS:.c=.o}
CC=gcc

%.o: %.c
	$(CC) -c $< -o $@

${BINPATH}$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $@

all: ${BINPATH}$(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

