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
