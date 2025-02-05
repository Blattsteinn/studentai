#include "mano_lib.h"

struct Studentas{

    string vardas = "A"; //Laikinas
    string pavarde = "B";

    vector<float> pazymiai;
    int egzaminoRezultatas;

    float galutinisVid;
    float galutinisMed;
};

int main(){

    vector<Studentas> studentas;

    Studentas laikinas;
    while(true){ 

        laikinas.pazymiai.clear();
        float sum = 0;
        
        // cout << "Vardas: ";   cin >> laikinas.vardas;
        // cout << "Pavarde: ";  cin >> laikinas.pavarde;

//------------------------------- Pazymiu ivedimas --------------------------------------------------------------------------------------------
        float ivertinimas;
        int j = 0;
        cout << "Pazymiu ivedimas... -1 - norint nutraukti" << endl;
        while(true){
            cout << j+1 << " pazymys: "; cin >> ivertinimas; j++;
            if(ivertinimas == -1){ break; }
            laikinas.pazymiai.push_back(ivertinimas);
        

       }

//------------------------------- Vidurkio skaiciavimas ----------------------------------------------------------------------------------------
       for(auto s : laikinas.pazymiai){
         sum += s;
       } 
       float vidurkis; //Pazymiu vidurkis
       vidurkis = sum/laikinas.pazymiai.size();

//------------------------------- Rikiavimas nuo maziausio iki didziausio ir medianos skaiciavimas ----------------------------------------------
        sort(laikinas.pazymiai.begin(), laikinas.pazymiai.end());

        float mediana;
        int pazymiu_kiekis = laikinas.pazymiai.size();
        if(pazymiu_kiekis % 2 == 1){ //Jei skaicius nelyginis
            mediana = laikinas.pazymiai[pazymiu_kiekis / 2];//Pradedama nuo 0 skaiciuoti
        } 

        else{
            mediana = (laikinas.pazymiai[pazymiu_kiekis/2] + laikinas.pazymiai[pazymiu_kiekis/2 - 1 ]) / 2.0;
        }

//-----------------------------------------------------------------------------------------------------------------------------------------------
        cout << "Egzamino rezultatas: "; cin >> laikinas.egzaminoRezultatas;

        laikinas.galutinisVid = vidurkis * 0.4 + laikinas.egzaminoRezultatas *0.6;
        laikinas.galutinisMed = mediana * 0.4 + laikinas.egzaminoRezultatas *0.6;

        studentas.push_back(laikinas);
        char choice;
        cout << "Ivestini kita studenta? y/n "; cin >>  choice;
        if(choice == 'n'){ break; }
    }

    //---------------------
    //Spausdinimas

    cout << left << setw(12) << "Pavarde" 
        << setw(12) << "Vardas" 
        << setw(15) << "Galutinis (Vid.)  /  " 
        << setw(15) << "Galutinis (Med.)" 
        << "\n-------------------------------------------------\n";

    for (auto& s : studentas) {
        cout << left << setw(12) << s.pavarde
            << setw(12) << s.vardas
            << fixed << setprecision(2) << setw(22) << s.galutinisVid
            << fixed << setprecision(2) << setw(15) << s.galutinisMed
            << "\n";
    }
    return 0;
}
