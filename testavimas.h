#pragma once

#include "my_library.h"
#include "my_functions.h"

    // Template function to measure the execution time of any callable
    template<typename Func>
    double measureTime(Func func) {
        auto start = std::chrono::high_resolution_clock::now();
        func();
        auto end = std::chrono::high_resolution_clock::now();
        return std::chrono::duration<double>(end - start).count();
    }

// --- Divides students into two groups & splits them to seperate containers ---
    template <template<typename, typename...> class Container>
    Container<Studentas> divide_students_unoptimized(const Container<Studentas>& list_of_students, int choice) {

        Container <Studentas> students;

        // --- returns list of students whose final grade is below 5
        if(choice == 0) { 
        for(auto student : list_of_students){
            if (student.galutinisVid < 5){
                students.push_back(student);
            }
        }
        return students;
        }

        // --- returns list of students whose final grade is above 5
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
    Container<Studentas> divide_students_optimized(const Container<Studentas>& list_of_students, int choice) {
        Container<Studentas> filtered;
        
        if(choice == 0) {
            // Copy students with final grade below 5.
            std::copy_if(list_of_students.begin(), list_of_students.end(),
                        std::back_inserter(filtered),
                        [](const Studentas &s) { return s.galutinisVid < 5; });
        } else if(choice == 1) {
            // Copy students with final grade 5 or above.
            std::copy_if(list_of_students.begin(), list_of_students.end(),
                        std::back_inserter(filtered),
                        [](const Studentas &s) { return s.galutinisVid >= 5; });
        }
        return filtered;
    }


// --- Strategy 1 ---

    template <template<typename, typename...> class Container>
    void strategy_1(){
        for(int i=3; i<=7; i++){

            int file_size = pow(10, i);
            Container<Studentas> list_of_students;
        
            string file_name = "testavimasFailas" + std::to_string(file_size) + ".txt";
            string file_path = "C:\\Users\\arnas\\Documents\\Studentu failu archyvas\\" + file_name;

            cout << "--------------------------- Testuojamas " << file_name << endl; cout << endl;
            auto overall_start = std::chrono::high_resolution_clock::now();   /// <--- sparta pradedama skaiciuoti cia
            double readingTime;

            // --- Reading ---
                readingTime = measureTime([&]() {
                    appendingContainerViaFile(file_path, list_of_students);
                });
                    cout << "Reading time: " << readingTime << "s" << endl;

            // --- Sorting ---
                readingTime = measureTime([&]() {
                    sort_students(list_of_students, 3);
                });
                    cout << "Sorting time: " << readingTime << "s" << endl;

            

            // --- Splits students between two groups ---

            Container<Studentas> worse_students;
            Container<Studentas> good_students;

                readingTime = measureTime([&]() {
                    worse_students = divide_students_unoptimized(list_of_students, 0); 
                    good_students = divide_students_unoptimized(list_of_students, 1);
                    });
                        cout << "Grouping time: " << readingTime << "s" << endl;


                list_of_students.clear(); // Deletes initial container

            // --- Bendras skaitymo laikas

                    auto overall_end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double> overall = overall_end - overall_start;
                    std::cout << "Overall reading time: " << overall.count() << "s" << std::endl;

            cout << endl;
            cout << endl;

            worse_students.clear();
            good_students.clear();
        }
    }

// --- Strategy 2 ---

    template <template<typename, typename...> class Container>
    void strategy_2(){
        for(int i=3; i<=7; i++){

            int file_size = pow(10, i);
            Container<Studentas> list_of_students;
        
            string file_name = "testavimasFailas" + std::to_string(file_size) + ".txt";
            string file_path = "C:\\Users\\arnas\\Documents\\Studentu failu archyvas\\" + file_name;

            cout << "--------------------------- Testuojamas " << file_name << endl; cout << endl;
            auto overall_start = std::chrono::high_resolution_clock::now();   /// <--- sparta pradedama skaiciuoti cia
            double readingTime;

            // --- Reading ---
                readingTime = measureTime([&]() {
                    appendingContainerViaFile(file_path, list_of_students);
                });
                    cout << "Reading time: " << readingTime << "s" << endl;

            // --- Sorting ---
                readingTime = measureTime([&]() {
                    sort_students(list_of_students, 3);
                });
                    cout << "Sorting time: " << readingTime << "s" << endl;

            

            // --- Splits students between two groups ---
            // -- Creates a seperate container for worse students

            Container<Studentas> worse_students;

                readingTime = measureTime([&]() {
                    for(auto it = list_of_students.begin(); it != list_of_students.end(); ) {
                        if (it->galutinisVid < 5) {
                            worse_students.push_back(*it);
                            it = list_of_students.erase(it); // erase returns the next valid iterator
                        } else {
                            ++it;
                        }
                    }

                    });
                    cout << "Grouping time: " << readingTime << "s" << endl;


                list_of_students.clear(); // Deletes initial container

            // --- Bendras skaitymo laikas

                    auto overall_end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double> overall = overall_end - overall_start;
                    std::cout << "Overall reading time: " << overall.count() << "s" << std::endl;

            cout << endl;
            cout << endl;

            worse_students.clear();
            good_students.clear();
        }
    }


// --- Strategy 3 ---

    template <template<typename, typename...> class Container>
    void strategy_3(){
 
    
}