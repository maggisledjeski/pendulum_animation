CC = g++
CODE = #-DTOP
CFLAGS = -O
LDLIBS =  -lglut -lGL -lGLU -lm
HEADERS = includes.h prototypes.h
OBJS = init.o reshape.o display.o physics.o step.o keyboard.o

run :   main.o $(OBJS)
	$(CC) $(CFLAGS) main.o $(OBJS) -o run $(LDLIBS)

main.o : main.cpp $(HEADERS)
	$(CC) $(CFLAGS) main.cpp -c

init.o : init.cpp $(HEADERS)
	$(CC) $(CFLAGS) init.cpp -c

reshape.o : reshape.cpp $(HEADERS)
	$(CC) $(CFLAGS) reshape.cpp -c

display.o : display.cpp $(HEADERS)
	$(CC) $(CFLAGS) $(CODE) display.cpp -c

physics.o : physics.cpp $(HEADERS)
	$(CC) $(CFLAGS) physics.cpp -c

step.o : step.cpp $(HEADERS)
	$(CC) $(CFLAGS) step.cpp -c

keyboard.o : keyboard.cpp $(HEADERS)
	$(CC) $(CFLAGS) keyboard.cpp -c

clean:
	rm *.o

pristine:
	rm *.o
	touch *

