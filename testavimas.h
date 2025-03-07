#pragma once

#include "mano_lib.h"
#include "my_functions.h"

template <template<typename, typename... > class Container>
Container<Studentas> divide_students(const Container <Studentas> &list_of_students, int choice){
    // --- returns list of students whose final grade is below 5
    Container <Studentas> students;

    if(choice == 0) { 
    for(auto student : list_of_students){
        if (student.galutinisVid < 5){
            students.push_back(student);
        }
    }
    return students;
    }

    else if(choice == 1) { 
        for(auto student : list_of_students){
            if (student.galutinisVid >= 5){
                students.push_back(student);
            }
        }
        return students;
    }
    return students;
}


template <template<typename, typename...> class Container>
void testing(){
    for(int i=3; i<=7; i++){
        auto overall_start = std::chrono::high_resolution_clock::now();

        int file_size = pow(10, i);
        Container<Studentas> list_of_students;
     
        string file_name = "testavimasFailas" + std::to_string(file_size) + ".txt";
        string file_path = "C:\\Users\\arnas\\Documents\\Studentu failu archyvas\\" + file_name;

        cout << "Testuojamas " << file_name << endl;
        cout << endl;

        // --- Nuskaitymas ---
            auto start = std::chrono::high_resolution_clock::now();
            appendingContainerViaFile(file_path, list_of_students);
            auto end = std::chrono::high_resolution_clock::now();

            std::chrono::duration<double> reading_duration = end - start;
            std::cout << "Skaitymo laikas: " << reading_duration.count() << "s" << std::endl;

        // --- Rusiavimas ---
            start = std::chrono::high_resolution_clock::now();
            sort_students(list_of_students, 3);
            end = std::chrono::high_resolution_clock::now();

            std::chrono::duration<double> sorting_duration = end - start;
            std::cout << "Rikiavimo laikas: " << sorting_duration.count() << "s" << std::endl;

        // --- Skaidymas i dvi grupes ---
            start = std::chrono::high_resolution_clock::now();

             // -- Splits students between two groups
            Container<Studentas> worse_students = divide_students(list_of_students, 0); 
            Container<Studentas> good_students = divide_students(list_of_students, 1);
            if(worse_students.size() == 0 || good_students.size() == 0){
                return;
            }

            list_of_students.clear(); // Deletes initial container

            end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> dividing_groups_duration = end - start;
            std::cout << "Skaidymo i dvi grupes laikas: " << dividing_groups_duration.count() << "s" << std::endl;

        // --- Studentai, kurių galutinis balas < 5.0 isrinkimas ir irasymas i nauja faila ---
            start = std::chrono::high_resolution_clock::now();
            print_to_file(worse_students, "vargsiukai" + std::to_string(file_size) + ".txt");

            end = std::chrono::high_resolution_clock::now();

            std::chrono::duration<double> worse_group_duration = end - start;
            std::cout << "Vargsiuku irasymas i faila laikas: " << worse_group_duration.count() << "s" << std::endl;

        // --- Studentai, kurių galutinis balas >= 5.0 isrinkimas ir irasymas i nauja faila---
            start = std::chrono::high_resolution_clock::now();
            print_to_file(good_students,  "kietuoliai" + std::to_string(file_size) + ".txt");

            end = std::chrono::high_resolution_clock::now();
            
            std::chrono::duration<double> good_group_duration = end - start;
            std::cout << "Kietuoliu irasymas i faila laikas: " << good_group_duration.count() << "s" << std::endl;

        // --- Bendras skaitymo laikas
            auto overall_end = std::chrono::high_resolution_clock::now();

            std::chrono::duration<double> overall = overall_end - overall_start;
            std::cout << "Bendras skaitymo laikas: " << overall.count() << "s" << std::endl;

        cout << endl;
        cout << endl;
    }
}