slist: slist.o utest_slist.o
	g++ slist.o utest_slist.o

slist-d: slist.cpp utest_slist.cpp
	g++ -g slist.cpp utest_slist.cpp

slist.o: slist.cpp
	g++ -c slist.cpp
utest_slist.o: utest_slist.cpp
	g++ -c utest_slist.cpp

slist-c:
	clang++ slist.cpp utest_slist.cpp

