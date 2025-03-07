#include "mano_lib.h"
#include "my_functions.h"

float average(Studentas temp){
    float sum = 0;
    float vidurkis = 0;

    if(temp.pazymiai.size() == 0 ) {
        cout << "[Klaida] Negalima apskaiciuoti vidurkio, nes nera ivertinimu. Vidurkis - 0" << endl;
        return 0;
    }

    sum = accumulate(temp.pazymiai.begin(), temp.pazymiai.end(), 0);

    vidurkis = sum/temp.pazymiai.size();
    return vidurkis;

}

void calculate_everything(Studentas &temp){
    temp.galutinisVid = average(temp) * 0.4 + temp.egzaminoRezultatas *0.6;
    temp.galutinisMed = median<StudentContainer>(temp) * 0.4 + temp.egzaminoRezultatas *0.6;

}

int check_the_value(string message, string errorMessage,int minVal,int maxVal){
    while (true)
    {
        cout << message;
        int value; 
        if (!(cin >> value)){  // <-- if cin fails
            cout << errorMessage << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;  // <-- prompt back again
        }

        if (value < minVal || value > maxVal){  // <-- if the number is not within the given range 
            cout << errorMessage << endl;
            continue;  // <-- prompt back again
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return value;
    }
}

string getPradziosTekstas() {
    return R"(
        [Programos eigos pasirinkimas]
        
1 - rankinis ivedimas, 
2 - generuoti pazymius, 
3 - generuoti ir pazymius, ir studentu vardus, pavardes, 
4 - nuskaityti duomenis is failo, 
5 - baigti darba

            [Pasirinkimas]: )";
}


void generate_files(int student_size) { // size = 10^student_size

    auto start = std::chrono::high_resolution_clock::now();

    int size = pow(10, student_size);
    string file_name = "testavimasFailas" + std::to_string(size) + ".txt";
    std::ofstream output(file_name);

    int nd_to_generate = 5;

    std::ostringstream buffer;
    buffer << std::left << std::setw(25) << "Vardas"
        << std::left << std::setw(27) << "Pavarde";

    for (int i = 1; i <= nd_to_generate; i++) {
        buffer << std::left << std::setw(10) << ("ND" + std::to_string(i));
    } buffer << '\n';

    for(int i = 1; i <= size; i++){
        string vardas = "VardasNr" + std::to_string(i);;
        string pavarde = "PavardeNr" + std::to_string(i);

        buffer << std::left << std::setw(25) << vardas
                  << std::left << std::setw(27) << pavarde;
                  
        for (int j = 0; j < nd_to_generate; j++) {
            buffer << std::left << std::setw(10) << randomNumber(1, 10);
        } buffer << '\n';
    }


    output << buffer.str();
    output.close();

    // ----
        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> reading_duration = end - start;
        cout << "Sukurtas " << file_name << " failas." << endl;
        std::cout << "Faila sukurti uztruko: " << reading_duration.count() << "s" << std::endl;
        cout << endl;
    // ----
}

int randomNumber(int a, int b) {
    static std::mt19937 gen{std::random_device{}()}; // paleidziama tik karta
    std::uniform_int_distribution<int> distr(a, b);
    return distr(gen);
}
