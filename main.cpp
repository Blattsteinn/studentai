#include "mano_lib.h"

struct Studentas{

    string vardas = "A"; //Laikinas
    string pavarde = "B";

    vector<float> pazymiai;
    int egzaminoRezultatas;

    float galutinisVid;
    float galutinisMed;
};

int randomNumber() {
    std::random_device rd;  //Seed
    std::mt19937 gen(rd()); //Mersenne Twister engine
    std::uniform_int_distribution<int> distr(0, 10);
    
    return distr(gen);
}

int main(){

    vector<Studentas> studentas;

    Studentas laikinas;
    while(true){ 

        laikinas.pazymiai.clear();
        float sum = 0;
        
        // cout << "Vardas: ";   cin >> laikinas.vardas;
        // cout << "Pavarde: ";  cin >> laikinas.pavarde;

                            // --- Pazymiu ivedimas --- 
        float ivertinimas;
        int j = 0;  // Seka ivestu pazymiu skaiciu
        cout << "Pazymiu ivedimas... -1 - norint nutraukti" << endl;
        while(true){
            cout << j+1 << " pazymys: "; cin >> ivertinimas; 

            ivertinimas = randomNumber(); cout << ivertinimas << endl; cin >> a;

            if(a == -1){ break; }  //nutraukimas
            else if (ivertinimas < 0 || ivertinimas > 10){ cout << "Ivertinimo ribos nuo 1 iki 10" << endl; continue; } // Salygos netenkinimas
            else{ 
                j++;
                laikinas.pazymiai.push_back(ivertinimas);
            }
       }

        // --- Vidurkio ir medianos skaiciavimas  --- 
        float vidurkis = 0;
        float mediana = 0; 
        
        if(laikinas.pazymiai.size() != 0 ){ // Jei yra bent vienas ivertinimas apskaiciuoja mediana/vidurki 
            for(auto s : laikinas.pazymiai){
                sum += s;
            }   
            vidurkis = sum/laikinas.pazymiai.size();

            sort(laikinas.pazymiai.begin(), laikinas.pazymiai.end()); // Duomenu issirikiavimas didejimo tvarka

            int pazymiu_kiekis = laikinas.pazymiai.size();
            if(pazymiu_kiekis % 2 == 1){ // Jei skaicius nelyginis
                mediana = laikinas.pazymiai[pazymiu_kiekis / 2];//Pradedama nuo 0 skaiciuoti
                } 

            else{ mediana = (laikinas.pazymiai[pazymiu_kiekis/2] + laikinas.pazymiai[pazymiu_kiekis/2 - 1 ]) / 2.0;} // Jei skaicius lyginis
            } 
        else { cout << "Pazymiu nera... " << endl;}

        cout << "Egzamino rezultatas: "; cin >> laikinas.egzaminoRezultatas;

        laikinas.galutinisVid = vidurkis * 0.4 + laikinas.egzaminoRezultatas *0.6;
        laikinas.galutinisMed = mediana * 0.4 + laikinas.egzaminoRezultatas *0.6;

        studentas.push_back(laikinas);
        char choice;
        cout << "Ivestini kita studenta? y/n "; cin >>  choice;
        if(choice == 'n'){ break; }
    }

    // --- Spausdinimas --- 
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