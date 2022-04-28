build:
	gcc -c src\arvores\ABP.c
	gcc -c src\arvores\AVL.c
	gcc -c src\utils.c
	gcc -c src\stats.c
	gcc -c src\analises\ordenada_ABP.c
	gcc -c main.c
	gcc -o main ABP.o AVL.o utils.o stats.o ordenada_ABP.o main.o
	del ABP.o
	del AVL.o
	del utils.o
	del stats.o
	del ordenada_ABP.o
	del main.o
run:
	.\main.exe
all:
	mingw32-make.exe build
	mingw32-make.exe run