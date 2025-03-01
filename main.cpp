#include "mano_lib.h"
#include "my_functions.h"

string pradzios_tekstas = getPradziosTekstas();

void generate_files(){
    std::ofstream output("testavimoFailas.txt");

    int nd_to_generate = randomNumber(5,9);
    string header = "Vardas                   Pavarde                    ";

    for(int i = 1; i <= nd_to_generate; i++){
        header += "ND" + std::to_string(i) +  "       ";
    } header += '\n';

    output << header;

    for(int i = 1; i <= 10; i++){
        string vardas = "VardasNr" + std::to_string(i);;
        string pavarde = "PavardeNr" + std::to_string(i);

        // Print names with fixed width, right-padded with spaces
        output << std::left << std::setw(25) << vardas
                  << std::left << std::setw(27) << pavarde;
                  
        for(int i = 0; i < nd_to_generate; i++){
            output <<  std::left << std::setw(10) << randomNumber(1,10);
        } output << endl;
    }


    output.close();

}

int main(){

    vector<Studentas> list_of_students;
    Studentas temp;   

    int program_choice{};
    
    generate_files();

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
                try {
                    string content = readFileToString("kursiokai.txt");   // "kursiokai.txt"
                    istringstream iss(content);
                    int ndCount = wordCount(iss);

                    vector<Studentas> studentList = read_student_records(ndCount, iss);
                    for( auto student : studentList){
                        temp.vardas = student.vardas;
                        temp.pavarde = student.pavarde;

                        calculate_everything(student);
                        insert_student(list_of_students, student);
                    }
                
                } catch (const char* msg) {
                    cerr << msg << endl;
                }
                cout << "Duomenys nuskaityti is failo" << endl;
                break;  
            }

            case 6: {  
                try {
                    time_t start = time(nullptr);
                    testavimas("C:\\Users\\arnas\\Documents\\studentai10000.txt", list_of_students);
                    time_t end = time(nullptr);
                    double a1 = end - start;           
                    cout << "1 failas, sugaista: " << a1 << " sekundes." << endl;
            
                    start = time(nullptr);
                    testavimas("C:\\Users\\arnas\\Documents\\studentai100000.txt", list_of_students);
                    end = time(nullptr);
                    double a2 = end - start;           
                    cout << "2 failas, sugaista: " << a2 << " sekundes." << endl;
            
                    start = time(nullptr);
                    testavimas("C:\\Users\\arnas\\Documents\\studentai1000000.txt", list_of_students);
                    end = time(nullptr);
                    double a3 = end - start;           
                    cout << "3 failas, sugaista: " << a3 << " sekundes." << endl;
            
                    cout << "Vidutinis testavimo laikas: " << (a1 + a2 + a3) / 3 << " sekundes." << endl;
            
                } catch (const char* msg) {
                    std::cerr << msg << std::endl;
                }

                break;
            }
            
            default:
                // The program shouldn't reach this point
            break;
        }
    }

    sort_students(list_of_students);

    //print_students(list_of_students);
    print_to_file(list_of_students);

    return 0;

}