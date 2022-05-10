build:
	gcc -c src\estruturas\ABP.c
	gcc -c src\estruturas\LSE.c
	gcc -c src\utils.c
	gcc -c src\analises\ordenada_ABP.c
	gcc -c src\analises\aleatoria_ABP.c
	gcc -c src\analises\ordenada_LSE.c
	gcc -c src\analises\aleatoria_LSE.c
	gcc -c main.c
	gcc -o main ABP.o LSE.o utils.o ordenada_ABP.o aleatoria_ABP.o ordenada_LSE.o aleatoria_LSE.o main.o
	del ABP.o
	del LSE.o
	del utils.o
	del ordenada_ABP.o
	del aleatoria_ABP.o
	del ordenada_LSE.o
	del aleatoria_LSE.o
	del main.o
run:
	.\main.exe
all:
	mingw32-make.exe build
	mingw32-make.exe run