#include <string>
#include <iostream>
#include <fstream>
using namespace std;



int main(){
    string f1_name = "f1.txt";
    string f2_name = "f2.txt";

    ifstream f1(f1_name);
    ofstream f2(f2_name);
    string buff;

    while(getline(f1, buff)){
        if (buff.find(" ") == -1) {
            f2 << buff << endl;
        }
    }

    cout << "Строки скопированы" << endl;
    f1.close();
    f2.close();

    ifstream f2_read(f2_name);
    string max_string;
    while(getline(f2_read, buff)){
        if (buff.size() > max_string.size())
            max_string = buff;
    }

    cout << "Самая длинная строка: " << max_string;


    return 0;
}
