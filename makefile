all: src/prog lib/biblioteca.a

lib/biblioteca.a: src/funcoes.o src/nefasto.o src/grafo.o
	ar rcs lib/biblioteca.a src/funcoes.o src/nefasto.o src/grafo.o

src/funcoes.o: src/funcoes.c include/funcoes.h
	gcc -c src/funcoes.c -o src/funcoes.o

src/nefasto.o: src/nefasto.c include/nefasto.h
	gcc -c src/nefasto.c -o src/nefasto.o

src/grafo.o: src/grafo.c include/grafo.h
	gcc -c src/grafo.c -o src/grafo.o

src/prog: src/main.c lib/biblioteca.a
	gcc -g src/main.c lib/biblioteca.a -o src/prog

run: src/prog
	./src/prog

clean:
	rm -f src/*.o src/*.exe lib/biblioteca.a
	rm -rf docs/doxygen/html docs/doxygen/latex