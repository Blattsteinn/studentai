#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <random>
#include <limits> // for std::numeric_limits
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::sort;

using std::left;
using std::setw;
using std::fixed;
using std::setprecision;
using std::numeric_limits;
using std::streamsize;

struct PazymiuStruk{
    float* ivertinimai;
    int size;
};

struct Studentas{

    string vardas;
    string pavarde;

    PazymiuStruk pazymiai;
    int egzaminoRezultatas;

    float galutinisVid;
    float galutinisMed;
};

int randomNumber(int a, int b) {
    static std::mt19937 gen{std::random_device{}()}; // paleidziama tik karta
    std::uniform_int_distribution<int> distr(a, b);
    return distr(gen);
}

PazymiuStruk atsitiktinisPazymiai(){
    PazymiuStruk d;
    d.ivertinimai = nullptr;
    d.size = 0;
    char testiGeneravima;
    int pazymiuSekimas = 1;  //Seka kiek vartotojas ivede pazymiu

    while(true){
        cout << "Generuoti pazymi? y/n: "; cin >> testiGeneravima;
        if(testiGeneravima != 'n' && testiGeneravima != 'N'){
            int atsitiktinisPazymys = randomNumber(1, 10);
            float* newIvertinimai = new float[d.size + 1];
            for(int i = 0; i < d.size; i++){
                newIvertinimai[i] = d.ivertinimai[i];
            }
            newIvertinimai[d.size] = atsitiktinisPazymys;
            delete[] d.ivertinimai;
            d.ivertinimai = newIvertinimai;
            d.size++;
            cout << pazymiuSekimas << " pazymys: "  << atsitiktinisPazymys << endl; pazymiuSekimas++;
            }
        else{
            break;
        }               
    }

    return d;
}

string atsitiktinisVardas() {
    string vardai[] = {"John", "Alice", "Michael", "Emily", "David", "Sophia"};
    int size = sizeof(vardai) / sizeof(vardai[0]);

    return vardai[randomNumber(0, size - 1)];
}

string atsitiktinePavarde() {
    string pavardes[] = {"Smith", "Johnson", "Brown", "Williams", "Jones", "Miller"};
    int size = sizeof(pavardes) / sizeof(pavardes[0]);

    return pavardes[randomNumber(0, size - 1)];
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

PazymiuStruk ivestiPazymius(){
    PazymiuStruk d;
    d.ivertinimai = nullptr;
    d.size = 0;
    int ivertinimas;
    int pazymiuSekimas = 1;  //Sekama kiek vartotojas ivede pazymiu

    cout << "[Pazymiu ivedimas] ivedant -1 nutraukiamas darbas" << endl;
        while(true){
            string tekstas = std::to_string(pazymiuSekimas) + " pazymys: ";
            
            ivertinimas = reiksmesTikrinimas(tekstas, "[Klaida] ivertinimo ribos nuo 1 iki 10", -1, 10);

            if(ivertinimas == -1){ break; }  //nutraukimas
            else if (ivertinimas == 0 ){ cout << "[Klaida] ivertinimo ribos nuo 1 iki 10" << endl; continue; }

            float* newIvertinimai = new float[d.size + 1];
            for (int i = 0; i < d.size; i++){
                newIvertinimai[i] = d.ivertinimai[i];
            }
            newIvertinimai[d.size] = ivertinimas;
            delete[] d.ivertinimai;
            d.ivertinimai = newIvertinimai;
            d.size++;
            pazymiuSekimas++;
            }

    return d;
}


int main(){

    Studentas* studentai = new Studentas[10];
    int studentCount = 0;
    int studentCapacity = 10;

    Studentas laikinas;
    laikinas.pazymiai.ivertinimai = nullptr;
    laikinas.pazymiai.size = 0;

    int pasirinkimas{};
    while(true){ 
        
        string pradzios_tekstas = "[Pasirinkimas] programos eiga (1 - ranka, 2 - generuoti pazymius, 3 - generuoti ir pazymius ir studentu vardus, pavardes, 4 - baigti darba): ";
        pasirinkimas = reiksmesTikrinimas(pradzios_tekstas, "[Klaida] iveskite skaiciu nuo 1-10", 1, 4);

        delete[] laikinas.pazymiai.ivertinimai;
        laikinas.pazymiai.ivertinimai = nullptr;
        laikinas.pazymiai.size = 0;

        if(pasirinkimas == 4) { break; } // Nutraukiamas programos darbas
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

            default:
                // programa neturetu pasiekti sios dalies
            break;
        }


        // --- Vidurkio ir medianos skaiciavimas  --- 
        float sum = 0;
        float vidurkis = 0;
        float mediana = 0; 
        
        if(laikinas.pazymiai.size != 0 ){ // Jei yra bent vienas ivertinimas apskaiciuoja mediana/vidurki 
            for(int i = 0; i < laikinas.pazymiai.size; i++){
                sum += laikinas.pazymiai.ivertinimai[i];
            }   
            vidurkis = sum/laikinas.pazymiai.size;

            sort(laikinas.pazymiai.ivertinimai, laikinas.pazymiai.ivertinimai + laikinas.pazymiai.size); // Duomenu issirikiavimas didejimo tvarka

            int pazymiu_kiekis = laikinas.pazymiai.size;
            if(pazymiu_kiekis % 2 == 1){ // Jei skaicius nelyginis
                mediana = laikinas.pazymiai.ivertinimai[pazymiu_kiekis / 2];//Pradedama nuo 0 skaiciuoti
                } 

            else{ mediana = (laikinas.pazymiai.ivertinimai[pazymiu_kiekis/2] + laikinas.pazymiai.ivertinimai[pazymiu_kiekis/2 - 1 ]) / 2.0;} // Jei skaicius lyginis
            } 
        else { cout << "Pazymiu nera... namu darbu tarpiniai rezultatai = 0" << endl;}

        laikinas.galutinisVid = vidurkis * 0.4 + laikinas.egzaminoRezultatas *0.6;
        laikinas.galutinisMed = mediana * 0.4 + laikinas.egzaminoRezultatas *0.6;

        if(studentCount == studentCapacity){
            Studentas* newStudents = new Studentas[studentCapacity * 2];
            for(int i = 0; i < studentCapacity; i++){
                newStudents[i] = studentai[i];
            }
            delete[] studentai;
            studentai = newStudents;
            studentCapacity *= 2;
        }
        studentai[studentCount] = laikinas;
        studentCount++;

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

    for (int i = 0; i < studentCount; i++) {
        cout << left << setw(12) << studentai[i].pavarde
            << setw(12) << studentai[i].vardas
            << fixed << setprecision(2) << setw(22) << studentai[i].galutinisVid
            << fixed << setprecision(2) << setw(15) << studentai[i].galutinisMed
            << "\n";
    }
    
    for (int i = 0; i < studentCount; i++){
        delete[] studentai[i].pazymiai.ivertinimai;
    }
    delete[] studentai;
    return 0;
}
