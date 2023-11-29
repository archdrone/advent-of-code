#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() {
    fstream new_file;
  
    // open a file to perform read operation using file object.
    new_file.open("input.txt", ios::in);

    // Checking whether the file is open.
    if (new_file.is_open()) {
        string sa;

        int max[3];
        for (int i = 0; i < 3; i++) {
            max[i] = 0;
        }
        int current = 0;

        // Read data from the file object and put it into a string.
        while (getline(new_file, sa)) {
            // Print the data of the string.

            if (sa.compare("") == 0) {
                cout << ">>LINEBREAK" << std::endl;
                int spot = -1;
                for (int i = 0; i < 3; i++) {
                    if (max[i] < current && (spot == -1 || max[i] <= max[spot])) {
                        spot = i;
                    }
                }
                if (spot != -1) {
                    max[spot] = current;
                }
                current = 0;
            }
            else {
                int currCalorie = stoi(sa);
                current += currCalorie;
            }
        }

        int total = 0;
        for (int i = 0; i < 3; i++) {
            cout << "MAX:" << i << ":" << max[i] << std::endl;
            total += max[i];
        }
        cout << "TOTAL:" << total << std::endl;

        // Close the file object.
        new_file.close();
    }
}