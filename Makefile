CC=gcc
CFLAGS=-g -Wall -O0
LDFLAGS=
RM=rm


all: test_example_E6 test_example_E10

clean:
	$(RM) -f test_example_E6
	$(RM) -f test_example_E10
	$(RM) -f *.o

test_example_E6: test_example_E6.o _test_helper.h
	$(CC) $< $(CFLAGS) $(LDFLAGS) -o $@

test_example_E10: test_example_E10.o _test_helper.h
	$(CC) $< $(CFLAGS) $(LDFLAGS) -o $@

%.o: %.c
	$(CC) -c $< $(CFLAGS) -o $@
