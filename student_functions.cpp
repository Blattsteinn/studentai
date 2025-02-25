#include "mano_lib.h"
#include "my_functions.h"
int reiksmesTikrinimas(string zinute, string klaidosZinute,int minVal,int maxVal);

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

void print_students(vector<Studentas> studentas){

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
