CC = gcc  # C compiler
CFLAGS = -fPIC -O2 # C flags
#LDFLAGS = -shared   # linking flags
RM = rm -f   # rm command
#TARGET_LIB = libTH.a  # target lib
TARGET = repl

SRCS = th_lang.c th.c repl.c linenoise.c # source files
OBJS = $(SRCS:.c=.o)

.PHONY: all
all: ${TARGET}

$(TARGET_LIB): $(OBJS)
	ar -r ${LDFLAGS} -o $@ $^

$(TARGET): $(OBJS)
	$(CC) ${LDFLAGS} -o $@ $^

$(SRCS:.c=.d):%.d:%.c
	$(CC) $(CFLAGS) -MM $< >$@

include $(SRCS:.c=.d)

.PHONY: clean
clean:
	-${RM} ${TARGET_LIB} ${OBJS} $(SRCS:.c=.d)
