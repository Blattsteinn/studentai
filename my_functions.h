#pragma once

#include "my_library.h"

    string consoleText_userChoice();

    int randomNumber(int a, int b);
    int check_the_value(string message, string errorMessage,int minVal,int maxVal);  // checks if a give value is within range
    float average(Studentas laikinas);

    void calculate_everything(Studentas &laikinas);

    void generate_files(int student_size);

    #include "random_generating.h"
    #include "fileRead.h"
    #include "student_functions.h"
    #include "additional_functions.h"
    #include "testavimas.h"