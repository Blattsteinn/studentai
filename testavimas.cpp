#include "mano_lib.h"
#include "my_functions.h"

void generate_files(int student_size) { // size = 10^student_size
    auto start = std::chrono::high_resolution_clock::now();

    int size = pow(10, student_size);
    string file_name = "testavimasFailas" + std::to_string(size) + ".txt";
    std::ofstream output(file_name);

    int nd_to_generate = randomNumber(5,12);

    std::ostringstream buffer;
    buffer << std::left << std::setw(25) << "Vardas"
        << std::left << std::setw(27) << "Pavarde";

    for (int i = 1; i <= nd_to_generate; i++) {
        buffer << std::left << std::setw(10) << ("ND" + std::to_string(i));
    } buffer << '\n';

    for(int i = 1; i <= size; i++){
        string vardas = "VardasNr" + std::to_string(i);;
        string pavarde = "PavardeNr" + std::to_string(i);

        buffer << std::left << std::setw(25) << vardas
                  << std::left << std::setw(27) << pavarde;
                  
        for (int j = 0; j < nd_to_generate; j++) {
            buffer << std::left << std::setw(10) << randomNumber(1, 10);
        } buffer << '\n';
    }


    output << buffer.str();
    output.close();

    // ----
        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> reading_duration = end - start;
        cout << "Sukurtas " << file_name << " failas." << endl;
        std::cout << "Faila sukurti uztruko: " << reading_duration.count() << std::endl;
        cout << endl;
    // ----
}

vector<Studentas> divide_students(vector <Studentas> &list_of_students, int choice){
    // --- returns list of students whose final grade is below 5
    vector <Studentas> students;

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

}

void testing(vector <Studentas> &list_of_students){
    for(int i=3; i<=7; i++){

        int file_size = pow(10, i);
        string file_name = "testavimasFailas" + std::to_string(file_size) + ".txt";
        string file_path = "C:\\Users\\arnas\\Documents\\Studentu failu archyvas\\" + file_name;

        cout << "Testuojamas " << file_name << endl;
        cout << endl;

        // --- Nuskaitymas ---
            auto start = std::chrono::high_resolution_clock::now();
            adding_from_file_logic(file_path, list_of_students);
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
            vector<Studentas> worse_students = divide_students(list_of_students, 0); 
            vector<Studentas> good_students = divide_students(list_of_students, 1);

            list_of_students.clear(); // Deletes initial vector

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

        // bendras laikas
        cout << endl;
        cout << endl;
    }
}
