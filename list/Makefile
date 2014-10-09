# setting compile options
CFLAGS = -ggdb -Wall -Werror

slist: utest_slist.o
	g++ -o slist.out $(CFLAGS) utest_slist.cpp

dlist: utest_dlist.o
	g++ -o dlist.out $(CFLAGS) utest_dlist.cpp

vlist: utest_vlist.o
	g++ -o vlist.out $(CFLAGS) utest_vlist.cpp

clean:
	\rm -f *.o
