#include "mano_lib.h"

float average(Studentas laikinas){
    float sum = 0;
    float vidurkis = 0;

    if(laikinas.pazymiai.size() == 0 ) {
        throw std::runtime_error("[Klaida] pazymiu nera, tarpiniai rezultatai - 0.");
    }

    for(auto s : laikinas.pazymiai){
        sum += s;
    }   

    vidurkis = sum/laikinas.pazymiai.size();
    return vidurkis;

}

float median(Studentas laikinas){

    float mediana = 0; 
    if (laikinas.pazymiai.empty()) {
        throw std::runtime_error("[Klaida] Negalima apskaiciuoti medianos, nera pazymiu.");
    }

    sort(laikinas.pazymiai.begin(), laikinas.pazymiai.end()); // Duomenu issirikiavimas didejimo tvarka
    int pazymiu_kiekis = laikinas.pazymiai.size();

    if(pazymiu_kiekis % 2 == 1){ // Jeigu pazymiu skaicius yra nelyginis
        mediana = laikinas.pazymiai[pazymiu_kiekis / 2];
        return mediana;
    } 

    else{ // Jeigu pazymiu skaicius yra lyginis
        mediana = (laikinas.pazymiai[pazymiu_kiekis/2] + laikinas.pazymiai[pazymiu_kiekis/2 - 1 ]) / 2.0;
        return mediana;
    }
}
