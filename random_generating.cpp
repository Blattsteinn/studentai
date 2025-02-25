#include "mano_lib.h"

int randomNumber(int a, int b) {
    static std::mt19937 gen{std::random_device{}()}; // paleidziama tik karta
    std::uniform_int_distribution<int> distr(a, b);
    return distr(gen);
}

vector<float> random_grade(){
    Studentas laikinas;

    char testiGeneravima;
    int pazymiuSekimas = 1;  //Seka kiek vartotojas ivede pazymiu

    while(true){
        cout << "Generate a new grade? [y/n]: "; cin >> testiGeneravima;
        if(testiGeneravima != 'n' && testiGeneravima != 'N'){ 
            int atsitiktinisPazymys = randomNumber(1, 10);
            laikinas.pazymiai.push_back(atsitiktinisPazymys);
            cout << pazymiuSekimas << " generated grade: "  << atsitiktinisPazymys << endl; pazymiuSekimas++;
            }
        else{
            break; 
        }               
    }

    return laikinas.pazymiai;
}

string random_name() {
    vector<string> vardai = {"John", "Alice", "Michael", "Emily", "David", "Sophia"};

    return vardai[randomNumber(0, vardai.size()-1)];
}

string random_last_name() {
    vector<string> pavardes = {"Smith", "Johnson", "Brown", "Williams", "Jones", "Miller"};

    return pavardes[randomNumber(0, pavardes.size()-1)];
}

