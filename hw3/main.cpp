#include <iostream>
#include <cstdlib>
#include <string>

#include "Student.h"
#include "Course.h"
#include "SchoolManagementSystem.h"

// Display menu for SchoolManagementSystem.
void school_display_menu();

// Display menu for Student.
void student_display_menu();

// Display menu for Course.
void course_display_menu();

// Display menu for select student case.
void select_student_display_menu();

// Display menu for select course case.
void select_course_display_menu();

// Gets a valid selection for argument function f.
// Valid selection is a selection in range [lower, upper].
// Returns selection.
int get_valid_selection(void (*f)(), int lower, int upper);

// Gets a valid course from course list of system_pointer
int get_valid_course(PA3::SchoolManagementSystem* system_pointer);


int main(int argc, char *argv[])
{
    int selection_school, selection_student, selection_course;
    bool quit_program, quit_case;
    int id;

    std::string name, sirname;
    std::string full_name;
    std::string code;


    PA3::SchoolManagementSystem* system_pointer = 
        new PA3::SchoolManagementSystem();

    quit_program = false;
    while (!quit_program) {
        // Display and get a valid selection from user.
        selection_school = get_valid_selection(&school_display_menu, 0, 4);

        switch (selection_school) {
            case 1: // Student menu.
                quit_case = false;
                while(!quit_case) {

                    // Display student menu and get a valid selection.
                    selection_student = 
                        get_valid_selection(&student_display_menu, 0, 2);


                    switch(selection_student) {
                        case 1:
                            // get name, sirname and id of student.
                            std::cout << ">> ";
                            std::cin >> name >> sirname >> id;

                            // get rid of newline char in buffer.
                            std::cin.get();

                            // concatinate name and sirname to get full_name
                            full_name = name + " " + sirname;

                            // Add new student.
                            system_pointer->add_student(full_name.c_str(),
                                                        id);

                            break;
                        case 2:
                            // Get name, sirname and id of student.
                            std::cout << ">> ";
                            std::cin >> name >> sirname >> id;
                            // get rid of newline char in buffer.
                            std::cin.get();

                            // get full_name.
                            full_name = name + " " + sirname;


                            // get a valid selection from user.
                            selection_student = get_valid_selection(&select_student_display_menu, 0, 3);


                            if (selection_student == 0){ // go up.
                                quit_case = true;
                            } else if (selection_student == 1) {
                                // delete student.
                                system_pointer->delete_student(full_name.c_str(), id);
                            } else if (selection_student == 2) {
                                // Add selected student to a course.
                                selection_student = get_valid_course(system_pointer);

                                if (selection_student != 0){
                                    int index_of_student = system_pointer->search_student(full_name.c_str(), id);
                                    system_pointer->add_student_to_a_course(index_of_student, selection_student-1);
                                }
                            } else if(selection_student == 3) {
                                // drop selected student from a course.

                                selection_student = get_valid_course(system_pointer);

                                if (selection_student != 0){
                                    int index_of_student = system_pointer->search_student(full_name.c_str(), id);
                                    system_pointer->drop_student_from_a_course(index_of_student, selection_student-1);
                                }
                            }
                            break;
                        case 0: // Quit this case and go back to main loop.
                            quit_case = true;
                            break;
                        default:
                            break;
                    }
                }

                break;
            case 2: // Course menu.

                quit_case = false;

                while (!quit_case) {
                    // Display menu for course and get a valid selection
                    selection_course = 
                        get_valid_selection(&course_display_menu, 0, 2);

                    switch(selection_course) {
                        case 1:
                            // Get course name and code
                            std::cout << ">> ";
                            std::cin >> name >> code;
                            std::cin.get(); // get rid of newline char in buffer.

                            // Add that course
                            system_pointer->add_course(name.c_str(), code.c_str());

                            break;
                        case 2:

                            selection_course = get_valid_selection(&select_course_display_menu, 0, 2);

                            if (selection_course == 1){
                                std::cout << ">> ";
                                std::cin >> name >> code;
                                std::cin.get(); // get rid of newline char in buffer.

                                system_pointer->delete_course(name.c_str(), code.c_str());
                            } else if(selection_course == 2) {
                                std::cout << ">> ";
                                std::cin >> name >> code;
                                std::cin.get(); // get rid of newline char in buffer.
                                
                                int index_of_course = system_pointer->search_course(name.c_str(), code.c_str());
                                system_pointer->list_all_registered_student_to_a_course(index_of_course);
                            }
                            break;
                        case 0:
                            quit_case = true;
                            break;
                        default:
                            break;
                    }
                }
                break;
            case 3:
                // Print student list
                system_pointer->list_all_students();
                break;
            case 4:
                // Print course list.
                system_pointer->list_all_courses();
                break;
            case 0: // Quit the program.
                quit_program = true;
                break;
            default:
                break;
        }
    }

    return 0;
}

// Display menu for SchoolManagementSystem.
void school_display_menu()
{
    std::cout << "Main Menu" << std::endl
              << "0 exit" << std::endl
              << "1 student" << std::endl
              << "2 course" << std::endl
              << "3 list all students" << std::endl
              << "4 list all courses" << std::endl;
}

// Display menu for Student.
void student_display_menu()
{
    std::cout << "0 up" << std::endl
              << "1 add student" << std::endl
              << "2 select student" << std::endl;
}

// Display menu for Course.
void course_display_menu()
{
    std::cout << "0 up" << std::endl
              << "1 add course" << std::endl
              << "2 select course" << std::endl;
}

// Display menu for select student case.
void select_student_display_menu()
{
    std::cout << "0 up" << std::endl
              << "1 delete student" << std::endl
              << "2 add selected student to a course" << std::endl
              << "3 drop selected student from a course" << std::endl;
}

// Display menu for select course case.
void select_course_display_menu()
{
    std::cout << "0 up" << std::endl
              << "1 delete course" << std::endl
              << "2 list students registered to the selected course" << std::endl;
}


// Gets a valid selection for argument function f.
// Valid selection is a selection in range [lower, upper].
// Returns selection.
int get_valid_selection(void (*f)(), int lower, int upper)
{
    int selection;

    do{
        // Display menu
        f();

        // Get a selection from user.
        std::cout << ">> ";
        std::cin >> selection;
    
    } while (selection > upper || selection < lower);

    return selection;
}


// Gets a valid course from course list of system_pointer
int get_valid_course(PA3::SchoolManagementSystem* system_pointer)
{
    int selection;

    do{
        std::cout << "0. up" << std::endl;
        system_pointer->list_all_courses();
        std::cout << ">> ";
        std::cin >> selection;

    } while(selection < 0 || selection > system_pointer->get_number_of_courses());

    return selection;
}


