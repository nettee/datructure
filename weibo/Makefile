CFLAGS = -Wall -I./include -ggdb

SRCS = $(shell find src/ -name "*.cpp")
OBJS = $(SRCS:.cpp=.o)

weibo: $(OBJS)
	g++ -o weibo $(OBJS) $(CFLAGS)

run: weibo
	./weibo

clean: 
	-rm -f weibo $(OBJS) 2>/dev/null
