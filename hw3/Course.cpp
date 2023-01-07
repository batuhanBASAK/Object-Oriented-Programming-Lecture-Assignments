// Course.cpp
// Implementation file for class Course

#include "Course.h"

namespace PA3{
    
    // Default constructor.
    Course::Course()
        : name(""), code(""), students(NULL),
          students_size(0), students_capacity(5)
    {
        // Allocate space for students array.
        students = new Student* [students_capacity];


        // Initialize students array.
        int i;
        for (i = 0; i < students_capacity; ++i)
            students[i] = NULL;
    }

    // Destructor.
    Course::~Course()
    {
        // Delete students array.
        for (int i = 0; i < students_size; ++i)
            delete students[i];
        delete [] students;
    }


    // Constructor that takes name and code of course.
    Course::Course(const char* name, const char* code)
        : name(name), code(code), students(NULL),
          students_size(0), students_capacity(5)
    {
        // Allocate space for students array.
        students = new Student* [students_capacity];


        // Initialize students array.
        int i;
        for (i = 0; i < students_capacity; ++i)
            students[i] = NULL;
 
    }


    // Sets name of course
    void Course::set_name(const char* name)
    {
        this->name = name;
    }

    // Sets code of course
    void Course::set_code(const char* code)
    {
        this->code = code;
    }

    // Gets code of course
    const char* Course::get_code() const
    {
        return code.c_str();
    }

    // Gets name of course
    const char* Course::get_name() const
    {
        return name.c_str();
    }


    // Adds student s to array students if it doesn't exist already.
    // If size of array reaches to capacity of array expands array to
    // twice of its capacity.
    void Course::add_student(Student* s)
    {
        if (search_student(s->get_name(), s->get_id()) != -1){
            // Student which is wanted to add to students array
            // already exists in array. Quit function doing nothing.
            return;
        }


        // Increase capacity if size reaches to capacity.
        if (students_size >= students_capacity) {

            // Hold old students array in a tmp pointer.
            Student** tmp = students;

            // Create a new students array which is capacity is 
            // twice of current capacity.
            students = new Student* [2*students_capacity];

            // Copy old studets array to new one.
            for (int i = 0; i < students_size; ++i)
                students[i] = tmp[i];

            // Delete tmp to avoid memory leak.
            delete [] tmp;


            // Set new capacity.
            students_capacity = 2 * students_capacity;
        }

        // add new element to
        students[students_size] = s;

        // Increase the size by one.
        students_size++;
    }


    // Deletes student if it exists already.
    // If size of array reaches to half of capacity of array shrinks array to
    // half of its capacity.
    void Course::delete_student(Student* s)
    {
        int index;
        if ((index = search_student(s->get_name(), s->get_id())) == -1){
            // There is no such student exists in array students.
            // Quit function doing nothing.
            return;
        }

        // Decrease the capacity to half of its capacity if 
        // size is less then half of its capacity.
        if (students_size < students_capacity / 2) {
            // Hold old array in a tmp pointer.
            Student** tmp = students;

            // Create new array.
            students = new Student* [students_capacity/2];

            // Copy old one to new one.
            for (int i = 0; i < students_size; ++i)
                students[i] = tmp[i];

            // Delete old array.
            delete [] tmp;

            students_capacity = students_capacity / 2;
        }

        // Shift elements
        for (int i = index; i < students_size-1; ++i) {
            students[i] = students[i+1];
        }

        // assign last element to NULL
        students[students_size-1] = NULL;
        // Decrease size by one.
        students_size--;

    }

    // Search and returns index of student in array students.
    // If there is no such student in array return -1.
    int Course::search_student(const char* name, int id) const
    {
        std::string name_in_str = name;
        std::string tmp_name;

        for (int i = 0; i < students_size; ++i) {
            tmp_name = students[i]->get_name();
            if ( tmp_name == name_in_str && students[i]->get_id() == id)
                return i;
        }

        return -1;
    }



    // list all student list.
    void Course::list_all_students() const
    {
        int i;

        for (i = 0; i < students_size; ++i) {
            std::cout << i+1 << " "
                      << students[i]->get_name() << " "
                      << students[i]->get_id() << std::endl;
        }
    }

    // Returns number of students.
    int Course::get_students_size() const
    {
        return students_size;
    }




}
