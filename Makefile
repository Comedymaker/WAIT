CC=gcc
CFLAGS=

OBJS= src/main.o \
	  src/parse.o \

OBJS_TEST= src/test.o \
		   src/parse.o \

build: $(OBJS)
	$(CC) -o target/WAIT $(OBJS) $(CFLAGS)

all: clean build
	./target/WAIT > log.txt

build-test: $(OBJS_TEST)
	$(CC) -o target/test $(OBJS_TEST) $(CFLAGS)

test: clean build-test
	./target/test > log.txt

$(OBJS_TEST):%.o:%.c
	$(CC) -c $< -o $@ $(CFLAGS)

$(OBJS):%.o:%.c
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm -f target/*
	rm -f src/*.o
	rm -f *.txt
