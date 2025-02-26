#include "mano_lib.h"
#include "my_functions.h"


int check_the_value(string message, string errorMessage,int minVal,int maxVal){
    while (true)
    {
        cout << message;
        int value; 
        if (!(cin >> value)){  // <-- if cin fails
            cout << errorMessage << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;  // <-- prompt back again
        }

        if (value < minVal || value > maxVal){  // <-- if the number is not within the given range 
            cout << errorMessage << endl;
            continue;  // <-- prompt back again
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return value;
    }
}

void print_to_file(vector<Studentas> list_of_students){

    // Create an output string stream
    std::ostringstream buffer;

        buffer <<'\n' 
        << left << setw(15) << "Pavarde" 
        << setw(15) << "Vardas" 
        << setw(15) << "Galutinis (Vid.)  /  " 
        << setw(15) << "Galutinis (Med.)" 
        << "\n-------------------------------------------------------------\n";

    std::ofstream isvedimas("isvedimas.txt");
    for (auto& s : list_of_students) {
        buffer << s;   //Check struct Studentas for printing logic

    }
    isvedimas << buffer.str();
    isvedimas.close();
    cout << "\n Studentu informacija issaugota faile isvedimas.txt" << endl;
}

void testavimas(string file_name, vector <Studentas> &student_list){
    {   
        Studentas temp;
        try{
            string content = readFileToString(file_name);
            istringstream iss(content);  // Stream for parsing the file
            int ndCount = wordCount(iss);
        
    
            vector<Studentas> studentList = read_student_records(ndCount, iss);
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

string getPradziosTekstas() {
    return R"(
        [Programos eigos pasirinkimas]
    1 - rankinis ivedimas, 
    2 - generuoti pazymius, 
    3 - generuoti ir pazymius, ir studentu vardus, pavardes, 
    4 - nuskaityti duomenis is failo, 
    5 - baigti darba

    6 - testavimas
            [Pasirinkimas]: )";
}
