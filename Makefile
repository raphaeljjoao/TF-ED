build:
	gcc -c src\estruturas\ABP.c
	gcc -c src\estruturas\LSE.c
	gcc -c src\stats.c
	gcc -c src\analises\ordenada_ABP.c
	gcc -c src\analises\ordenada_LSE.c
	gcc -c main.c
	gcc -o main ABP.o LSE.o stats.o ordenada_ABP.o ordenada_LSE.o main.o
	del ABP.o
	del LSE.o
	del stats.o
	del ordenada_ABP.o
	del ordenada_LSE.o
	del main.o
run:
	.\main.exe
all:
	mingw32-make.exe build
	mingw32-make.exe run