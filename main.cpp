#include "mano_lib.h"

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

vector<float> enter_grades_manually(){
    Studentas laikinas;

    float ivertinimas;
    int pazymiuSekimas = 1;  //Seka kiek vartotojas ivede pazymiu

    cout << "[Pazymiu ivedimas] ivedant -1 nutraukiamas darbas" << endl;
        while(true){
            string tekstas = std::to_string(pazymiuSekimas) + " pazymys: ";
            
            ivertinimas = reiksmesTikrinimas(tekstas, "[Klaida] ivertinimo ribos nuo 1 iki 10", -1, 10);

            if(ivertinimas == -1){ break; }  //nutraukimas
            else if (ivertinimas == 0 ){ cout << "[Klaida] ivertinimo ribos nuo 1 iki 10" << endl; continue; }

            pazymiuSekimas++;
            laikinas.pazymiai.push_back(ivertinimas);

            }

    return laikinas.pazymiai;
}

void spausdinimas(vector<Studentas> studentas){

    // Create an output string stream
    std::ostringstream buffer;

        buffer <<'\n' 
        << left << setw(15) << "Pavarde" 
        << setw(15) << "Vardas" 
        << setw(15) << "Galutinis (Vid.)  /  " 
        << setw(15) << "Galutinis (Med.)" 
        << "\n-------------------------------------------------------------\n";

    for (auto& s : studentas) {
        buffer << left << setw(15) << s.pavarde
            << setw(15) << s.vardas
            << fixed << setprecision(2) << setw(22) << s.galutinisVid
            << fixed << setprecision(2) << setw(15) << s.galutinisMed
            << "\n";
    }

    // Print the entire buffered content at once
    cout << buffer.str();
}

/* --- Inserts a student into vector<Studentas>  ---   
                              vector <Studentas> &student_target - vector, which we want to expand
                              Studentas &studentas - information of the student, (Grades, exam score) */
void insert_student(vector <Studentas> &student_list, Studentas &studentas){
    Studentas laikinas = studentas; // Copy the student

    laikinas.galutinisVid = average(laikinas) * 0.4 + laikinas.egzaminoRezultatas *0.6;
    laikinas.galutinisMed = median(laikinas) * 0.4 + laikinas.egzaminoRezultatas *0.6;
    student_list.push_back(laikinas);

}

/* --- Sorts students depending on user input  ---   
                              vector <Studentas> &student_target - vector, which we want to sort */
void sort_students(vector <Studentas> &student_list){
    string rikiavimo_pasirinkimas = R"([Programos eigos pasirinkimas]
    1 - sort students by name, 
    2 - sort students by last name, 
    3 - sort students by overall (mean)
    4 - sort students by overall (median)
            [Choice]: )";
    
    int choice = reiksmesTikrinimas(rikiavimo_pasirinkimas, "[Error] Choose a number between 1-4", 1, 4);

    switch(choice){
        case 1:
           sort(student_list.begin(), student_list.end(), []( Studentas &a,  Studentas &b) {
                return a.vardas < b.vardas; });
            break;
        case 2:
            sort(student_list.begin(), student_list.end(), []( Studentas &a,  Studentas &b) {
                return a.pavarde < b.pavarde; });
            break;
        case 3:
            sort(student_list.begin(), student_list.end(), []( Studentas &a,  Studentas &b) {
                return a.galutinisVid > b.galutinisVid; });
            break;
        case 4:
            sort(student_list.begin(), student_list.end(), []( Studentas &a,  Studentas &b) {
                return a.galutinisMed > b.galutinisMed; });
            break;
        default:
        break;
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
                string content = readFileToString();
                if (content.empty() || content == "[ERROR]") {
                    cerr << "[Error] The file is empty or an error has occured. Exiting.\n";
                    break;
                }
            
                istringstream iss(content);  // Stream for parsing the file
            
                int ndCount = wordCount(iss);
                if (ndCount < 0) {
                    cerr << "[Error] Header is invalid. Exiting.\n";
                    break;
                }
            
                vector<Studentas> studentList = read_student_records(ndCount, iss);
                for( auto student : studentList){
                    laikinas.vardas = student.vardas;
                    laikinas.pavarde = student.pavarde;
                    insert_student(studentas, student);
                }
                
            }
        
            default:
                // The program shouldn't reach this point
            break;
        }

        char choice;
        cout << "Ivestini kita studenta? y/n: "; cin >>  choice;
        if(choice == 'n' || choice == 'N'){ break; }
    }

    sort_students(studentas);
    spausdinimas(studentas);

    return 0;

}