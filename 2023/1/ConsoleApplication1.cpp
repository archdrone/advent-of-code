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

        int total = 0;

        // Read data from the file object and put it into a string.
        while (getline(new_file, sa)) {

            int first = -1;
            int last = -1;

            for (int i = 0; i < sa.length(); i++) {

                char curr = sa[i];

                int digit = -1;

                if (curr >= '0' && curr <= '9') {
                    digit = curr - '0';

                } else if (curr == 'o') {

                    if (sa.length() - i > 2 && sa[i+1] == 'n' && sa[i+2] == 'e') {
                        digit = 1;
                    }

                }
                else if (curr == 't') {

                    int currLength = sa.length() - i;

                    if (currLength > 2 && sa[i + 1] == 'w' && sa[i + 2] == 'o') {
                        digit = 2;
                    }
                    else if (currLength > 4 && sa[i + 1] == 'h' && sa[i + 2] == 'r' && sa[i + 3] == 'e' && sa[i + 4] == 'e') {
                        digit = 3;
                    }


                }
                else if (curr == 'f') {
                    int currLength = sa.length() - i;

                    if (currLength > 3 && sa[i + 1] == 'o' && sa[i + 2] == 'u' && sa[i+3] == 'r') {
                        digit = 4;
                    } else  if (currLength > 3 && sa[i + 1] == 'i' && sa[i + 2] == 'v' && sa[i + 3] == 'e') {
                        digit = 5;
                    }

                }
                else if (curr == 's') {
                    int currLength = sa.length() - i;

                    if (currLength > 2 && sa[i + 1] == 'i' && sa[i + 2] == 'x' ) {
                        digit = 6;
                    }
                    else  if (currLength > 4 && sa[i + 1] == 'e' && sa[i + 2] == 'v' && sa[i + 3] == 'e' && sa[i+4] == 'n') {
                        digit = 7;
                    }
                }
                else if (curr == 'e') {
                    int currLength = sa.length() - i;

                    if (currLength > 4 && sa[i + 1] == 'i' && sa[i + 2] == 'g' && sa[i + 3] == 'h' && sa[i + 4] == 't') {
                        digit = 8;
                    }

                }
                else if (curr == 'n') {
                    int currLength = sa.length() - i;
                    if (currLength > 3 && sa[i + 1] == 'i' && sa[i + 2] == 'n' && sa[i + 3] == 'e') {
                        digit = 9;
                    }
                }



                if(digit != -1) {
                    if (first == -1) {
                        last = first = digit;
                    }

                    else {
                        last = digit;
                    }
                } 
            }


            cout << sa << ":" << first << ":" << last << std::endl;
               

            total += (first*10) + last;
            


        }

        
        cout << "TOTAL:" << total << std::endl;

        // Close the file object.
        new_file.close();
    }
}