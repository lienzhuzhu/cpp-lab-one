// lien-lab1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include "enums.h"

using namespace std;

int parse_file(vector<string>&, char*);
int how_to_use(char*);

int main(int argc, char* argv[])
{
    if (argc != 2) {
        return how_to_use(argv[prog_name]);
    }

    vector<string> v;

    int file_open = parse_file(v, argv[input_file_name]);
    
    if (file_open != success) {
        return file_open;
    }

    vector<int> num_vector;
    
    for (size_t s = 0; s < v.size(); ++s) {
        string word = v[s];

        int i = 0;
        bool not_int = false;                                  
        while (i < word.length()) {
            if (!isdigit(word[i]) && word[i] != '-') { // considers ints with minus sign in front as negative int
                not_int = true;
            }
            ++i;
        }

        if (not_int) {
            cout << word << endl;
        }
        else {
            int nums;
            istringstream iss(word);
            iss >> nums;
            num_vector.push_back(nums);
        }
    }

    for (size_t c = 0; c < num_vector.size(); ++c) {
        cout << num_vector[c] << endl;
    }

    return success;
}


int parse_file(vector<string>& v_ref, char* f) {
                                                
    ifstream ifs(f);
    
    if (ifs.is_open()) {
        
        string w;
        ifs >> w;
        
        while (ifs) {
            v_ref.push_back(w);
            ifs >> w;
        }

    }
    else {
        return file_could_not_be_opened;    // echo 1
    }

    ifs.close();
    return success;
}

int how_to_use(char* program_name) {
    cout << "usage: " << program_name << " " << "<input_file.txt>" << endl;
    return wrong_number_of_arguments;       // echo 2
}


