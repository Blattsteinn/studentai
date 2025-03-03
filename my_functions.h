#pragma once

#include "mano_lib.h"

// random_generating.cpp
    int randomNumber(int a, int b);
    vector<float> random_grade();
    string random_name();
    string random_last_name();

//  calculations.cpp
    float average(Studentas laikinas);
    float median(Studentas laikinas);

    void calculate_everything(Studentas &laikinas);

// fileRead.cpp
    string readFileToString(string file_name);
    int wordCount(istringstream& iss);
    vector<Studentas> read_student_records(int ndCount, istringstream& iss);


//  student_functions.cpp
    vector<float> enter_grades_manually();
    void print_students(vector<Studentas> studentas);
    void insert_student(vector <Studentas> &student_list, Studentas &studentas);
    void sort_students(vector <Studentas> &student_list);
    void sort_students(std::vector<Studentas> &student_list, int choice);

// aditional_functions.cpp
    int check_the_value(string message, string errorMessage,int minVal,int maxVal);  // checks if a give value is within range
    void print_to_file(vector<Studentas> list_of_students, string file_name);
    void adding_from_file_logic(string file_name, vector <Studentas> &student_list);
    string getPradziosTekstas();