#pragma once

#include "my_library.h"

// --- Reads the entire file into a string in a universal way ---
    template <template<typename, typename...> class Container>
    string readFileToString(string file_name){

        // Opens the file in binary mode - ensures that you always get the exact content
        ifstream file(file_name, std::ios::binary);
        if (!file) {
            throw "[Klaida] Failas neegzistuoja / neatsidaro.\n";
        }
        
        // Create an empty container.
        Container<char> buffer;
        
        // Use back_inserter to insert all characters from the file into the container.
        std::copy(std::istreambuf_iterator<char>(file),
                std::istreambuf_iterator<char>(),
                std::back_inserter(buffer));
        
        // Convert the container to a string.
        string content(buffer.begin(), buffer.end());
        return content;
    }


// --- Counts the number of ND (NDn) in the header ---
    template <template<typename, typename...> class Container>
    int wordCount(istringstream& iss){

        // Read the header line
        string header;
        std::getline(iss, header);
        
        // Splits the header into words
        istringstream headerStream(header); 

        Container<string> wordContainer;
        string word;

        while (headerStream >> word) {
            wordContainer.push_back(word);
        }
        
        // Ensure that the header has at least three words (name, lastName & exam score)
        if (wordContainer.size() < 3) {
            throw "[Klaida] Neteisinga failo antraste.";
            return -1;
        }

        // ND count is total number of words minus 3 (name, lastName & exam score)
        int ndCount = wordContainer.size() - 3;
        // cout << "ND count from header: " << ndCount << "\n";  // <-- Testing

        return ndCount;
    }


// --- Reads student records  ---   
    //  ndCount - instances of NDn in the file; &iss - stream of the file.
    //  Skips processing further records if any record is malformed.
    //  Returns a container of Studentas objects 

    template<template<typename, typename ... > class Container>
    Container<Studentas> read_student_records(int ndCount, istringstream& iss){

            
            Container<Studentas> records;
            int line = 1;
            while (true) {
                Studentas r;
                if (!(iss >> r.vardas >> r.pavarde))
                    break;  // End of file or read error.
        
                // Resizes the 'container<float> pazymiai' to the expected number of values.
                r.pazymiai.resize(ndCount);
        
                bool success = true;
                for (int i = 0; i < ndCount; i++) {
                    float grade;
                    if (!(iss >> grade)) {
                        throw "[Klaida] Netinkamas duomenu failas!";
                    }
                    r.pazymiai.push_back(grade);
                }

                if (!success)
                    break;
                
                // Exam score.
                if (!(iss >> r.egzaminoRezultatas)){
                    throw "[Klaida] Netinkamas duomenu failas!";
                }
                    
                
                // Add the record to the container.
                records.push_back(r);
                line++;
            }
            //Returns all the students & their information
            return records; 
    }


// --- Appends the student container and calculates everything ---
    // file_name - needed .txt file
    // &student_list - container of Student structs

    template<template<typename,typename ...> class Container>
    void appendingContainerViaFile(string file_name, Container <Studentas> &student_list){
        {   
            Studentas temp;
            try{
                string content = readFileToString<Container>(file_name);
                istringstream iss(content);  // Stream for parsing the file
                int ndCount = wordCount<Container>(iss);
            
        
                Container<Studentas> studentList = read_student_records<Container>(ndCount, iss);
                for( auto student : studentList){
                    temp.vardas = student.vardas;
                    temp.pavarde = student.pavarde;
                    calculate_everything(student);
                    insert_student(student_list, student);
                }
            } catch (const char* msg) {
                cerr << msg << endl;
            }
        }
    }
