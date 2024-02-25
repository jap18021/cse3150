#ifndef _STUDENT_H_
#define _STUDENT_H_

#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

struct student {
  int id;
  string name;
  int fscore;
  int mscore;
  vector<int> hwgrades; 
};

double calculate_grade(const student& s);
student getStudent();
void printStudent(student s);

#endif
