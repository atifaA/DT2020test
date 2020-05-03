# all: exec

# clean:
# 	rm *.o exec

# game.o: game.h game.c
# 	gcc -c game.c

# # %.o: %.c game.h
# # 	gcc -c $<

# exec: game.c game.h game.o print_with_ansi.c print_with_ansi.h
# 	gcc -o exec main.c game.c print_with_ansi.c game.o
# output: game.o main.o print_with_ansi.o
# 	gcc game.o main.o -o output

# main.o: main.c
# 	gcc -c main.c

# game.o: game.c game.h
# 	gcc -c game.c

# print_with_ansi.o:print_with_ansi.h print_with_ansi.c
# 	gcc -c print_with_ansi.c

# clean:
# 	rm *.o output


all:output

output: game
	cc game.c main.c print_with_ansi.c -o output

# doc:
# 	file:///home/nafila/Desktop/DevTech/GameOfLife/html/index.html
# main.o: main.c
# 	gcc -c main.c

# game.o: game.c game.h
# 	gcc -c game.c

# print_with_ansi.o:print_with_ansi.h print_with_ansi.c
# 	gcc -c print_with_ansi.c


clean:
	rm *.o output