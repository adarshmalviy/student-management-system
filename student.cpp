#include "Student.h"
#include <fstream>

Student::Student() : name(""), id(0), course("") {}

Student::Student(std::string name, int id, std::string course) : name(name), id(id), course(course) {}

void Student::setName(std::string name) {
    this->name = name;
}

std::string Student::getName() const {
    return name;
}

void Student::setId(int id) {
    this->id = id;
}

int Student::getId() const {
    return id;
}

void Student::setCourse(std::string course) {
    this->course = course;
}

std::string Student::getCourse() const {
    return course;
}

void Student::display() const {
    std::cout << "ID: " << id << "\nName: " << name << "\nCourse: " << course << "\n";
}

void Student::saveToFile(std::ofstream &out) const {
    out << id << "\n" << name << "\n" << course << "\n";
}

Student Student::readFromFile(std::ifstream &in) {
    int id;
    std::string name, course;

    if (!(in >> id)) {
        return Student();
    }
    in.ignore();
    std::getline(in, name);
    std::getline(in, course);

    return Student(name, id, course);
}
