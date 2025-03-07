#pragma once

#include "mano_lib.h"
#include "my_functions.h"


template <template<typename, typename...> class Container>
void print_to_file(Container<Studentas> list_of_students, string file_name){

    // Create an output string stream
    std::ostringstream buffer;

        buffer <<'\n' 
        << left << setw(15) << "Pavarde" 
        << setw(15) << "Vardas" 
        << setw(15) << "Galutinis (Vid.)  /  " 
        << setw(15) << "Galutinis (Med.)" 
        << "\n-------------------------------------------------------------\n";

    std::ofstream isvedimas(file_name);
    for (auto& s : list_of_students) {
        buffer << s;   //Check struct Studentas for printing logic

    }
    isvedimas << buffer.str();
    isvedimas.close();

}
