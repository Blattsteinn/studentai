#include "mano_lib.h"

float average(Studentas laikinas){
    float sum = 0;
    float vidurkis = 0;

    if(laikinas.pazymiai.size() != 0 ){ // Jei yra bent vienas ivertinimas apskaiciuojamas vidurki 
        for(auto s : laikinas.pazymiai){
            sum += s;
        }   
        vidurkis = sum/laikinas.pazymiai.size();
        return vidurkis;
    }
    else { 
        cout << "[Pazymiu nera] namu darbu tarpiniai rezultatai = 0" << endl; 
        return 0;   
    }
    
}

float median(Studentas laikinas){

    float mediana = 0; 
        
    if(laikinas.pazymiai.size() != 0 ){ // Jei yra bent vienas ivertinimas apskaiciuojama mediana
        
            sort(laikinas.pazymiai.begin(), laikinas.pazymiai.end()); // Duomenu issirikiavimas didejimo tvarka
            int pazymiu_kiekis = laikinas.pazymiai.size();

            if(pazymiu_kiekis % 2 == 1){ // Jeigu pazymiu skaicius yra nelyginis
                mediana = laikinas.pazymiai[pazymiu_kiekis / 2];
                return mediana;
            } 

            else{ // Jeigu pazymiu skaicius yra lyginis
                mediana = (laikinas.pazymiai[pazymiu_kiekis/2] + laikinas.pazymiai[pazymiu_kiekis/2 - 1 ]) / 2.0;}
                return mediana;
            } 

    else { 
        return 0;   
    }
}
