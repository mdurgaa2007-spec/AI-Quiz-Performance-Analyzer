# Makefile for AI Quiz Performance Analyzer

CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
TARGET = quiz_analyzer
SOURCE = quiz_analyzer.cpp

all: $(TARGET)

$(TARGET): $(SOURCE)
	$(CXX) $(CXXFLAGS) $(SOURCE) -o $(TARGET)

clean:
	rm -f $(TARGET) leaderboard.txt

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
