#include <iostream>  
#include <iomanip>  
#include <string>  
#include <vector>  

using namespace std;
 
class Course {
public:
    string name;
    int credits;
    float gradePoint;

    Course(string n, int c, float g) : name(n), credits(c), gradePoint(g) {}
};
 
class Student {
private:
    vector<Course> courses;
    float totalGradePoints;
    int totalCredits;

public:
    Student() : totalGradePoints(0), totalCredits(0) {}
 
    void addCourse(string name, int credits, float gradePoint) {
        if (credits <= 0) {
            cout << "Credits must be greater than 0!\n";
            return;
        }
        if (gradePoint < 0 || gradePoint > 10) { 
            cout << "Grade point must be between 0 and 10!\n";
            return;
        }

        courses.emplace_back(name, credits, gradePoint);
        totalGradePoints += gradePoint * credits;
        totalCredits += credits;
    }

    
    float calculateGPA() {
        return (totalCredits == 0) ? 0 : totalGradePoints / totalCredits;
    }

    
    void displayCGPA() {
        cout << "\n==============================================\n";
        cout << " COURSE DETAILS \n";
        cout << "==============================================\n";
        cout << left << setw(20) << "Course Name"
            << setw(10) << "Credits"
            << setw(10) << "Grade Point" << endl;
        cout << "----------------------------------------------\n";

        for (const auto& course : courses) {
            cout << left << setw(20) << course.name
                << setw(10) << course.credits
                << setw(10) << fixed << setprecision(2) << course.gradePoint << endl;
        }

        cout << "==============================================\n";
        cout << " Total Credits: " << totalCredits << endl;
        cout << " Total Grade Points: " << fixed << setprecision(2) << totalGradePoints << endl;
        cout << " CGPA: " << fixed << setprecision(2) << calculateGPA() << " / 10" << endl; // Fixed scale of 10  
        cout << "==============================================\n";
    }
};

int main() {
    Student student;
    int numCourses;

    cout << " Welcome to the CGPA Calculator \n";
    cout << "====================================\n";
    cout << "Enter the number of courses: ";
    cin >> numCourses;

    while (numCourses <= 0) {
        cout << "Invalid input! Please enter a positive number: ";
        cin >> numCourses;
    }

    for (int i = 0; i < numCourses; i++) {
        string name;
        int credits;
        float gradePoint;

        cout << "\n Enter details for Course " << (i + 1) << ":\n";
        cout << "------------------------------------\n";
        cout << "Course Name: ";
        cin >> ws;
        getline(cin, name);

        cout << "Credits (1-10): ";
        cin >> credits;
        while (credits <= 0) {
            cout << "Invalid! Credits must be greater than 0. Enter again: ";
            cin >> credits;
        }

        cout << "Grade Point (0-10): ";
        cin >> gradePoint;
        while (gradePoint < 0 || gradePoint > 10) { // Maintain the maximum of 10  
            cout << "Invalid! Grade point must be between 0 and 10. Enter again: ";
            cin >> gradePoint;
        }

        student.addCourse(name, credits, gradePoint);
    }

    student.displayCGPA();
    return 0;
}