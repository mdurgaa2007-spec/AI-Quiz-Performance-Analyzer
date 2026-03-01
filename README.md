# AI Quiz Performance Analyzer 🧠

An advanced C++ console application that:
- Conducts a quiz
- Analyzes performance
- Stores leaderboard
- Gives intelligent feedback

## Features

- **Interactive Quiz**: Three questions covering general knowledge and technology
- **Real-time Feedback**: Immediate feedback on each answer
- **Performance Analysis**: Scores are categorized as:
  - Excellent Performance 🔥 (80%+)
  - Good Job 👍 (50-79%)
  - Needs Improvement 💪 (<50%)
- **Leaderboard**: All scores are saved to `leaderboard.txt`

## Concepts Used

- Object-Oriented Programming (OOP)
- File Handling
- Vectors
- Conditional Logic

## How to Build and Run

### Prerequisites
- g++ compiler with C++11 support
- Make (optional)

### Compilation

Using Make:
```bash
make
```

Or compile manually:
```bash
g++ -std=c++11 -Wall -o quiz quiz.cpp
```

### Running the Quiz

```bash
./quiz
```

Or with Make:
```bash
make run
```

### Cleaning Build Artifacts

```bash
make clean
```

## Usage

1. Run the program
2. Enter your name when prompted
3. Answer each question by entering a number (1-4)
4. View your score and performance feedback
5. Check `leaderboard.txt` to see all scores

## Example

```
Enter your name: John
What is the capital of India?
1. Mumbai
2. Delhi
3. Chennai
4. Kolkata
Enter your answer: 2
Correct! 🎉
...
Final Score: 3/3
Excellent Performance 🔥
```

Created by Malliha Durgaa 
