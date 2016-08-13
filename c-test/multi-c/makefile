mainOS= implhome.o implname.o
main.e: $(mainOS)
	gcc main.c -o main.e $(mainOS)
implname.o: \
implname.c \
def.h
	gcc -c implname.c
implhome.o: \
implhome.c \
def.h
	gcc -c implhome.c

clean:
	rm *.o
	rm *.e
