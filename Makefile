all : COMPIL EXEC CLEAN


.SILENT: *
menu.o : menu.c
	gcc -c menu.c `sdl-config --cflags --libs` -lSDL_mixer -lSDL_ttf -lSDL_image
map.o :  map.c
	gcc -c map.c `sdl-config --cflags --libs` -lSDL_mixer -lSDL_ttf -lSDL_image
perso.o : perso.c
	gcc -c perso.c `sdl-config --cflags --libs` -lSDL_mixer -lSDL_ttf -lSDL_image
game.o : game.c
	gcc -c game.c `sdl-config --cflags --libs` -lSDL_mixer -lSDL_ttf -lSDL_image
main.o : main.c
	gcc -c main.c `sdl-config --cflags --libs` -lSDL_mixer -lSDL_ttf -lSDL_image
combat.o : combat.c
	gcc -c combat.c `sdl-config --cflags --libs` -lSDL_mixer -lSDL_ttf -lSDL_image
son.o : son.c
		gcc -c son.c `sdl-config --cflags --libs` -lSDL_mixer -lSDL_ttf -lSDL_image
COMPIL : menu.o map.o perso.o game.o main.o combat.o son.o
	gcc -o PST main.c `sdl-config --cflags --libs` -lSDL_mixer -lSDL_ttf -lSDL_image
EXEC :
	./PST
CLEAN:
	rm *.o
