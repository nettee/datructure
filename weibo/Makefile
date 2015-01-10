CFLAGS = -Wall -I include -ggdb

SRCS = $(shell find src/ -name "*.cpp")
OBJS = $(SRCS:.cpp=.o)

weibo: $(OBJS)
	g++ -o weibo $(OBJS) $(CFLAGS) 

run: weibo
	./weibo -f data/newfriends.txt -a data/at.txt 2>&1 | tee log.txt

test: weibo
	./weibo -f test/friends.txt -a test/at.txt 2>&1 | tee log.txt

gdb:
	g++ -o weibo $(SRCS) $(CFLAGS)
	gdb --args ./weibo -f test/friends.txt -a test/at.txt 2>&1 | tee log.txt

clean: 
	-rm -f weibo $(OBJS) 2>/dev/null
