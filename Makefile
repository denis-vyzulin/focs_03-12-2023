build: main.out utils.out
	gcc main.out utils.out -o app.exe
main.out: main.c
	gcc -c main.c -o main.out
utils.out: utils.c
	gcc -c utils.c -o utils.out