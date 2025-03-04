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

void print_to_file(vector<Studentas> list_of_students, string file_name){

    // Create an output string stream
    std::ostringstream buffer;

        buffer <<'\n' 
        << left << setw(15) << "Pavarde" 
        << setw(15) << "Vardas" 
        << setw(15) << "Galutinis (Vid.)  /  " 
        << setw(15) << "Galutinis (Med.)" 
        << "\n-------------------------------------------------------------\n";

    std::ofstream isvedimas(file_name);
    for (auto& s : list_of_students) {
        buffer << s;   //Check struct Studentas for printing logic

    }
    isvedimas << buffer.str();
    isvedimas.close();

}

string getPradziosTekstas() {
    return R"(
        [Programos eigos pasirinkimas]
        
1 - rankinis ivedimas, 
2 - generuoti pazymius, 
3 - generuoti ir pazymius, ir studentu vardus, pavardes, 
4 - nuskaityti duomenis is failo, 
5 - baigti darba

            [Pasirinkimas]: )";
}
