#include <iostream>
#include <fstream>
#include <vector>
#include "Student.h"

void addStudent(std::vector<Student> &students);
void saveStudentsToFile(const std::vector<Student> &students);
void loadStudentsFromFile(std::vector<Student> &students);
void displayAllStudents(const std::vector<Student> &students);
Student searchStudentById(const std::vector<Student> &students, int id);

int main() {
    std::vector<Student> students;
    loadStudentsFromFile(students);

    int choice;
    do {
        std::cout << "\nStudent Management System\n";
        std::cout << "1. Add Student\n";
        std::cout << "2. Display All Students\n";
        std::cout << "3. Search Student by ID\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addStudent(students);
                saveStudentsToFile(students);
                break;
            case 2:
                displayAllStudents(students);
                break;
            case 3: {
                int id;
                std::cout << "Enter student ID to search: ";
                std::cin >> id;
                Student student = searchStudentById(students, id);
                if (student.getId() != 0) {
                    student.display();
                } else {
                    std::cout << "Student not found!\n";
                }
                break;
            }
            case 4:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Try again.\n";
                break;
        }
    } while (choice != 4);

    return 0;
}

void addStudent(std::vector<Student> &students) {
    std::string name, course;
    int id;

    std::cout << "Enter student ID: ";
    std::cin >> id;
    std::cin.ignore();
    std::cout << "Enter student name: ";
    std::getline(std::cin, name);
    std::cout << "Enter course: ";
    std::getline(std::cin, course);

    Student newStudent(name, id, course);
    students.push_back(newStudent);

    std::cout << "Student added successfully!\n";
}

void saveStudentsToFile(const std::vector<Student> &students) {
    std::ofstream outFile("data.txt");
    if (!outFile) {
        std::cerr << "Error saving to file!\n";
        return;
    }

    for (const auto &student : students) {
        student.saveToFile(outFile);
    }

    outFile.close();
    std::cout << "Data saved to file.\n";
}

void loadStudentsFromFile(std::vector<Student> &students) {
    std::ifstream inFile("data.txt");
    if (!inFile) {
        std::cout << "No data file found. Starting fresh.\n";
        return;
    }

    while (true) {
        Student student = Student::readFromFile(inFile);
        if (student.getId() == 0) {
            break;
        }
        students.push_back(student);
    }

    inFile.close();
}

void displayAllStudents(const std::vector<Student> &students) {
    if (students.empty()) {
        std::cout << "No students available.\n";
    } else {
        for (const auto &student : students) {
            student.display();
            std::cout << "-----------------\n";
        }
    }
}

Student searchStudentById(const std::vector<Student> &students, int id) {
    for (const auto &student : students) {
        if (student.getId() == id) {
            return student;
        }
    }
    return Student();
}
