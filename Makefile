TARGET = nanoipc
CC = gcc
#CC = cc
INSTALL = install

PREFIX = /usr/local

LIBS = 
INCLUDES = -Iinc -I/usr/include -I/usr/local/include
LIB_DIRS = -L/usr/lib -L/usr/local/lib/
FLAGS = -std=c99 -Os -Wall
LD_FLAGS = -std=c99 -Os -Wall -lm -lpthread -lnanomsg

OBJECTS := server.o
SOURCES := src/server.c

$(TARGET): $(OBJECTS) 
	$(CC)  $< $(LD_FLAGS) $(DEFINES) $(INCLUDES) $(LIB_DIRS) $(LIBS) -o $@
	strip $@

$(OBJECTS): $(SOURCES) 
	$(CC) $(FLAGS) $(DEFINES) $(INCLUDES) -c -o $@ $<

clean:
	rm -rf $(TARGET) $(OBJECTS)

install: $(TARGET) $(MAN)
	$(INSTALL) -o root -g root -m 0755 $(TARGET) $(PREFIX)/bin

uninstall:
	rm -f $(PREFIX)/bin/$(TARGET)
