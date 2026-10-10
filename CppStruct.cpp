//
// Created by User on 10/10/2026.
//

#include <iostream>
#include <string>

using namespace std;

struct Student
{
    std::string name;
    double gpa;
    bool enrolled;
};

void ScoreStudent(Student &student, double changeGpa);

int main()
{

    // struct - A structure that group related variables under one name
    // structs can contain many different data types (string, int, bools)
    // variables in a struct are known as 'members'
    // members can access with . "Class Member Access Operator"

    Student student1;
    student1.name = "Joe";
    student1.gpa = 5.0;
    student1.enrolled = true;

    Student std2;
    std2.name = "Rachel";
    std2.gpa = 5.0;
    std2.enrolled = true;

    ScoreStudent(std2, 3.4);

    return 0;
}

void ScoreStudent(Student &student, double changeGpa)
{
    student.gpa = changeGpa;
    printf("Gpa changed to %f", student.gpa);
}