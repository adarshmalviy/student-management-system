#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>

class Student {
private:
    std::string name;
    int id;
    std::string course;

public:
    Student();
    Student(std::string name, int id, std::string course);

    void setName(std::string name);
    std::string getName() const;

    void setId(int id);
    int getId() const;

    void setCourse(std::string course);
    std::string getCourse() const;

    void display() const;

    void saveToFile(std::ofstream &out) const;

    static Student readFromFile(std::ifstream &in);
};

#endif
