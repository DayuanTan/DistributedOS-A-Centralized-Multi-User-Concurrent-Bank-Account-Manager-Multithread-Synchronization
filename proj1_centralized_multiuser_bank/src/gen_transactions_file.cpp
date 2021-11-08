#include <iostream>
#include <fstream>
using namespace std;

int main () {
    ofstream myfile;
    myfile.open ("Transactions.txt");

    for (float i = 0; i < 10000; i++){
        float timestamp = 5 + i/100;
        string type = "d";
        if (int(i) % 2 == 0){ type = "w"; }
        string aline = std::to_string(timestamp) + " 101 " + type + " " + std::to_string(1); 
        myfile << aline << endl;
    }

    
    myfile.close();
    return 0;
}