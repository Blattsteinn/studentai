#include "mano_lib.h"
#include "my_functions.h"

vector<float> enter_grades_manually(){
    Studentas temp;

    float grade;
    int track_grades = 1;  //Seka kiek vartotojas ivede pazymiu

    cout << "[Pazymiu ivedimas] ivedant -1 nutraukiamas darbas" << endl;
    while(true){

        string temp_text = std::to_string(track_grades) + " pazymys: ";
            
        grade = check_the_value(temp_text, "[Klaida] ivertinimo ribos nuo 1 iki 10", -1, 10);

        if(grade == -1){ 
            break; 
        }
        else if (grade == 0 ){ 
            cout << "[Klaida] ivertinimo ribos nuo 1 iki 10" << endl; 
            continue; 
        }

        track_grades++;
        temp.pazymiai.push_back(grade);
    }

    return temp.pazymiai;

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
        buffer << s;
    }

    // Print the entire buffered content at once
    cout << buffer.str();
}

// --- Inserts a student into vector<Studentas>  ---  
void insert_student(vector <Studentas> &student_list, Studentas &student){
    Studentas temp = student; // Copy the student
    student_list.push_back(temp);
}

// --- Sorts students depending on user input  ---   
void sort_students(std::vector<Studentas> &student_list) {
    std::string rikiavimo_pasirinkimas = R"([Rikiavimo pasirinkimas]
    1 - rikiuoti pagal vardus (abeceliskai), 
    2 - rikiuoti pagal pavardes (abeceliskai),
    3 - rikiuoti pagal vidurki (mazejant),
    4 - rikiuoti pagal mediana (mazejant),
            [Pasirinkimas]: )";
    
    int choice = check_the_value(rikiavimo_pasirinkimas, "[Klaida] Pasirinkite skaiciu tarp [1-4]", 1, 4);

    switch (choice) {
        case 1:
            sort(student_list.begin(), student_list.end(),
                      [](const Studentas &a, const Studentas &b) { return a.vardas < b.vardas; });
            break;
        case 2:
            sort(student_list.begin(), student_list.end(),
                      [](const Studentas &a, const Studentas &b) { return a.pavarde < b.pavarde; });
            break;
        case 3:
            sort(student_list.begin(), student_list.end(),
                      [](const Studentas &a, const Studentas &b) { return a.galutinisVid > b.galutinisVid; });
            break;
        case 4:
            sort( student_list.begin(), student_list.end(),
                      [](const Studentas &a, const Studentas &b) { return a.galutinisMed > b.galutinisMed; });
            break;
        default:
            break;
    }
}

void sort_students(std::vector<Studentas> &student_list, int choice) {

    switch (choice) {
        case 1:
            sort(student_list.begin(), student_list.end(),
                      [](const Studentas &a, const Studentas &b) { return a.vardas < b.vardas; });
            break;
        case 2:
            sort(student_list.begin(), student_list.end(),
                      [](const Studentas &a, const Studentas &b) { return a.pavarde < b.pavarde; });
            break;
        case 3:
            sort(student_list.begin(), student_list.end(),
                      [](const Studentas &a, const Studentas &b) { return a.galutinisVid > b.galutinisVid; });
            break;
        case 4:
            sort( student_list.begin(), student_list.end(),
                      [](const Studentas &a, const Studentas &b) { return a.galutinisMed > b.galutinisMed; });
            break;
        default:
            break;
    }
}
