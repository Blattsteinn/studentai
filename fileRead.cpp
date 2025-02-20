#include "mano_lib.h"

// --- Reads the entire file into a string  ---
string readFileToString(){
        // Open file in binary mode and position at the end to determine its size.
        ifstream file("kursiokai.txt", std::ios::binary | std::ios::ate);
        if (!file) {
            cerr << "Error: Could not open file.\n";
            return "[ERROR]";
        }
    
        // Determine the file size.
        std::streamsize size = file.tellg();
        
        // Move the file pointer back to the beginning.
        file.seekg(0, std::ios::beg);
    
        // Read the entire file into a buffer.
        vector<char> bufferis(size);
        if (!file.read(bufferis.data(), size)) {
            cerr << "[ERROR]: Could not read file.\n";
            return "[ERROR]";
        }
        
        // Convert the buffer into a string for easier parsing.
        string content(bufferis.begin(), bufferis.end());
        return content;
} 

// --- Counts the number of ND (NDn)  ---
int wordCount(istringstream& iss){

    // Read the header line
    string header;
    std::getline(iss, header);
    
    // Splits the header into words
    istringstream headerStream(header); 

    vector<string> wordVector;
    string word;

    while (headerStream >> word) {
        wordVector.push_back(word);
    }
    
    // Ensure that the header has at least three words (name, lastName & exam score)
    if (wordVector.size() < 3) {
        cerr << "[ERROR]: Invalid file header.\n";
        return -1;
    }

    // ND count is total number of words minus 3 (name, lastName & exam score)

    int ndCount = wordVector.size() - 3;
    // cout << "Determined ND count from header: " << ndCount << "\n";  // <-- Testing

    return ndCount;
}

/* --- Reads student records  ---   
                              ndCount - instances of NDn in the file; &iss - stream of the file.
                              Skips processing further records if any record is malformed.
                              Returns a vector of Studentas objects */
vector<Studentas> read_student_records(int ndCount, istringstream& iss){

        
        vector<Studentas> records;
        while (true) {
            Studentas r;
            if (!(iss >> r.vardas >> r.pavarde))
                break;  // End of file or read error.
    
            // Resizes the 'vector<float> pazymiai' to the expected number of values.
            r.pazymiai.resize(ndCount);
    
            bool success = true;
            for (int i = 0; i < ndCount; i++) {
                if (!(iss >> r.pazymiai[i])) {
                    success = false;
                    break;
                }
            }
            if (!success)
                break;
            
            // Exam score.
            if (!(iss >> r.egzaminoRezultatas))
                break;
            
            // Add the record to the vector.
            records.push_back(r);
        }
        //Returns all the students & their information
        return records; 
}