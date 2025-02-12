#include <iostream>
#include <iostream>
#include <vector>
#include <iomanip>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;

struct Studentas{

    string vardas;
    string pavarde;

    vector<float> pazymiai;
    int egzaminoRezultatas;

    float galutinisVid;
    float galutinisMed;
};


int main() {
    
    vector<Studentas> studentas;

    int n, m; // n - pazymiu skaicius
              // m - studentu skaicius
    
    m = 2; n = 3;

    
    Studentas laikinas;
    for(int i=0; i < m; i++){

        laikinas.pazymiai.clear();
        float sum = 0;
        
        // cout << "Vardas: ";   cin >> laikinas.vardas;
        // cout << "Pavarde: ";  cin >> laikinas.pavarde;

//------------------------------- Pazymiu ivedimas --------------------------------------------------------------------------------------------
        float ivertinimas;
        for(int j=0; j < n; j++){
            cout << j+1 << " pazymys: "; cin >> ivertinimas;
            laikinas.pazymiai.push_back(ivertinimas);
       }

//------------------------------- Vidurkio skaiciavimas ----------------------------------------------------------------------------------------
       for(auto s : laikinas.pazymiai){
         sum += s;
       } 
       float vidurkis; //Pazymiu vidurkis
       vidurkis = sum/n;

    return 0;
}
