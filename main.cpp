#include "mano_lib.h"


int randomNumber(int a, int b) {
    static std::mt19937 gen{std::random_device{}()}; // paleidziama tik karta
    std::uniform_int_distribution<int> distr(a, b);
    return distr(gen);
}

vector<float> atsitiktinisPazymiai(){
    Studentas laikinas;

    char testiGeneravima;
    int pazymiuSekimas = 1;  //Seka kiek vartotojas ivede pazymiu

    while(true){
        cout << "Generuoti pazymi? y/n: "; cin >> testiGeneravima;
        if(testiGeneravima != 'n' && testiGeneravima != 'N'){ 
            int atsitiktinisPazymys = randomNumber(1, 10);
            laikinas.pazymiai.push_back(atsitiktinisPazymys);
            cout << pazymiuSekimas << "pazymys: "  << atsitiktinisPazymys << endl; pazymiuSekimas++;
            }
        else{
            break; 
        }               
    }

    return laikinas.pazymiai;
}

string atsitiktinisVardas() {
    vector<string> vardai = {"John", "Alice", "Michael", "Emily", "David", "Sophia"};

    return vardai[randomNumber(0, vardai.size()-1)];
}

string atsitiktinePavarde() {
    vector<string> pavardes = {"Smith", "Johnson", "Brown", "Williams", "Jones", "Miller"};

    return pavardes[randomNumber(0, pavardes.size()-1)];
}

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

vector<float> ivestiPazymius(){
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

        pasirinkimas = reiksmesTikrinimas(pradzios_tekstas, "[Klaida] iveskite skaiciu nuo 1-10", 1, 4);

        laikinas.pazymiai.clear();

        if(pasirinkimas == 5) { break; } // Nutraukiamas programos darbas
        switch(pasirinkimas){
            case 1:   // 1 - ivedimas rankas
                cout << "Vardas: ";   cin >> laikinas.vardas;
                cout << "Pavarde: ";  cin >> laikinas.pavarde;

                    // --- Rankinis pazymiu ivedimas --- 
                laikinas.pazymiai = ivestiPazymius();
                laikinas.egzaminoRezultatas = reiksmesTikrinimas("Egzamino ivertinimas: ", "[Klaida] iveskite skaiciu nuo 1-10", 1, 10);
                break;

            case 2:   // 2 - atsitiktinis pazymiu generavimas
                cout << "Vardas: ";   cin >> laikinas.vardas;
                cout << "Pavarde: ";  cin >> laikinas.pavarde;

                    // --- Atsitiktinis pazymiu ivedimas --- 
                laikinas.pazymiai = atsitiktinisPazymiai();
                laikinas.egzaminoRezultatas = randomNumber(1, 10); cout << "Egzamino rezultatas: " << laikinas.egzaminoRezultatas << endl;
                break;

            case 3:   // 3 - generuoti ir pazymius ir studentu vardus, pavardes
                laikinas.vardas = atsitiktinisVardas();  cout << "Sugeneruotas vardas: " << laikinas.vardas << endl;
                laikinas.pavarde = atsitiktinePavarde(); cout << "Sugeneruota pavarde: " << laikinas.pavarde << endl;
                laikinas.pazymiai = atsitiktinisPazymiai();
                laikinas.egzaminoRezultatas = randomNumber(1, 10); cout << "Egzamino rezultatas: " << laikinas.egzaminoRezultatas << endl;
                break;

            case 4:
                cout << "[Skaitymas is failo] ";

            default:
                // programa neturetu pasiekti sios dalies
            break;
        }


        // --- Vidurkio ir medianos skaiciavimas  --- 
        float sum = 0;
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

        laikinas.galutinisVid = vidurkis * 0.4 + laikinas.egzaminoRezultatas *0.6;
        laikinas.galutinisMed = mediana * 0.4 + laikinas.egzaminoRezultatas *0.6;

        studentas.push_back(laikinas);

        char choice;
        cout << "Ivestini kita studenta? y/n: "; cin >>  choice;
        if(choice == 'n' || choice == 'N'){ break; }
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