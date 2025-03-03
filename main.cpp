#include "mano_lib.h"
#include "my_functions.h"

string pradzios_tekstas = getPradziosTekstas();


void generate_files(int student_size) { // size = 10^student_size

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

    // Write any remaining data
    output << buffer.str();

    output.close();
    cout << "sukurtas " << file_name << " failas!" << endl;
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
            std::cout << "Reading execution time: " << reading_duration.count() << " seconds" << std::endl;

        // --- Rusiavimas ---
            start = std::chrono::high_resolution_clock::now();
            sort_students(list_of_students, 3);
            end = std::chrono::high_resolution_clock::now();

            std::chrono::duration<double> sorting_duration = end - start;
            std::cout << "Sorting execution time: " << sorting_duration.count() << " seconds" << std::endl;

        // --- Skaidymas i dvi grupes ---
            start = std::chrono::high_resolution_clock::now();
             // -- Splits students between two groups
            vector<Studentas> worse_students = divide_students(list_of_students, 0); 
            vector<Studentas> good_students = divide_students(list_of_students, 1);

            list_of_students.clear(); // Deletes initial vector

            end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> dividing_groups_duration = end - start;
            std::cout << "Dividing groups execution time: " << dividing_groups_duration.count() << " seconds" << std::endl;

        // --- Studentai, kurių galutinis balas < 5.0 isrinkimas ir irasymas i nauja faila ---
            start = std::chrono::high_resolution_clock::now();
            print_to_file(worse_students, "rezultatasBad" + std::to_string(file_size) + ".txt");

            end = std::chrono::high_resolution_clock::now();

            std::chrono::duration<double> worse_group_duration = end - start;
            std::cout << "Writing worse group to a file: " << worse_group_duration.count() << " seconds" << std::endl;

        // --- Studentai, kurių galutinis balas >= 5.0 isrinkimas ir irasymas i nauja faila---
            start = std::chrono::high_resolution_clock::now();
            print_to_file(good_students, "rezultatasGood" + std::to_string(file_size) + ".txt");

            end = std::chrono::high_resolution_clock::now();
            
            std::chrono::duration<double> good_group_duration = end - start;
            std::cout << "Writing better group to a file: " << good_group_duration.count() << " seconds" << std::endl;

        // bendras laikas
        cout << endl;
        cout << endl;
    }
}


int main(){

    vector<Studentas> list_of_students;
    Studentas temp;   

    testing(list_of_students);

    int program_choice{};
    
    while(false){ 
        
        program_choice = check_the_value(pradzios_tekstas, "[Klaida] iveskite skaiciu nuo 1-5", 1, 6);
        cout << endl;

        temp.pazymiai.clear();
        if(program_choice == 5) { break; } // Nutraukiamas programos darbas
        switch(program_choice){
            case 1:   // 1 - ivedimas rankas
                cout << "Vardas: ";   cin >> temp.vardas;
                cout << "Pavarde: ";  cin >> temp.pavarde;

                    // --- Rankinis pazymiu ivedimas --- 
                temp.pazymiai = enter_grades_manually();
                temp.egzaminoRezultatas = check_the_value("Egzamino ivertinimas: ", "[Klaida] iveskite skaiciu nuo 1-10", 1, 10);
            
                calculate_everything(temp);
                insert_student(list_of_students, temp);

                break;

            case 2:   // 2 - atsitiktinis pazymiu generavimas
                cout << "Vardas: ";   cin >> temp.vardas;
                cout << "Pavarde: ";  cin >> temp.pavarde;

                temp.pazymiai = random_grade();
                temp.egzaminoRezultatas = randomNumber(1, 10); cout << "Egzamino rezultatas: " << temp.egzaminoRezultatas << endl;
                calculate_everything(temp);
                insert_student(list_of_students, temp);

                break;

            case 3:   // 3 - generuoti ir pazymius ir studentu vardus, pavardes
                temp.vardas = random_name();  cout << "Sugeneruotas vardas: " << temp.vardas << endl;
                temp.pavarde = random_last_name(); cout << "Sugeneruota pavarde: " << temp.pavarde << endl;
                temp.pazymiai = random_grade();
                temp.egzaminoRezultatas = randomNumber(1, 10); cout << "Egzamino rezultatas: " << temp.egzaminoRezultatas << endl;

                calculate_everything(temp);
                insert_student(list_of_students, temp);
                break;

            case 4: {   // 4 - skaityti duomenu faila
                adding_from_file_logic("kursiokai.txt", list_of_students);
                cout << "Duomenys sekmingai nuskaityti is failo" << endl;

                break;  
            }

            default:
                // The program shouldn't reach this point
            break;

            case 6: {

             }
        }
    }


    // sort_students(list_of_students);
    //print_students(list_of_students);

    //print_to_file(list_of_students, "kursiokai.txt");

    return 0;

}