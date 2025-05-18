all: src/prog

src/funcoes.o: src/funcoes.c include/funcoes.h src/dados.h
	gcc -c src/funcoes.c -o src/funcoes.o

src/nefasto.o: src/nefasto.c include/nefasto.h src/dados.h
	gcc -c src/nefasto.c -o src/nefasto.o

src/grafo.o: src/grafo.c include/grafo.h src/dados.h
	gcc -c src/grafo.c -o src/grafo.o

lib/biblioteca.a: src/funcoes.o src/nefasto.o src/grafo.o
	ar rcs lib/biblioteca.a src/funcoes.o src/nefasto.o src/grafo.o

src/prog: src/main.c lib/biblioteca.a
	gcc -g src/main.c lib/biblioteca.a -o src/prog

clean:
	del src\*.o src\*.exe lib\Biblioteca.a