#include "mano_lib.h"
#include "my_functions.h"

string pradzios_tekstas = getPradziosTekstas();

template <typename T>
using Container = std::deque<T>;

int main(){

    Container<Studentas> list_of_students;
    Studentas temp;   

    // testing<Container>();
    for(int i=3;i<=7; i++){
        generate_files(i);
    }


    int program_choice{};
    
    while(false){ 
        
        program_choice = check_the_value(pradzios_tekstas, "[Klaida] iveskite skaiciu nuo 1-5", 1, 5);
        cout << endl;

        temp.pazymiai.clear();
        if(program_choice == 5) { break; } // Nutraukiamas programos darbas
        switch(program_choice){
            case 1:   // 1 - ivedimas rankas
                cout << "Vardas: ";   cin >> temp.vardas;
                cout << "Pavarde: ";  cin >> temp.pavarde;

                    // --- Rankinis pazymiu ivedimas --- 
                temp.pazymiai = enter_grades_manually<Container>();
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