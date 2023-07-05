CC = g++
CFLAGS = -std=c++11 -Wall

TARGET = benchmark
SRCS = benchmark.cpp functions.cpp
DEPS = functions.h
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET) *.csv
