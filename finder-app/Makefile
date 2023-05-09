#使用默认编译器，接受指定编译器
CC := $(CROSS_COMPILE)gcc
CFLAGS := -Wall -Wextra

writer: writer.o
	$(CC) $(CFLAGS) $< -o $@

writer.o: writer.c
	$(CC) $(CFLAGS) -c $< -o $@

# 清理目标
clean:
	rm -f writer writer.o
