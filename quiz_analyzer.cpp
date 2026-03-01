#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <ctime>

using namespace std;

// Question class to represent a multiple-choice question
class Question {
private:
    string questionText;
    vector<string> options;
    int correctAnswer;

public:
    Question(string text, vector<string> opts, int correct) 
        : questionText(text), options(opts), correctAnswer(correct) {}

    void display(int questionNumber) const {
        cout << "\n" << questionNumber << ". " << questionText << endl;
        for (size_t i = 0; i < options.size(); i++) {
            cout << "   " << (i + 1) << ") " << options[i] << endl;
        }
    }

    bool checkAnswer(int userAnswer) const {
        return userAnswer == correctAnswer;
    }

    int getCorrectAnswer() const {
        return correctAnswer;
    }
};

// User class to store user information
class User {
private:
    string name;
    int score;
    double percentage;
    time_t timestamp;

public:
    User(string n = "", int s = 0, double p = 0.0) 
        : name(n), score(s), percentage(p) {
        timestamp = time(0);
    }

    string getName() const { return name; }
    int getScore() const { return score; }
    double getPercentage() const { return percentage; }
    time_t getTimestamp() const { return timestamp; }

    void setName(string n) { name = n; }
    void setScore(int s) { score = s; }
    void setPercentage(double p) { percentage = p; }
};

// Quiz class to manage the quiz
class Quiz {
private:
    vector<Question> questions;
    int totalQuestions;

public:
    Quiz() : totalQuestions(0) {}

    void addQuestion(const Question& q) {
        questions.push_back(q);
        totalQuestions++;
    }

    int conductQuiz(User& user) {
        int score = 0;
        cout << "\n========================================" << endl;
        cout << "   STARTING QUIZ - Total Questions: " << totalQuestions << endl;
        cout << "========================================" << endl;

        for (size_t i = 0; i < questions.size(); i++) {
            questions[i].display(i + 1);
            
            int userAnswer;
            cout << "\nYour answer (1-4): ";
            cin >> userAnswer;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid input! Marking as incorrect." << endl;
                userAnswer = -1;
            }

            if (questions[i].checkAnswer(userAnswer)) {
                cout << "✓ Correct!" << endl;
                score++;
            } else {
                cout << "✗ Incorrect! The correct answer was: " 
                     << questions[i].getCorrectAnswer() << endl;
            }
        }

        user.setScore(score);
        double percentage = (static_cast<double>(score) / totalQuestions) * 100.0;
        user.setPercentage(percentage);

        return score;
    }

    int getTotalQuestions() const {
        return totalQuestions;
    }
};

// Leaderboard class for file handling and ranking
class Leaderboard {
private:
    string filename;
    vector<User> users;

public:
    Leaderboard(string file = "leaderboard.txt") : filename(file) {}

    void addUser(const User& user) {
        users.push_back(user);
        saveToFile(user);
    }

    void saveToFile(const User& user) {
        ofstream file(filename, ios::app);
        if (file.is_open()) {
            file << user.getName() << "," 
                 << user.getScore() << "," 
                 << fixed << setprecision(2) << user.getPercentage() << ","
                 << user.getTimestamp() << endl;
            file.close();
        } else {
            cout << "Error: Unable to save to leaderboard file!" << endl;
        }
    }

    void loadFromFile() {
        users.clear();
        ifstream file(filename);
        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                size_t pos1 = line.find(',');
                size_t pos2 = line.find(',', pos1 + 1);
                size_t pos3 = line.find(',', pos2 + 1);

                if (pos1 != string::npos && pos2 != string::npos) {
                    string name = line.substr(0, pos1);
                    int score = stoi(line.substr(pos1 + 1, pos2 - pos1 - 1));
                    double percentage = stod(line.substr(pos2 + 1, pos3 - pos2 - 1));

                    User user(name, score, percentage);
                    users.push_back(user);
                }
            }
            file.close();
            
