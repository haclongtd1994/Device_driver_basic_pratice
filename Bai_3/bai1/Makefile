build:
	gcc -c -Wall -Werror -fpic foo2.c
	gcc -shared -o libfoo2.so foo2.o
	gcc -L./ -Wl,-rpath=/home/phanthanhhung/bin -Wall -o test main.c -lfoo2