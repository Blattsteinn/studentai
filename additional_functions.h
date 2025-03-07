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

// Generic helper for containers without a member sort
template<typename Container>
void sortGrades(Container& grades) {
    std::sort(grades.begin(), grades.end());
}

// Overload for std::list<float>
inline void sortGrades(std::list<float>& grades) {
    grades.sort();
}

template<template<typename, typename ...> class Container>
float median(Studentas temp){

    float mediana = 0; 
    if (temp.pazymiai.empty()) {
        cout << "[Klaida] Negalima apskaiciuoti vidurkio, nes nera ivertinimu. Mediana - 0" << endl;
        return 0;
    }

    sortGrades(temp.pazymiai);
    
    
    int pazymiu_kiekis = temp.pazymiai.size();

    if(pazymiu_kiekis % 2 == 1){ // Jeigu pazymiu skaicius yra nelyginis
        mediana = temp.pazymiai[pazymiu_kiekis / 2];
        return mediana;
    } 

    else{ // Jeigu pazymiu skaicius yra lyginis
        mediana = (temp.pazymiai[pazymiu_kiekis/2] + temp.pazymiai[pazymiu_kiekis/2 - 1 ]) / 2.0;
        return mediana;
    }
}
