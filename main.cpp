#include "mano_lib.h"
#include "my_functions.h"

int reiksmesTikrinimas(string zinute, string klaidosZinute,int minVal,int maxVal){
    while (true)
    {
        cout << zinute;
        int value;
        if (!(cin >> value))
        {
            cout << klaidosZinute << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        if (value < minVal || value > maxVal) //Tikrinama ar atitinka rezius
        {
            cout << klaidosZinute << endl;
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return value;//Jei skaicius tenkina salyga, jis - grazinamas
    }
}


int main(){

    vector<Studentas> studentas;

    Studentas laikinas;   
    int pasirinkimas{};
    
    while(true){ 
        
        string pradzios_tekstas = R"([Programos eigos pasirinkimas]
1 - rankinis ivedimas, 
2 - generuoti pazymius, 
3 - generuoti ir pazymius, ir studentu vardus, pavardes, 
4 - nuskaityti duomenis is failo, 
5 - baigti darba
        [Pasirinkimas]: )";

        pasirinkimas = reiksmesTikrinimas(pradzios_tekstas, "[Klaida] iveskite skaiciu nuo 1-5", 1, 5);

        laikinas.pazymiai.clear();
        if(pasirinkimas == 5) { break; } // Nutraukiamas programos darbas
        switch(pasirinkimas){
            case 1:   // 1 - ivedimas rankas
                cout << "Vardas: ";   cin >> laikinas.vardas;
                cout << "Pavarde: ";  cin >> laikinas.pavarde;

                    // --- Rankinis pazymiu ivedimas --- 
                laikinas.pazymiai = enter_grades_manually();
                laikinas.egzaminoRezultatas = reiksmesTikrinimas("Egzamino ivertinimas: ", "[Klaida] iveskite skaiciu nuo 1-10", 1, 10);
                insert_student(studentas, laikinas);
                break;

            case 2:   // 2 - atsitiktinis pazymiu generavimas
                cout << "Vardas: ";   cin >> laikinas.vardas;
                cout << "Pavarde: ";  cin >> laikinas.pavarde;

                    // --- Atsitiktinis pazymiu ivedimas --- 
                laikinas.pazymiai = random_grade();
                laikinas.egzaminoRezultatas = randomNumber(1, 10); cout << "Egzamino rezultatas: " << laikinas.egzaminoRezultatas << endl;
                insert_student(studentas, laikinas);
                break;

            case 3:   // 3 - generuoti ir pazymius ir studentu vardus, pavardes
                laikinas.vardas = random_name();  cout << "Sugeneruotas vardas: " << laikinas.vardas << endl;
                laikinas.pavarde = random_last_name(); cout << "Sugeneruota pavarde: " << laikinas.pavarde << endl;
                laikinas.pazymiai = random_grade();
                laikinas.egzaminoRezultatas = randomNumber(1, 10); cout << "Egzamino rezultatas: " << laikinas.egzaminoRezultatas << endl;
                insert_student(studentas, laikinas);
                break;

            case 4: {                
                try {
                    string content = readFileToString();
                    istringstream iss(content);
                    int ndCount = wordCount(iss);

                    vector<Studentas> studentList = read_student_records(ndCount, iss);
                    for( auto student : studentList){
                        laikinas.vardas = student.vardas;
                        laikinas.pavarde = student.pavarde;
                        insert_student(studentas, student);
                    }
                
                } catch (const char* msg) {
                    cerr << msg << endl;
                }
                
            }
        
            default:
                // The program shouldn't reach this point
            break;
        }

        char choice;
        cout << "\nIvesti daugiau studentu? [y/n]: "; cin >>  choice; cout << '\n';
        if(choice == 'n' || choice == 'N'){ break; }
    }

    sort_students(studentas);
    print_students(studentas);

    return 0;

}