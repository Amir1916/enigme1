CC = gcc
CFLAGS = -Wall -Wno-switch -I. -O2 -g
LDFLAGS = -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf

prog: main.o source.o
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f *.o prog