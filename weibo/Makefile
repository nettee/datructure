CFLAGS = -Wall -I include -ggdb

SRCS = $(shell find src/ -name "*.cpp")
OBJS = $(SRCS:.cpp=.o)

weibo: $(OBJS)
	g++ -o weibo $(OBJS) $(CFLAGS) 

run: weibo
	./weibo -f test/newfriends.txt -a test/at.txt 2>&1 | tee log.txt

gdb:
	g++ -o weibo $(SRCS) $(CFLAGS)
	gdb --args ./weibo

clean: 
	-rm -f weibo $(OBJS) 2>/dev/null
