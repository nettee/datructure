CFLAGS = -Wall -g

SRCS = $(shell find src/ -name "*.cpp")
OBJS = $(SRCS:.cpp=.o)

TEST_F_FILE = test/friends-1
TEST_A_FILE = test/at-1

weibo: $(OBJS)
	g++ -o weibo $(OBJS) $(CFLAGS) 

#clang:
#	clang++ -o weibo $(CFLAGS) $(SRCS)

run: weibo
	./weibo -f data/newfriends.txt -a data/at.txt 2>&1 | tee log.txt

test: weibo $(TEST_F_FILE)
	-./weibo -f $(TEST_F_FILE) -a $(TEST_A_FILE) 2>&1 | tee log.txt

gdb:
	g++ -o weibo $(SRCS) $(CFLAGS)
	gdb --args ./weibo -f $(TEST_F_FILE) -a $(TEST_A_FILE) 2>&1 | tee log.txt

clean: 
	-rm -f weibo $(OBJS) 2>/dev/null
