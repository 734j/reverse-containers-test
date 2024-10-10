CC=g++
CFLAGS_TESTBIN=-O0 -Wfatal-errors -Wall -Werror -Wextra -g3 -fsanitize=address -fsanitize=leak -Wpedantic -Wformat=2 -Wshadow -Wformat-truncation=2 -Wformat-overflow -fno-common -std=c++20
CFLAGS=-O3 -flto -march=native -DNDEBUG -fomit-frame-pointer -s -static -std=c++20
TARGET=reverse
TESTTARGET=reverse-TESTING
MAKEFLAGS += 
SRCS=reverse-containers.cpp

all: release tests
clean:
	rm -f $(TARGET)
	rm -f $(TESTTARGET)

tests:
	$(CC) $(CFLAGS_TESTBIN) $(SRCS) -o $(TESTTARGET)

release:
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)
