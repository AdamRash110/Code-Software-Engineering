#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <limits>

using namespace std;

struct Student {
    string name;
    int age;
    double grade;
};

void displayMenu();
void addStudent(vector<Student>& students);
void displayStudents(const vector<Student>& students);
void calculateAverage(const vector<Student>& students);
void saveToFile(const vector<Student>& students, const string& filename);
void loadFromFile(vector<Student>& students, const string& filename);
void searchStudent(const vector<Student>& students);
void updateStudent(vector<Student>& students);
void deleteStudent(vector<Student>& students);

int main() {
    vector<Student> students;
    string filename = "students.txt";
    int choice;

    while (true) {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a valid number.\n";
            continue;
        }

        switch (choice) {
            case 1: 
                addStudent(students);
                break;
            case 2: 
                displayStudents(students);
                break;
            case 3: 
                calculateAverage(students);
                break;
            case 4: 
                saveToFile(students, filename);
                break;
            case 5: 
                loadFromFile(students, filename);
                break;
            case 6: 
                searchStudent(students);
                break;
            case 7: 
                updateStudent(students);
                break;
            case 8: 
                deleteStudent(students);
                break;
            case 9:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}

void displayMenu() {
    cout << "\nStudent Grade Calculator Menu:\n";
    cout << "1. Add Student\n";
    cout << "2. Display Students\n";
    cout << "3. Calculate Average Grade\n";
    cout << "4. Save to File\n";
    cout << "5. Load from File\n";
    cout << "6. Search Student\n";
    cout << "7. Update Student\n";
    cout << "8. Delete Student\n";
    cout << "9. Exit\n";
}

void addStudent(vector<Student>& students) {
    Student student;
    cout << "Enter student's name: ";
    cin.ignore();
    getline(cin, student.name);
    cout << "Enter student's age: ";
    cin >> student.age;
    cout << "Enter student's grade: ";
    cin >> student.grade;
    students.push_back(student);
}

void displayStudents(const vector<Student>& students) {
    for (const auto& student : students) {
        cout << "Name: " << student.name << ", Age: " << student.age << ", Grade: " << student.grade << endl;
    }
}

void calculateAverage(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No students to calculate average.\n";
        return;
    }
    double total = 0;
    for (const auto& student : students) {
        total += student.grade;
    }
    cout << "Average grade: " << total / students.size() << endl;
}

void saveToFile(const vector<Student>& students, const string& filename) {
    ofstream file(filename);
    if (!file) {
        cout << "Error opening file for saving.\n";
        return;
    }
    for (const auto& student : students) {
        file << student.name << "," << student.age << "," << student.grade << endl;
    }
    cout << "Data saved to " << filename << endl;
}

void loadFromFile(vector<Student>& students, const string& filename) {
    ifstream file(filename);
    if (!file) {
        cout << "Error opening file for loading.\n";
        return;
    }
    students.clear();
    string line;
    while (getline(file, line)) {
        Student student;
        size_t pos1 = line.find(',');
        size_t pos2 = line.find(',', pos1 + 1);
        
        student.name = line.substr(0, pos1);
        student.age = stoi(line.substr(pos1 + 1, pos2 - pos1 - 1));
        student.grade = stod(line.substr(pos2 + 1));
        
        students.push_back(student);
    }
    cout << "Data loaded from " << filename << endl;
}

void searchStudent(const vector<Student>& students) {
    string name;
    cout << "Enter student's name to search: ";
    cin.ignore();
    getline(cin, name);
    
    for (const auto& student : students) {
        if (student.name == name) {
            cout << "Student found: " << student.name << ", Age: " << student.age << ", Grade: " << student.grade << endl;
            return;
        }
    }
    cout << "Student not found.\n";
}

void updateStudent(vector<Student>& students) {
    string name;
    cout << "Enter student's name to update: ";
    cin.ignore();
    getline(cin, name);
    
    for (auto& student : students) {
        if (student.name == name) {
            cout << "Enter new age: ";
            cin >> student.age;
            cout << "Enter new grade: ";
            cin >> student.grade;
            cout << "Student updated.\n";
            return;
        }
    }
    cout << "Student not found.\n";
}

void deleteStudent(vector<Student>& students) {
    string name;
    cout << "Enter student's name to delete: ";
    cin.ignore();
    getline(cin, name);
    
    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->name == name) {
            students.erase(it);
            cout << "Student deleted.\n";
            return;
        }
    }
    cout << "Student not found.\n";
}