
CFLAGS = -Wall -pedantic -Werror
LFLAGS = `sdl-config --libs` -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf
OBJS   =   enigme.o   Enigme.o  puzzle.o menu_puzzle.o image.o display.o  file_rw.o    xo.o  chrono.o        animation.o audio.o cinematique.o draw.o  hero.o init.o input.o  minimap.o  instruction.o logo.o  main.o menu.o  monstre.o options.o quit.o sound.o vie_score.o   

PROG = jeu
CXX = gcc

# top-level rule to create the program.
all: $(PROG)

# compiling other source files.
%.o: %.c %.h defs.h structs.h
	$(CXX) $(CFLAGS) -c -s $<

# linking the program.
$(PROG): $(OBJS)
	$(CXX) $(OBJS) -o $(PROG) $(LFLAGS)

# cleaning everything that can be automatically recreated with "make".
clean:
	rm $(PROG) *.o
