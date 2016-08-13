main.e: \
implhome.o \
implname.o
	gcc main.c -o main.e implhome.o implname.o
implname.o: \
implname.c \
def.h
	gcc -c implname.c
implhome.o: \
implhome.c \
def.h
	gcc -c implhome.c

