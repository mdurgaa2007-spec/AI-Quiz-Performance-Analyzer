# Makefile for AI Quiz Performance Analyzer

CXX = g++
CXXFLAGS = -std=c++11 -Wall
TARGET = quiz
SOURCE = quiz.cpp

all: $(TARGET)

$(TARGET): $(SOURCE)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCE)

clean:
	rm -f $(TARGET) *.o leaderboard.txt

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
