all: newshell clean

newshell: main.o interMode.o bash2.o CD.o
		gcc -o newshell main.o interMode.o bash2.o CD.o

main.o: functions.h
		gcc -c main.c

interMode.o: functions.h
		gcc -c interMode.c

bash2.o: functions.h
		gcc -c bash2.c

CD.o: functions.h
		gcc -c CD.c
		
clean:
		rm *.o
