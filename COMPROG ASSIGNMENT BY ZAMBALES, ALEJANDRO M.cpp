#include <iostream>
#include <string>
#include <limits>
using namespace std;

struct Student {
    int studentID;
    string firstName;
    string lastName;
    string course;
    float previousGPA;
};

int main() {
    const int numStudents = 5;
    Student students[numStudents];
    for (int i = 0; i < numStudents; i++) {
        cout << "Enter details for student " << i + 1 << ":" << endl;
        cout << "Student ID: ";
        while (!(cin >> students[i].studentID)) {
            cout << "Invalid input. Please enter a valid numeric Student ID: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        cout << "First Name: ";
        getline(cin, students[i].firstName);
        cout << "Last Name: ";
        getline(cin, students[i].lastName);
        cout << "Course: ";
        getline(cin, students[i].course);
        cout << "Previous GPA: ";
        while (!(cin >> students[i].previousGPA) || students[i].previousGPA < 0.0 || students[i].previousGPA > 4.0) {
            cout << "Invalid input. Please enter a GPA between 0.0 and 4.0: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
        cout << endl;
    }
    cout << "Student Records:" << endl;
    for (int i = 0; i < numStudents; i++) {
        cout << "Student " << i + 1 << ":" << endl;
        cout << "ID: " << students[i].studentID << endl;
        cout << "Name: " << students[i].firstName << " " << students[i].lastName << endl;
        cout << "Course: " << students[i].course << endl;
        cout << "Previous GPA: " << students[i].previousGPA << endl;
        cout << endl;
    }
    return 0;
}