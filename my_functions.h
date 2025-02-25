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

// fileRead.cpp
    string readFileToString();
    int wordCount(istringstream& iss);
    vector<Studentas> read_student_records(int ndCount, istringstream& iss);


//  student_functions.cpp
    vector<float> enter_grades_manually();
    void print_students(vector<Studentas> studentas);
    void insert_student(vector <Studentas> &student_list, Studentas &studentas);
    void sort_students(vector <Studentas> &student_list);
