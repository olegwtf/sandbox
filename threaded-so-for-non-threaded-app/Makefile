all:
	cc -pthread -g -fPIC -c mylib.c
	cc -pthread -g -shared -o libmy.so mylib.o
	cc -g -o main main.c -ldl

clean:
	rm *.o *.so main
