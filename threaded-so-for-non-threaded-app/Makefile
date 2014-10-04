all:
	cc -pthread -fPIC -c mylib.c
	cc -pthread -shared -o libmy.so mylib.o
	cc -o main main.c -ldl

clean:
	rm *.o *.so main
