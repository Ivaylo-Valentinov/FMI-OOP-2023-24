#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

const size_t MAX_STRING_LENGTH = 257; //The last char is '\0'. The string's max length is 256
const size_t EGN_LENGTH = 11;
const size_t MAX_NUMBER_OF_STUDENTS = 100;

struct Student {
    char name[MAX_STRING_LENGTH] = "";
    char surname[MAX_STRING_LENGTH] = "";
    char EGN[EGN_LENGTH] = "";

    bool isUninitialized() const {
        return (name[0] == '\0' && surname[0] == '\0' && EGN[0] == '\0');
    }

    bool equalTo(const Student& compredStudent) const {
        return strcmp(name, compredStudent.name) == 0
          && strcmp(surname, compredStudent.surname) == 0
          && strcmp(EGN, compredStudent.EGN) == 0;
    }

    void copyInto(const Student& studentData) {
        strcpy(name, studentData.name);
        strcpy(surname, studentData.surname);
        strcpy(EGN, studentData.EGN);
    }
};

struct University {
    char name[MAX_STRING_LENGTH] = "";
    Student students[MAX_NUMBER_OF_STUDENTS];

    bool hasStudent(const Student& student) const {
        for (size_t index = 0; index < MAX_NUMBER_OF_STUDENTS; ++index) {
            if (students[index].equalTo(student)) {
                return true;
            }
        }

        return false;
    }

    void addStudent(const Student& student) {
        if (hasStudent(student)) {
            return;
        }

        for (size_t index = 0; index < MAX_NUMBER_OF_STUDENTS; ++index) {
            if (students[index].isUninitialized()) {
                students[index].copyInto(student);
                return;
            }
        }

        throw std::exception("There is no free space to save the student!");
    }
};
