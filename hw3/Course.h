#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <cstdlib>
#include <string>
#include "Student.h"

namespace PA3{


    class Student;

    class Course{
        public:
            // Default constructor.
            Course();

            // Destructor.
            ~Course();

            // Constructor that takes name and code of course.
            Course(const char* name, const char* code);


            // Sets name of course
            void set_name(const char* name);

            // Sets code of course
            void set_code(const char* code);

            // Gets code of course
            const char* get_code() const;

            // Gets name of course
            const char* get_name() const;


            // Adds student s to array students if it doesn't exist already.
            // If size of array reaches to capacity of array expands array to
            // twice of its capacity.
            void add_student(Student* s);


            // Deletes student if it exists already.
            // If size of array reaches to half of capacity of array shrinks array to
            // half of its capacity.
            void delete_student(Student* s);

            // Search and returns index of student in array students.
            // If there is no such student in array return -1.
            int search_student(const char* name, int id) const;

            // list all student list.
            void list_all_students() const;

            // Returns number of students.
            int get_students_size() const;


        private:

            // Name of course.
            std::string name;

            // Code of course.
            std::string code;

            // Array of Student pointers.
            Student** students;

            // Size of students array.
            int students_size;

            // Capacity of students array.
            int students_capacity;

    };

}

#endif
