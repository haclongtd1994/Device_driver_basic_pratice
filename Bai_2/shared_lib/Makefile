all:
	gcc -c -Wall -Werror -fpic foo.c
	gcc -shared -o libfoo.so foo.o
	gcc -L./ -Wl,-rpath=/usr/bin -Wall -o test main.c -lfoo