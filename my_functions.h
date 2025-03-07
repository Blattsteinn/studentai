#pragma once

#include "mano_lib.h"

// random_generating.cpp
    int randomNumber(int a, int b);
    StudentContainer<float> random_grade();
    string random_name();
    string random_last_name();

//  calculations.cpp
    float average(Studentas laikinas);
    // float median(Studentas laikinas);
    void calculate_everything(Studentas &laikinas);

// fileRead.cpp
    /**string readFileToString(string file_name);
    int wordCount(istringstream& iss);
    StudentContainer<Studentas> read_student_records(int ndCount, istringstream& iss);
    void appendingContainerViaFile(string file_name, StudentContainer <Studentas> &student_list);
**/

/**  student_functions.cpp
    StudentContainer<float> enter_grades_manually();
    void print_students(StudentContainer<Studentas> studentas);
    void insert_student(StudentContainer <Studentas> &student_list, Studentas &studentas);
    void sort_students(StudentContainer <Studentas> &student_list);
    void sort_students(StudentContainer<Studentas> &student_list, int choice);
**/

// aditional_functions.cpp
    int check_the_value(string message, string errorMessage,int minVal,int maxVal);  // checks if a give value is within range
    //void print_to_file(StudentContainer<Studentas> list_of_students, string file_name);
    string getPradziosTekstas();

// testavimas.cpp
    void generate_files(int student_size);
   // StudentContainer<Studentas> divide_students(StudentContainer <Studentas> &list_of_students, int choice);
   // void testing();

    #include "random_generating.h"
    #include "fileRead.h"
    #include "student_functions.h"
    #include "additional_functions.h"
    #include "testavimas.h"