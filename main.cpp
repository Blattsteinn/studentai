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

vector<float> ivestiPazymius(){
    Studentas laikinas;

    float ivertinimas;
    int j = 0;  // Seka ivestu pazymiu skaiciu
    cout << "Pazymiu ivedimas... -1 - norint nutraukti" << endl;
        while(true){
            cout << j+1 << " pazymys: "; cin >> ivertinimas; 

            if(ivertinimas == -1){ break; }  //nutraukimas
            else if (ivertinimas < 0 || ivertinimas > 10){ cout << "!! Ivertinimo ribos nuo 1 iki 10" << endl; continue; } // Salygos netenkinimas
            else{ 
                j++;
                laikinas.pazymiai.push_back(ivertinimas);
            }
       }

    return laikinas.pazymiai;
}

vector<float> atsitiktinisPazymiai(){
    Studentas laikinas;

    char testiGeneravima;
    int pazymiuSekimas = 1;  //Seka kiek vartotojas ivede pazymiu

    while(true){
        cout << "Generuoti pazymi? y/n: "; cin >> testiGeneravima;
        if(testiGeneravima != 'n'){ 
            int atsitiktinisPazymys = randomNumber();
            laikinas.pazymiai.push_back(atsitiktinisPazymys);
            cout << pazymiuSekimas << " pazymys: "  << atsitiktinisPazymys << endl; pazymiuSekimas++;
            }
        else{
            break; 
        }               
    }

    return laikinas.pazymiai;
}

int main(){

    vector<Studentas> studentas;

    Studentas laikinas;

    int pasirinkimas;
    bool programa;
    while(programa){ 
        
        cout << "Programos eigos pasirinkimas (1 - ranka, 2 - generuoti pazymius, 3 - generuoti ir pazymius ir studentu vardus, pavardes, 4 - baigti darba): ";
        cin >> pasirinkimas;

        laikinas.pazymiai.clear();
        float sum = 0;
        int pazymiuSekimas = 0;

        switch(pasirinkimas){
            case 1:   // 1 - ivedimas rankas
                //cout << "Vardas: ";   cin >> laikinas.vardas;
                //cout << "Pavarde: ";  cin >> laikinas.pavarde;

                    // --- Rankinis pazymiu ivedimas --- 
                laikinas.pazymiai = ivestiPazymius();
                break;

            case 2:   // 2 - atsitiktinis pazymiu generavimas
                //cout << "Vardas: ";   cin >> laikinas.vardas;
                //cout << "Pavarde: ";  cin >> laikinas.pavarde;

                    // --- Atsitiktinis pazymiu ivedimas --- 
                laikinas.pazymiai = atsitiktinisPazymiai();
                break;

            case 3:   // 3 - generuoti ir pazymius ir studentu vardus, pavardes


                laikinas.pazymiai = atsitiktinisPazymiai();
                break;

            case 4:
                programa = false; // Nutraukiamas programos darbas
                break;

            default:
                cout << "Neteisingas pasirinkimas.. " << endl;
                cout << "Programos eigos pasirinkimas (1 - ranka, 2 - generuoti pazymius, 3 - generuoti ir pazymius ir studentu vardus, pavardes, 4 - baigti darba): ";
                cin >> pasirinkimas;
            break;
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
        else { cout << "Pazymiu nera... namu darbu tarpiniai rezultatai = 0" << endl;}

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