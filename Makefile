#
# Makefile
#
# Targets:
#   all
#       The default target, if not target is specified. Compiles source files
#       as necessary and links them into the final executable.
#   clean
#       Removes all object files and executables.
# Variables:
#   CC
#       The C compiler to use. Defaults to gcc.
#   CFLAGS
#       Flags to pass to the C compiler. Defaults to -I/usr/include.
#   debug=1
#       Build with debug info
#   LDFLAGS
#       Flags to pass to the linker. Defaults to -L/usr/lib.
#

ifeq ($(CC),)
CC=gcc
endif
CFGLAGS += -I/usr/include
LDFLAGS += -L/usr/lib
ifdef debug
CFLAGS += -ggdb -D DEBUG
LDFLAGS += -v
else
CFLAGS += -O3 -flto
LDFLAGS += -flto
endif

OBJS = main.o sort.o

.PHONY: all clean

all: clean sort

sort: main.o $(OBJS)
	$(CC) $(LDFLAGS) $^ -o $@
ifndef debug
	strip $@
endif

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	- rm -f test
	- rm -f *.o
	- rm -f *.map
