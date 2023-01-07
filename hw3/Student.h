#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <cstdlib>
#include <string>

#include "Course.h"

namespace PA3{

    class Course;


    class Student
    {
    public:
        // Default constructor for Student.
        Student();

        // Destructor.
        ~Student();

        // Constructor which takes name and id.
        Student(const char* name, int id);


        // Sets name of student.
        void set_name(const char* name);

        // Sets id of student
        void set_id(int id);

        // Returns name of student as C-string.
        const char* get_name() const;

        // Returns id of student.
        int get_id() const;


        // Add a new course if course doesn't exist already.
        // Increase the capacity of courses array to twice of its
        // capacity if necessary.
        void add_course(Course* c);

        // Deletes a course if course exists in courses.
        // Decrease the capacity of courses array to half of its
        // capacity if necessay.
        void delete_course(Course* c);


        // Searches and returns index of course which its name is name
        // and code is code
        int search_course(const char* name, const char* code);


    private:
        // Name of student
        std::string name;

        // Id of student.
        int id;

        // Array of Course pointers which are
        // courses taken by student.
        Course** courses;

        // Size of courses.
        int courses_size;

        // Capacity of courses.
        int courses_capacity;

    };



}

#endif
