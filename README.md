# AI Quiz Performance Analyzer 🧠

An advanced C++ console application that conducts quizzes, analyzes performance, stores results in a leaderboard, and provides intelligent AI-based feedback.

## Features

✨ **Core Features:**
- **Multiple-Choice Questions**: Interactive quiz with 10 questions on programming and computer science
- **Score Calculation**: Automatic calculation of score and percentage
- **Performance Analysis**: Detailed analysis of user performance with accuracy metrics
- **Intelligent AI Feedback**: Context-aware feedback based on performance levels:
  - 90%+ : Excellent (Grade A+)
  - 75-89%: Great Job (Grade A)
  - 60-74%: Good (Grade B)
  - 50-59%: Average (Grade C)
  - <50%: Needs Improvement (Grade D)
- **Leaderboard System**: File-based persistent storage of all quiz attempts
- **Sorted Rankings**: Leaderboard displays top performers sorted by percentage

## Concepts Used

- **Object-Oriented Programming (OOP)**: 
  - Question class
  - Quiz class
  - User class
  - Leaderboard class
  - FeedbackAnalyzer class
- **File Handling**: Reading and writing leaderboard data to text file
- **Vectors**: Dynamic array management for questions and users
- **Conditional Logic**: AI-based feedback system with performance thresholds
- **String Processing**: CSV-based data storage and retrieval
- **Sorting Algorithms**: Leaderboard ranking system

## Compilation and Usage

### Prerequisites
- C++ compiler with C++11 support (g++, clang++, etc.)
- Make (optional, for using Makefile)

### Compilation Options

**Using Make:**
```bash
make
```

**Using g++ directly:**
```bash
g++ -std=c++11 -Wall -Wextra quiz_analyzer.cpp -o quiz_analyzer
```

### Running the Application

```bash
./quiz_analyzer
```

Or with Make:
```bash
make run
```

### Cleaning Build Files

```bash
make clean
```

## How to Use

1. **Start the application**: Run `./quiz_analyzer`
2. **Main Menu Options**:
   - **Option 1 - Take Quiz**: 
     - Enter your name
     - Answer 10 multiple-choice questions (enter 1-4)
     - Get instant feedback for each answer
     - View your performance analysis and AI feedback
     - Your score is automatically saved to the leaderboard
   - **Option 2 - View Leaderboard**: 
     - See top performers sorted by percentage
     - View scores and percentages of all participants
   - **Option 3 - Exit**: Close the application

## Sample Output

```
╔════════════════════════════════════════╗
║  AI QUIZ PERFORMANCE ANALYZER 🧠       ║
║  Intelligent Assessment System         ║
╚════════════════════════════════════════╝

========================================
       PERFORMANCE ANALYSIS
========================================
Player: John Doe
Score: 9/10
Percentage: 90.00%
----------------------------------------

🤖 AI FEEDBACK:
⭐ EXCELLENT! Outstanding performance!
You have demonstrated exceptional mastery of the subject.
Keep up the brilliant work! You're a star performer!
Grade: A+

📊 PERFORMANCE INSIGHTS:
- Correct Answers: 9
- Incorrect Answers: 1
- Accuracy Rate: 90.0%
- Potential for Improvement: 10.0%
========================================
```

## File Structure

```
AI-Quiz-Performance-Analyzer/
├── quiz_analyzer.cpp    # Main application source code
├── Makefile            # Build automation
├── README.md           # This file
├── .gitignore          # Git ignore rules
└── leaderboard.txt     # Generated: Stores quiz results (created automatically)
```

## Leaderboard File Format

The leaderboard data is stored in CSV format:
```
Name,Score,Percentage,Timestamp
John Doe,9,90.00,1772350522
```

## Technical Details

- **Language**: C++11
- **Compiler**: g++ (GCC)
- **Standard Library**: iostream, string, vector, fstream, iomanip, algorithm, ctime
- **File I/O**: Text-based file handling with CSV format
- **Data Structures**: Vectors for dynamic arrays, Classes for OOP design

## Future Enhancements

- Add more questions with difficulty levels
- Implement question categories
- Add timer for each question
- Export results to PDF
- Add graphical user interface (GUI)
- Database integration for better data management

## Author

Created by Malliha Durgaa

## License

This project is open source and available for educational purposes.
