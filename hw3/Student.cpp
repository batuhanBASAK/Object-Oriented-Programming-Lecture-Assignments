#include "Student.h"

namespace PA3{

    // Default constructor for Student.
    Student::Student()
        : name(""), id(0), courses(NULL),
          courses_size(0), courses_capacity(5)
    {
        // Allocate space for courses
        courses = new Course* [courses_capacity];

        // Initialize courses.
        int i;
        for (i = 0; i < courses_capacity; ++i)
            courses[i] = NULL;
    }


    Student::~Student()
    {
        // Delete courses array.
        for(int i = 0; i < courses_size; i++)
            delete courses[i];
        delete [] courses;
    }

    // Constructor which takes name and id.
    Student::Student(const char* name, int id)
        : name(name), id(id), courses(NULL),
          courses_size(0), courses_capacity(5)
    {
        // Allocate space for courses
        courses = new Course* [courses_capacity];

        // Initialize courses.
        int i;
        for (i = 0; i < courses_capacity; ++i)
            courses[i] = NULL;
    }


    // Sets name of student.
    void Student::set_name(const char* name)
    {
        this->name = name;
    }

    // Sets id of student
    void Student::set_id(int id)
    {
        this->id = id;
    }

    // Returns name of student as C-string.
    const char* Student::get_name() const
    {
        return name.c_str();
    }

    // Returns id of student.
    int Student::get_id() const
    {
        return id;
    }


    // Add a new course if course doesn't exist already.
    // Increase the capacity of courses array to twice of its
    // capacity if necessary.
    void Student::add_course(Course* c)
    {
        if (search_course(c->get_name(), c->get_code()) != -1) {
            // Course already exists in array courses.
            // Quit function doing nothing.
            return;
        }

        // if size is reaches to capacity
        // then increase the capacity to twice of its capacity.
        if ( courses_size >= courses_capacity) {
            // Holds olds courses array in tmp.
            Course **tmp = courses;

            // Create new courses array.
            courses = new Course* [2 * courses_capacity];

            // Copy old array to new one.
            int i;
            for (i = 0; i < courses_size; ++i)
                courses[i] = tmp[i];

            // delete tmp to avoid memory leak.
            delete [] tmp;


            // Set new capacity.
            courses_capacity = 2 * courses_capacity;
        }
        

        // Add new course to array.
        courses[courses_size] = c;

        // Increase course size by one.
        courses_size++;

    }

    // Deletes a course if course exists in courses.
    // Decrease the capacity of courses array to half of its
    // capacity if necessay.
    void Student::delete_course(Course* c)
    {
        int index; // index of course will been deleted.
        if ((index = search_course(c->get_name(), c->get_code())) == -1) {
            // Course doesn't exists in array course.
            // Quit function doing nothing.
            return;
        }

        // If course size decreases to half of capacity
        // then decrease capacity to half of capacity.
        if (courses_size < courses_capacity/2) {
            // Hold old array to tmp.
            Course** tmp = courses; 

            // Create new array.
            courses = new Course* [courses_capacity/2];

            // Copy old array to new one.
            for (int i = 0; i < courses_size; ++i)
                courses[i] = tmp[i];

            // delete old one to avoid memory leak.
            delete [] tmp;

            // Set new capacity.
            courses_capacity = courses_capacity / 2;

        }


        // shift array
        for (int i = index; i < courses_size-1; ++i) {
            courses[i] = courses[i+1];
        }

        // make last element NULL.
        courses[courses_size-1] = NULL;

        // Decrease size by one.
        courses_size--;

    }


    // Searches and returns index of course which its name is name
    // and code is code
    int Student::search_course(const char* name, const char* code)
    {
        std::string name_in_str = name;
        std::string code_in_str = code;
        std::string tmp_name;
        std::string tmp_code;

        int i;
        for (i = 0; i < courses_size; ++i) {
            tmp_name = courses[i]->get_name();
            tmp_code = courses[i]->get_code();
            if ( tmp_name == name_in_str && tmp_code == code_in_str)
                return i;
        }
        return -1;
    }

}
