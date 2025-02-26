#include "mano_lib.h"

int randomNumber(int a, int b) {
    static std::mt19937 gen{std::random_device{}()}; // paleidziama tik karta
    std::uniform_int_distribution<int> distr(a, b);
    return distr(gen);
}

// Generates random grades
vector<float> random_grade(){
    Studentas temp;

    int amount_to_generate = randomNumber(2,8);  // Generates a random number to determine how many grades the student will have
    for(int i = 0; i< amount_to_generate; i++){
        int random_generated_grade = randomNumber(1, 10);   // Generates a grade
        temp.pazymiai.push_back(random_generated_grade);
    }

    return temp.pazymiai;
}

string random_name() {
    vector<string> vardai = {"John", "Alice", "Michael", "Emily", "David", "Sophia"};

    return vardai[randomNumber(0, vardai.size()-1)];
}

string random_last_name() {
    vector<string> pavardes = {"Smith", "Johnson", "Brown", "Williams", "Jones", "Miller"};

    return pavardes[randomNumber(0, pavardes.size()-1)];
}

