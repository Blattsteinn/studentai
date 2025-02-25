#pragma once

#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <random>
#include <string>
#include <limits> // for std::numeric_limits
#include <fstream>
#include <sstream> // for buffer

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::sort;

using std::left;
using std::setw;
using std::fixed;
using std::setprecision;
using std::numeric_limits;
using std::streamsize;

using std::ifstream;
using std::istringstream;
using std::cerr;

struct Studentas{

    string vardas;
    string pavarde;

    vector<float> pazymiai;
    int egzaminoRezultatas;

    float galutinisVid;
    float galutinisMed;
};

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

