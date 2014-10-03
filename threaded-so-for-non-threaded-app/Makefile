all:
	cc -fPIC -c mylib.c
	cc -lpthread -shared -o libmy.so mylib.o
	cc -o main main.c -ldl
	
clean:
	rm *.o *.so main
