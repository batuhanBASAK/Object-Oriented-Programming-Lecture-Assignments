// SchoolManagementSystem.h
// Interface file for class SchoolManagementSystem
#ifndef SCHOOL_MANAGEMENT_SYSTEM_H
#define SCHOOL_MANAGEMENT_SYSTEM_H

#include <iostream>
#include <cstdlib>
#include <string>

#include "Student.h"
#include "Course.h"

namespace PA3{

    class SchoolManagementSystem
    {
    public:
        // Default constructor.
        SchoolManagementSystem();

        // Desctuctor
        ~SchoolManagementSystem();


        // Add a new student
        void add_student(const char* name, int id);

        // Add a new course
        void add_course(const char* name, const char* code);

        // Delete the student which student name is name and id is id.
        void delete_student(const char* name, int id);

        // Delete the course which course name is name and code name is code.
        void delete_course(const char*name, const char*code);

        // Lists all courses.
        void list_all_courses() const;

        // Lists all students.
        void list_all_students() const;

        // Searches and returns index of student in array students if exists.
        // Returns -1 if there is no such student in array.
        int search_student(const char* name, int id) const;

        // Searches and returns index of course in array courses if exists.
        // Returns -1 if there is no such course in array.
        int search_course(const char* name, const char* code) const;

        // Returns number of courses.
        int get_number_of_courses() const;

        // Returns number of students.
        int get_number_of_students() const;

        // adds student to a course.
        void add_student_to_a_course(int index_of_student, int index_of_course);

        // Drops student from a course.
        void drop_student_from_a_course(int index_of_student, int index_of_course);

        // List all students who registered to a course taken index of course in array courses.
        void list_all_registered_student_to_a_course(int course_index) const;

    private:

        // Array of Student pointers.
        Student** students;

        // number of students in array
        int number_of_students;

        // Total capacity of students array.
        int student_capacity;
        
        // Array of Course pointers.
        Course** courses;

        // number of courses in array
        int number_of_courses;

        // Total capacity of courses array.
        int courses_capacity;

    };



}


#endif
