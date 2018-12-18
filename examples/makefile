CC=g++
CFLAGS_OMP= -I../mojo/ -std=c++11 -O3 -DMOJO_AVX -msse4 -mavx # -fopenmp -DMOJO_OMP 

all: test train_mnist train_cifar

test: test.cpp 
	$(CC) $(CFLAGS_OMP) test.cpp -o test

train_mnist: train_mnist.cpp
	$(CC) $(CFLAGS_OMP) train_mnist.cpp -o train_mnist

train_cifar: train_cifar.cpp 
	$(CC) $(CFLAGS_OMP) train_cifar.cpp -o train_cifar

clean:
	-rm -f test
	-rm -f train_mnist
	-rm -f train_cifar
