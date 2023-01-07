// SchoolManagementSystem.cpp
// Implementation file of class SchoolManagementSystem
#include "SchoolManagementSystem.h"

namespace PA3{
    // Default constructor.
    SchoolManagementSystem::SchoolManagementSystem()
        : students(NULL), courses(NULL), number_of_students(0),
          number_of_courses(0), student_capacity(5), courses_capacity(5)
    {
        int i;

        // Init courses.
        courses = new Course* [courses_capacity];
        for (i = 0; i < courses_capacity; ++i)
            courses[i] = NULL;

        students = new Student* [student_capacity];
        for (i = 0; i < student_capacity; ++i)
            students[i] = NULL;

    }

    // Desctuctor
    SchoolManagementSystem::~SchoolManagementSystem()
    {
        // Delete all students.
        for (int i = 0; i < number_of_students; i++)
            delete students[i];
        delete [] students;

        // Delete all courses.
        for (int i = 0; i < number_of_courses; i++)
            delete courses[i];
        delete [] courses;
    }

    // Add a new student
    void SchoolManagementSystem::add_student(const char* name, int id)
    {
        int index;
        if ((index = search_student(name, id)) != -1){
            // Student already exists in system.
            // Quit function doing nothing.
            return;
        }

        // Increase capacity of students array if necessary.
        if (number_of_students >= student_capacity){
            // Hold old array in a tmp pointer.
            Student** tmp = students;

            // Create new array
            students = new Student* [2 * student_capacity];

            // Copy old one to new one.
            for (int i = 0; i < number_of_students; ++i)
                students[i] = tmp[i];

            // Delete old one to avoid memory leak.
            delete [] tmp;


            // Set new capacity.
            student_capacity = 2 * student_capacity;
        }

        // Add new student to array.
        students[number_of_students] = new Student(name, id);
        
        // Increase number of students by one.
        number_of_students++;
        
    }

    // Add a new course
    void SchoolManagementSystem::add_course(const char* name, const char* code)
    {
        int index;
        if ((index = search_course(name, code)) != -1){
            // Course already exists in array courses
            // Quit program doing nothing.
            return;
        }

        // Increase capacity of courses if necessary
        if (number_of_courses >= courses_capacity){

            // Hold old array in a tmp pointer.
            Course** tmp = courses;

            // create new array
            courses = new Course* [2 * courses_capacity];

            // Copy old array to new one.
            for (int i = 0; i < number_of_courses; ++i)
                courses[i] = tmp[i];

            // Delete old one.
            delete [] tmp;


            // Set new capacity.
            courses_capacity = 2 * courses_capacity;
        }


        // Add new course to array courses
        courses[number_of_courses] = new Course(name, code);

        // Increase number of courses by one.
        number_of_courses++;

    }

    // Delete the student which student name is name and id is id.
    void SchoolManagementSystem::delete_student(const char* name, int id)
    {
        int index;
        if ((index = search_student(name, id)) == -1){
            // There is no such student exists in array students.
            // Quit function doing nothing.
            return;
        }

        // Decrease capacity if necessary
        if (number_of_students < student_capacity/2){
            // Hold old array in a tmp pointer.
            Student** tmp = students;

            // Create new array
            students = new Student* [student_capacity / 2];

            // Copy students array
            for (int i = 0; i < number_of_students; ++i)
                students[i] = tmp[i];

            // Delete old one.
            delete [] tmp;

            // Set new capacity.
            student_capacity = student_capacity / 2;
        }


        // Delete element.
        for (int i = index; i < number_of_students-1; ++i)
            students[i] = students[i+1];

        // Descrease number of students by one.
        number_of_students--;

        // make last element NULL
        students[number_of_students] = NULL;

    }


    // Delete the course which course name is name and code name is code.
    void SchoolManagementSystem::delete_course(const char*name, const char*code)
    {
        int index;
        if ((index = search_course(name, code)) == -1){
            // There is no such course exists in array courses.
            // Quit function doing nothing.
            return;
        }

        // Decrease capacity if necessary
        if (number_of_courses < courses_capacity/2){
            // Hold old array in a tmp pointer.
            Course** tmp = courses;

            // Create new array
            courses = new Course* [courses_capacity / 2];

            // Copy courses array
            for (int i = 0; i < number_of_courses; ++i)
                courses[i] = tmp[i];

            // Delete old one.
            delete [] tmp;

            // Set new capacity.
            courses_capacity = courses_capacity / 2;
        }


        // Delete element.
        for (int i = index; i < number_of_courses-1; ++i)
            courses[i] = courses[i+1];

        // Descrease number of courses by one.
        number_of_courses--;

        // make last element NULL
        courses[number_of_courses] = NULL;

    }

    // Lists all courses.
    void SchoolManagementSystem::list_all_courses() const
    {
        int i;
        for (i = 0; i < number_of_courses; ++i) {
            std::cout << i+1 << " "
                      << courses[i]->get_name() << " "
                      << courses[i]->get_code() << std::endl;
        }
    }

    // Lists all students.
    void SchoolManagementSystem::list_all_students() const
    {
        int i;
        for (i = 0; i < number_of_students; ++i) {
            std::cout << i+1 << " "
                      << students[i]->get_name() << " "
                      << students[i]->get_id() << std::endl;
        }
    }

    // searchs and returns index of student which its name is name and id is id
    // If there is no such student returns -1.
    int SchoolManagementSystem::search_student(const char* name, int id) const
    {
        int i;
        std::string name_in_str = name;
        std::string tmp_name;
        int tmp_id;
        
        for (i = 0; i < number_of_students; ++i) {
            tmp_name = students[i]->get_name();
            tmp_id = students[i]->get_id();

            if (tmp_name == name_in_str && tmp_id == id)
                return i;
        }

        return -1;
    }



    // searchs and returns index of course which its name is name and code is code.
    // If there is no such course returns -1.
    int SchoolManagementSystem::search_course(const char* name, const char* code) const
    {
        std::string name_in_str = name;
        std::string code_in_str = code;

        std::string tmp_name;
        std::string tmp_code;
        
        for (int i = 0; i < number_of_courses; ++i) {
            tmp_name = courses[i]->get_name();
            tmp_code = courses[i]->get_code();

            if (tmp_name == name_in_str && tmp_code == code_in_str)
                return i;
        }

        return -1;
    }

    // Returns number of courses.
    int SchoolManagementSystem::get_number_of_courses() const
    {
        return number_of_courses;
    }

    // Returns number of students.
    int SchoolManagementSystem::get_number_of_students() const
    {
        return number_of_students;
    }



    // adds student to a course.
    void SchoolManagementSystem::add_student_to_a_course(int index_of_student, int index_of_course)
    {
        students[index_of_student]->add_course(courses[index_of_course]);
        courses[index_of_course]->add_student(students[index_of_student]);
    }

    // Drops student from a course.
    void SchoolManagementSystem::drop_student_from_a_course(int index_of_student, int index_of_course)
    {
        students[index_of_student]->delete_course(courses[index_of_course]);
        courses[index_of_course]->delete_student(students[index_of_student]);
    }


    // List all students who registered to a course taken index of course in array courses.
    void SchoolManagementSystem::list_all_registered_student_to_a_course(int course_index) const
    {
        courses[course_index]->list_all_students();
    }

}
