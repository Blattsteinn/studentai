#include "my_library.h"
#include "my_functions.h"

int main(){

    StudentContainer<Studentas> list_of_students;
    Studentas temp;   

    int program_choice{};
    
    while(true){ 
        
        program_choice = check_the_value(consoleText_userChoice(), "[Klaida] iveskite skaiciu nuo 1-5", 1, 5);
        cout << endl;

        temp.pazymiai.clear();
        if(program_choice == 5) { break; } // Nutraukiamas programos darbas
        switch(program_choice){
            case 1:   // 1 - ivedimas rankas
                cout << "Vardas: ";   cin >> temp.vardas;
                cout << "Pavarde: ";  cin >> temp.pavarde;

                    // --- Rankinis pazymiu ivedimas --- 
                temp.pazymiai = enter_grades_manually<StudentContainer>();
                temp.egzaminoRezultatas = check_the_value("Egzamino ivertinimas: ", "[Klaida] iveskite skaiciu nuo 1-10", 1, 10);
            
                calculate_everything(temp);
                insert_student(list_of_students, temp);

                break;

            case 2:   // 2 - atsitiktinis pazymiu generavimas
                cout << "Vardas: ";   cin >> temp.vardas;
                cout << "Pavarde: ";  cin >> temp.pavarde;

                temp.pazymiai = random_grade<StudentContainer>();
                temp.egzaminoRezultatas = randomNumber(1, 10); cout << "Egzamino rezultatas: " << temp.egzaminoRezultatas << endl;
                calculate_everything(temp);
                insert_student(list_of_students, temp);

                break;

            case 3:   // 3 - generuoti ir pazymius ir studentu vardus, pavardes
                temp.vardas = random_name<StudentContainer>();  cout << "Sugeneruotas vardas: " << temp.vardas << endl;
                temp.pavarde = random_last_name<StudentContainer>(); cout << "Sugeneruota pavarde: " << temp.pavarde << endl;
                temp.pazymiai = random_grade<StudentContainer>();
                temp.egzaminoRezultatas = randomNumber(1, 10); cout << "Egzamino rezultatas: " << temp.egzaminoRezultatas << endl;

                calculate_everything(temp);
                insert_student(list_of_students, temp);
                break;

            case 4: {   // 4 - skaityti duomenu faila
                appendingContainerViaFile("kursiokai.txt", list_of_students);
                cout << "Duomenys sekmingai nuskaityti is failo" << endl;

                break;  
            }

            default:
                // The program shouldn't reach this point
            break;

        }
    }


    sort_students(list_of_students);

    //print_students(list_of_students);
    print_to_file(list_of_students, "rezultatai.txt");

    return 0;

}