            // Sort users by percentage in descending order after loading
            sort(users.begin(), users.end(), [](const User& a, const User& b) {
                return a.getPercentage() > b.getPercentage();
            });
        }
    }

    void display() {
        loadFromFile();
        
        if (users.empty()) {
            cout << "\nNo leaderboard data available yet!" << endl;
            return;
        }

        cout << "\n========================================" << endl;
        cout << "          LEADERBOARD" << endl;
        cout << "========================================" << endl;
        cout << left << setw(20) << "Name" 
             << setw(10) << "Score" 
             << setw(15) << "Percentage" << endl;
        cout << "----------------------------------------" << endl;

        for (size_t i = 0; i < users.size() && i < 10; i++) {
            cout << left << setw(20) << users[i].getName()
                 << setw(10) << users[i].getScore()
                 << fixed << setprecision(2) << setw(15) 
                 << users[i].getPercentage() << "%" << endl;
        }
        cout << "========================================" << endl;
    }
};

// AI Feedback Analyzer class
class FeedbackAnalyzer {
public:
    static void provideFeedback(const User& user, int totalQuestions) {
        double percentage = user.getPercentage();
        
        cout << "\n========================================" << endl;
        cout << "       PERFORMANCE ANALYSIS" << endl;
        cout << "========================================" << endl;
        cout << "Player: " << user.getName() << endl;
        cout << "Score: " << user.getScore() << "/" << totalQuestions << endl;
        cout << "Percentage: " << fixed << setprecision(2) 
             << percentage << "%" << endl;
        cout << "----------------------------------------" << endl;
        
        cout << "\n🤖 AI FEEDBACK:" << endl;
        
        if (percentage >= 90.0) {
            cout << "⭐ EXCELLENT! Outstanding performance!" << endl;
            cout << "You have demonstrated exceptional mastery of the subject." << endl;
            cout << "Keep up the brilliant work! You're a star performer!" << endl;
            cout << "Grade: A+" << endl;
        } else if (percentage >= 75.0) {
            cout << "👍 GREAT JOB! Very good performance!" << endl;
            cout << "You have a strong understanding of the material." << endl;
            cout << "With a bit more practice, you can achieve excellence!" << endl;
            cout << "Grade: A" << endl;
        } else if (percentage >= 60.0) {
            cout << "✓ GOOD! Decent performance!" << endl;
            cout << "You have a fair grasp of the concepts." << endl;
            cout << "Review the topics you missed and practice more." << endl;
            cout << "You're on the right track - keep improving!" << endl;
            cout << "Grade: B" << endl;
        } else if (percentage >= 50.0) {
            cout << "⚠ AVERAGE. Room for improvement!" << endl;
            cout << "You need to strengthen your understanding." << endl;
            cout << "Recommendation: Study the material more thoroughly." << endl;
            cout << "Focus on areas where you made mistakes." << endl;
            cout << "Grade: C" << endl;
        } else {
            cout << "❌ NEEDS IMPROVEMENT. Don't give up!" << endl;
            cout << "This subject requires more attention and study." << endl;
            cout << "Recommendation: Review all concepts systematically." << endl;
            cout << "Consider seeking additional help or resources." << endl;
            cout << "Remember: Every expert was once a beginner!" << endl;
            cout << "Grade: D" << endl;
        }
        
        cout << "\n📊 PERFORMANCE INSIGHTS:" << endl;
        int correctAnswers = user.getScore();
        int incorrectAnswers = totalQuestions - correctAnswers;
        
        cout << "- Correct Answers: " << correctAnswers << endl;
        cout << "- Incorrect Answers: " << incorrectAnswers << endl;
        cout << "- Accuracy Rate: " << fixed << setprecision(1) 
             << percentage << "%" << endl;
        
        if (percentage < 100.0) {
            double improvement = 100.0 - percentage;
            cout << "- Potential for Improvement: " << fixed << setprecision(1) 
                 << improvement << "%" << endl;
        }
        
        cout << "========================================" << endl;
    }
};

