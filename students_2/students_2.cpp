#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <numeric>

using namespace std;

class Student {
private:
    string name;
    map<string, vector<int>> grades;

public:
    Student(const string& name) : name(name) {}

    void addGrade(const string& subject, int grade) {
        grades[subject].push_back(grade);
    }

    const string& getName() const {
        return name;
    }

    const map<string, vector<int>>& getGrades() const {
        return grades;
    }

    ~Student() {
        grades.clear();
    }
};

class Gradebook {
private:
    vector<Student> students;

public:
    void addStudent(const Student& student) {
        students.push_back(student);
    }

    void calculateAverageGrades() const {
        for (const auto& student : students) {
            cout << "Student: " << student.getName() << endl;
            for (const auto& subject : student.getGrades()) {
                double average = accumulate(subject.second.begin(), subject.second.end(), 0.0) / subject.second.size();
                cout << "Subject: " << subject.first << ", Average Grade: " << average << endl;
            }
            cout << endl;
        }
    }
};

int main() {
    Gradebook gradebook;
    int numStudents;

    cout << "Enter number of students: ";
    cin >> numStudents;

    for (int i = 0; i < numStudents; ++i) {
        string name;
        cout << "Enter name of student " << i + 1 << ": ";
        cin >> name;

        Student student(name);
        int numSubjects;

        cout << "Enter number of subjects for " << name << ": ";
        cin >> numSubjects;

        for (int j = 0; j < numSubjects; ++j) {
            string subject;
            int numGrades;

            cout << "Enter subject name: ";
            cin >> subject;

            cout << "Enter number of grades for " << subject << ": ";
            cin >> numGrades;

            for (int k = 0; k < numGrades; ++k) {
                int grade;
                cout << "Enter grade " << k + 1 << ": ";
                cin >> grade;
                student.addGrade(subject, grade);
            }
        }

        gradebook.addStudent(student);
    }

    gradebook.calculateAverageGrades();

    return 0;
}

