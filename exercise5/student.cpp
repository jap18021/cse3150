#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "student.h"

using namespace std;

double calculate_grade(const student& s) {
    double tscore = 0.3 * s.mscore + 0.3 * s.fscore;
    double hwscore = 0;
    for (int grade : s.hwgrades) {
        hwscore += grade;
    }
    tscore += 0.4 * (hwscore / s.hwgrades.size());
    return tscore;
}

student getStudent() {
    student s;
    cout << "Enter student ID: ";
    cin >> s.id;

    cout << "Enter student name: ";
    cin.ignore();
    getline(cin, s.name);

    cout << "Enter final exam score: ";
    cin >> s.fscore;

    cout << "Enter midterm exam score: ";
    cin >> s.mscore;

    cout << "Enter homework grades (enter -1 to stop):\n";
    int grade;
    while (true) {
        cin >> grade;
        if (grade == -1) {
            break;
        }
        s.hwgrades.push_back(grade);
    }

    return s;
}

void printStudent(student s) {
    cout << "Student ID: " << s.id << endl;
    cout << "Student Name: " << s.name << endl;
    cout << "Final Exam Score: " << s.fscore << endl;
    cout << "Midterm Exam Score: " << s.mscore << endl;
    cout << "Homework Grades: ";
    for (int grade : s.hwgrades) {
        cout << grade << " ";
    }
    cout << endl;
    cout << "Total Class Score: " << calculate_grade(s) << endl;
}
