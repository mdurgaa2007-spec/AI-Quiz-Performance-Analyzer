#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Question {
public:
    string question;
    string option1, option2, option3, option4;
    int correctOption;

    void display() {
        cout << "\n" << question << endl;
        cout << "1. " << option1 << endl;
        cout << "2. " << option2 << endl;
        cout << "3. " << option3 << endl;
        cout << "4. " << option4 << endl;
    }
};

class Quiz {
    vector<Question> questions;
    int score = 0;

public:
    void addQuestion(const string& q, const string& o1, const string& o2, const string& o3, const string& o4, int correct) {
        Question ques;
        ques.question = q;
        ques.option1 = o1;
        ques.option2 = o2;
        ques.option3 = o3;
        ques.option4 = o4;
        ques.correctOption = correct;
        questions.push_back(ques);
    }

    void startQuiz(const string& username) {
        int answer;

        for (size_t i = 0; i < questions.size(); i++) {
            questions[i].display();
            cout << "Enter your answer: ";
            cin >> answer;

            // Validate input
            if (cin.fail() || answer < 1 || answer > 4) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid input! Skipping this question.\n";
                continue;
            }

            if (answer == questions[i].correctOption) {
                cout << "Correct! 🎉\n";
                score++;
            } else {
                cout << "Wrong ❌\n";
            }
        }

        cout << "\nFinal Score: " << score << "/" << questions.size() << endl;
        giveFeedback();

        saveToFile(username);
    }

    void giveFeedback() {
        float percentage = (score * 100.0) / questions.size();

        if (percentage >= 80)
            cout << "Excellent Performance 🔥\n";
        else if (percentage >= 50)
            cout << "Good Job 👍 Keep Improving!\n";
        else
            cout << "Needs Improvement 💪 Practice More!\n";
    }

    void saveToFile(const string& username) {
        ofstream file("leaderboard.txt", ios::app);
        if (!file.is_open()) {
            cerr << "Error: Unable to save score to leaderboard.\n";
            return;
        }
        file << username << " - Score: " << score << endl;
        file.close();
    }
};

int main() {
    string name;
    cout << "Enter your name: ";
    cin >> name;

    Quiz quiz;

    quiz.addQuestion("What is the capital of India?",
                     "Mumbai", "Delhi", "Chennai", "Kolkata", 2);

    quiz.addQuestion("Which language is used for AI?",
                     "C", "Python", "HTML", "CSS", 2);

    quiz.addQuestion("What does CPU stand for?",
                     "Central Processing Unit",
                     "Computer Personal Unit",
                     "Central Program Utility",
                     "Control Processing Unit", 1);

    quiz.startQuiz(name);

    return 0;
}