// Function to initialize quiz with sample questions
void initializeQuiz(Quiz& quiz) {
    // Add 10 sample questions about general knowledge and programming
    quiz.addQuestion(Question(
        "What does CPU stand for?",
        {"Central Processing Unit", "Computer Personal Unit", 
         "Central Processor Unit", "Computer Processing Unit"},
        1
    ));

    quiz.addQuestion(Question(
        "Which programming language is known as the 'mother of all languages'?",
        {"Python", "C", "Assembly", "FORTRAN"},
        2
    ));

    quiz.addQuestion(Question(
        "What is the time complexity of binary search?",
        {"O(n)", "O(log n)", "O(n^2)", "O(1)"},
        2
    ));

    quiz.addQuestion(Question(
        "Which data structure uses LIFO (Last In First Out)?",
        {"Queue", "Stack", "Array", "Linked List"},
        2
    ));

    quiz.addQuestion(Question(
        "What does OOP stand for in programming?",
        {"Object Oriented Programming", "Operator Overloading Principle",
         "Open Output Protocol", "Object Operation Process"},
        1
    ));

    quiz.addQuestion(Question(
        "Which of the following is NOT a valid C++ loop?",
        {"for loop", "while loop", "do-while loop", "repeat-until loop"},
        4
    ));

    quiz.addQuestion(Question(
        "What is the size of 'int' data type in C++ (typically)?",
        {"2 bytes", "4 bytes", "8 bytes", "1 byte"},
        2
    ));

    quiz.addQuestion(Question(
        "Which operator is used for dynamic memory allocation in C++?",
        {"malloc", "new", "alloc", "create"},
        2
    ));

    quiz.addQuestion(Question(
        "What is inheritance in OOP?",
        {"Hiding implementation details", "Creating objects from classes",
         "Acquiring properties from parent class", "Overloading functions"},
        3
    ));

    quiz.addQuestion(Question(
        "Which header file is required for file handling in C++?",
        {"<iostream>", "<fstream>", "<fileio>", "<stdio.h>"},
        2
    ));
}

// Main function
int main() {
    cout << "\n╔════════════════════════════════════════╗" << endl;
    cout << "║  AI QUIZ PERFORMANCE ANALYZER 🧠       ║" << endl;
    cout << "║  Intelligent Assessment System         ║" << endl;
    cout << "╚════════════════════════════════════════╝" << endl;

    Quiz quiz;
    Leaderboard leaderboard;
    
    // Initialize quiz with questions
    initializeQuiz(quiz);

    int choice;
    do {
        cout << "\n========== MAIN MENU ==========" << endl;
        cout << "1. Take Quiz" << endl;
        cout << "2. View Leaderboard" << endl;
        cout << "3. Exit" << endl;
        cout << "===============================" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input! Please enter a number." << endl;
            continue;
        }

        switch (choice) {
            case 1: {
                cin.ignore(); // Clear newline for getline
                string userName;
                cout << "\nEnter your name: ";
                getline(cin, userName);

                if (userName.empty()) {
                    userName = "Anonymous";
                }

                User user;
                user.setName(userName);

                cout << "\nWelcome, " << userName << "! Get ready for the quiz." << endl;
                cout << "Answer each question by entering the option number (1-4)." << endl;
                cout << "\nPress Enter to start...";
                cin.get();

                quiz.conductQuiz(user);

                // Provide AI-based feedback
                FeedbackAnalyzer::provideFeedback(user, quiz.getTotalQuestions());

                // Add to leaderboard
                leaderboard.addUser(user);

                cout << "\nYour score has been saved to the leaderboard!" << endl;
                break;
            }
            case 2:
                leaderboard.display();
                break;
            case 3:
                cout << "\n👋 Thank you for using AI Quiz Performance Analyzer!" << endl;
                cout << "Keep learning and improving! 🚀" << endl;
                break;
            default:
                cout << "\n❌ Invalid choice! Please select 1, 2, or 3." << endl;
        }
    } while (choice != 3);

    return 0;
}
