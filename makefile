all: src/prog

src/funcoes.o: src/funcoes.c src/funcoes.h src/dados.h
	gcc -c src/funcoes.c -o src/funcoes.o

src/prog: src/main.c src/funcoes.o
	gcc -g src/main.c src/funcoes.o -o src/prog

clean:
	del src\*.o src\*.exe