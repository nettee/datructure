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

polynomial: polynomial.o utest_polynomial.o
	g++ polynomial.o utest_polynomial.o

polynomial-d: polynomial.cpp utest_polynomial.cpp
	g++ -g polynomial.cpp utest_polynomial.cpp

polynomial.o: polynomial.cpp
	g++ -c polynomial.cpp
utest_polynomial.o: utest_polynomial.cpp
	g++ -c utest_polynomial.cpp

polynomial-c:
	clang++ polynomial.cpp utest_polynomial.cpp

