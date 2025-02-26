#include "mano_lib.h"

float average(Studentas temp){
    float sum = 0;
    float vidurkis = 0;

    if(temp.pazymiai.size() == 0 ) {
        cout << "[Klaida] Negalima apskaiciuoti vidurkio, nes nera ivertinimu. Vidurkis - 0" << endl;
        return 0;
    }

    for(auto s : temp.pazymiai){
        sum += s;
    }   

    vidurkis = sum/temp.pazymiai.size();
    return vidurkis;

}

float median(Studentas temp){

    float mediana = 0; 
    if (temp.pazymiai.empty()) {
        cout << "[Klaida] Negalima apskaiciuoti vidurkio, nes nera ivertinimu. Mediana - 0" << endl;
        return 0;
    }

    sort(temp.pazymiai.begin(), temp.pazymiai.end()); // Duomenu issirikiavimas didejimo tvarka
    int pazymiu_kiekis = temp.pazymiai.size();

    if(pazymiu_kiekis % 2 == 1){ // Jeigu pazymiu skaicius yra nelyginis
        mediana = temp.pazymiai[pazymiu_kiekis / 2];
        return mediana;
    } 

    else{ // Jeigu pazymiu skaicius yra lyginis
        mediana = (temp.pazymiai[pazymiu_kiekis/2] + temp.pazymiai[pazymiu_kiekis/2 - 1 ]) / 2.0;
        return mediana;
    }
}

void calculate_everything(Studentas &temp){

    temp.galutinisVid = average(temp) * 0.4 + temp.egzaminoRezultatas *0.6;
    temp.galutinisMed = median(temp) * 0.4 + temp.egzaminoRezultatas *0.6;

}