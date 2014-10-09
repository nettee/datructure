# setting compiling options
CFLAGS = -ggdb -Wall -Werror -I../include

slist: utest-slist.cpp
	g++ -o slist.out $(CFLAGS) utest-slist.cpp
dlist: utest-dlist.cpp
	g++ -o dlist.out $(CFLAGS) utest-dlist.cpp
vlist: utest-vlist.cpp
	g++ -o vlist.out $(CFLAGS) utest-vlist.cpp

vstack: utest-vstack.cpp
	g++ -o vstack.out $(CFLAGS) utest-vstack.cpp
lstack: utest-lstack.cpp
	g++ -o lstack.out $(CFLAGS) utest-lstack.cpp

lqueue: utest-lqueue.cpp
	g++ -o lqueue.out $(CFLAGS) utest-lqueue.cpp

clean:
	\rm *.out
